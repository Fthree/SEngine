#ifndef __GFX__
#define __GFX__

//Types
#include "GameData.h"
#include "Input.h"
#include <Box2D\Box2D.h>

//GLM
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"

//Internal
#include <vector>

//Graphical
#include <SOIL.h>
#include <SDL2\SDL.h>
#include "Shader.h"
#include "Texture.h"
#include <SDL2\SDL_opengl.h>
#include <gl\glu.h>
#include "ResourceManager.h"

class graphics
{
public:
	graphics() { }
	graphics(Shader &shader);
	~graphics() {}
	
	void drawSprite(Texture &texture, glm::vec2 position, glm::vec2 size, GLfloat rotate, glm::vec3 colour);
	void drawSprite(Texture &texture, b2Vec2 position, b2Vec2 size, GLfloat rotate, glm::vec3 colour);
	void drawLine(b2Vec2 start, b2Vec2 end, glm::vec3 colour);


private:

	Shader shader_;

	GLuint quadVAO;
	GLuint lineVAO;
	GLuint triangleVAO;
	
	void init();

	bool isTextureBinded;
};

#endif