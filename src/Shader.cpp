#include "Shader.h"

void Shader::load(const GLchar* vert, const GLchar* frag)
{
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vert, NULL);
	glCompileShader(vertexShader);

	outputError(vertexShader, "VERTEX", GL_COMPILE_STATUS);

	GLuint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragmentShader, 1, &frag, NULL);
	glCompileShader(fragmentShader);

	outputError(fragmentShader, "FRAGMENT", GL_COMPILE_STATUS);

	ID = glCreateProgram();

	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);

	outputError(ID, "SHADER", GL_LINK_STATUS);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::outputError(GLuint type, std::string typeName, GLenum what)
{
	//Log output
	//Success 'boolean'
	//Info output
	//Get the shader information(shader ID, enum[what to get], boolean)

	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(type, what, &success);

	if (!success)
	{
		glGetShaderInfoLog(type, 512, NULL, infoLog);
		std::cout << "ERROR::" << typeName.c_str() << "::SHADER::FAILED\n" << infoLog << "\n";
		std::cout << "\n\n";
	}

	glViewport(0, 0, 800, 600);

}

//Shader type input
void Shader::setFloat(const GLchar* name, GLfloat value, GLboolean useShader)
{
	if (useShader)
	{
		use();
	}
	glUniform1f(glGetUniformLocation(ID, name), value);
}

void Shader::setInt(const GLchar* name, GLint value, GLboolean useShader)
{
	if (useShader)
	{
		use();
	}
	glUniform1i(glGetUniformLocation(ID, name), value);
}

void Shader::setVector2f(const GLchar* name, GLfloat x, GLfloat y, GLboolean useShader)
{
	if (useShader)
	{
		use();
	}
	glUniform2f(glGetUniformLocation(ID, name), x, y);
}

void Shader::setVector2f(const GLchar* name, const glm::vec2 &vec, GLboolean useShader)
{
	if (useShader)
	{
		use();
	}
	glUniform2f(glGetUniformLocation(ID, name), vec.x, vec.y); 
}

void Shader::setVector3f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader)
{
	if (useShader)
	{
		use();
	}
	glUniform3f(glGetUniformLocation(ID, name), x, y, z);
}

void Shader::setVector3f(const GLchar* name, const glm::vec3 &vec, GLboolean useShader)
{
	if (useShader)
	{
		use();
	}

	glUniform3f(glGetUniformLocation(ID, name), vec.x, vec.y, vec.z);
}

void Shader::setVector4f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader)
{
	if (useShader)
	{
		use();
	}

	glUniform4f(glGetUniformLocation(ID, name), x, y, z, w);
}

void Shader::setVector4f(const GLchar* name, const glm::vec4 &vec, GLboolean useShader)
{
	if (useShader)
	{
		use();
	}

	glUniform4f(glGetUniformLocation(ID, name), vec.x, vec.y, vec.z, vec.w);
}

void Shader::setMat4(const GLchar* name, const glm::mat4 &matrix, GLboolean useShader)
{
	if (useShader)
	{
		use();
	}

	glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(matrix));
}
