#ifndef SHADER 
#define SHADER

#include <string>
#include <fstream>
#include <iostream>
#include "glm\glm.hpp"
#include "glm\gtc\type_ptr.hpp"

#define GLEW_STATIC
#include <GL\glew.h>

class Shader
{
public:
	Shader() {}
	void load(const GLchar* vert, const GLchar* frag);
	Shader &use() { glUseProgram(ID); return *this; }

	void setFloat	(const GLchar* name, GLfloat value, GLboolean useShader = false);
	void setInt		(const GLchar* name, GLint value, GLboolean useShader = false);
	void setVector2f(const GLchar* name, GLfloat x, GLfloat y, GLboolean useShader = false);
	void setVector2f(const GLchar* name, const glm::vec2 &vec, GLboolean useShader = false);
	void setVector3f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader = false);
	void setVector3f(const GLchar* name, const glm::vec3 &vec, GLboolean useShader = false);
	void setVector4f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader = false);
	void setVector4f(const GLchar* name, const glm::vec4 &vec, GLboolean useShader = false);
	void setMat4	(const GLchar* name, const glm::mat4 &matrix, GLboolean useShader = false);

	GLuint getID() { return ID; }

private:
	void getSource(std::string source, std::string &input);
	void outputError(GLuint type, std::string typeName, GLenum what);

	std::string vertShaderSource;
	std::string fragShaderSource;

	GLuint ID;
};

#endif