#include "GFX.h"

graphics::graphics(Shader &shader)
{
	shader_ = shader;
	init();

	isTextureBinded = false;
}

void graphics::init()
{
	//Setup rect information
	{
		GLuint VBO;
		GLfloat vertices[] =
		{
			//Position  //Texture
			0.0f, 1.0f, 0.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,

			0.0f, 1.0f, 0.0f, 1.0f,
			1.0f, 1.0f, 1.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 0.0f
		};


		glGenVertexArrays(1, &quadVAO);
		glGenBuffers(1, &VBO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

		glBindVertexArray(quadVAO);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);
	}

	//Setup line information
	{
		GLuint VBO;
		GLfloat line_verts[] =
		{
			1.0f, 0.0f,
			0.0f, 1.0f
		};

		glGenVertexArrays(1, &lineVAO);
		glGenBuffers(1, &VBO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(line_verts), line_verts, GL_DYNAMIC_DRAW);

		glBindVertexArray(lineVAO);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat), (GLvoid*)0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);
	}
}

void graphics::drawSprite(Texture &texture, glm::vec2 position, glm::vec2 size, GLfloat rotate, glm::vec3 colour)
{
	shader_.use();

	//Do translation/rot/scaling ops on object. Do in reverse due to order of multiplication. Right to left
	glm::mat4 model;

	//Translate
	model = glm::translate(model, glm::vec3(position, 0.0f));
	
	//Rotate
	model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
	model = glm::rotate(model, rotate, glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

	//Scale
	model = glm::scale(model, glm::vec3(size, 1.0f));

	//Set varibales for shaders
	shader_.setMat4("model", model);
	shader_.setVector3f("spriteColour", colour);

	//Texturize
	glActiveTexture(GL_TEXTURE0);
	texture.bind();
	

	//Draw
	glBindVertexArray(quadVAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

void graphics::drawSprite(Texture &texture, b2Vec2 pos_, b2Vec2 size_, GLfloat rotate, glm::vec3 colour)
{
	glm::vec2 position(pos_.x - size_.x, pos_.y - size_.y);
	glm::vec2 size(size_.x * 2, size_.y * 2); //box2d works with half-widths. Double size

	/************************************************************************************/
	/********************************TRANSFORMATIONS*************************************/
	/************************************************************************************/
	glm::mat4 model;

	//Translate
	model = glm::translate(model, glm::vec3(glm::vec2(position.x, position.y), 0.0f));

	//Rotate
	model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
	model = glm::rotate(model, rotate, glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

	//Scale
	model = glm::scale(model, glm::vec3(size, 1.0f));

	//Send data
	shader_.use();
	shader_.setMat4("model", model);
	
	/************************************************************************************/
	/***********************************TEXTURES*****************************************/
	/************************************************************************************/

	if (texture.isActive)
	{
		shader_.setInt("loadImage", 1);
		shader_.setVector3f("spriteColour", glm::vec3(1.0f, 1.0f, 1.0f));
		glActiveTexture(GL_TEXTURE0);
		texture.bind();
	}
	else
	{
		shader_.setInt("loadImage", 0);
		shader_.setVector3f("spriteColour", colour);
		texture.unbind();
	}

	/************************************************************************************/
	/*************************************DRAW*******************************************/
	/************************************************************************************/

	glBindVertexArray(quadVAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

void graphics::drawLine(b2Vec2 start, b2Vec2 end, glm::vec3 colour)
{
	//Scaling: nX; 1/n(X)

	glm::vec2 A, B;
	A = glm::vec2(start.x, start.y);
	B = glm::vec2(end.x, end.y);

	glm::vec2 size((A.x - B.x), (A.y - B.y));

	shader_.use();

	//Do translation/rot/scaling ops on object. Do in reverse due to order of multiplication. Right to left
	glm::mat4 model;

	//Translate

	model = glm::translate(model, glm::vec3(B, 0.0f));

	double rot = atan2(size.y * 2, size.x * 2); //ANGLE
	model = glm::rotate(model, (GLfloat)rot, glm::vec3(0.0f, 0.0f, 1.0f));

	glm::vec2 scaleVal = glm::abs(size);

	GLfloat scl = glm::sqrt((size.x * size.x) + (size.y * size.y));

	model = glm::scale(model, glm::vec3(scl, scl, 1.0f));

	//Set varibales for shaders
	shader_.setMat4("model", model);
	shader_.setVector3f("spriteColour", colour);

	//Draw
	glBindVertexArray(lineVAO);
	glDrawArrays(GL_LINES, 0, 2);
	glBindVertexArray(0);
}