#ifndef __TEXTURE__
#define __TEXTURE__

#include <GL/glew.h>
#include <iostream>

class Texture
{
public:
	Texture();
	void load(GLuint w, GLuint h, unsigned char* data);
	void bind();
	void unbind();

	GLuint ID;
	GLuint width;
	GLuint height;

	GLuint internalFormat;
	GLuint imageFormat;

	GLuint wrapS;
	GLuint wrapT;
	GLuint filterMin;
	GLuint filterMax;

	bool isActive;
};

#endif