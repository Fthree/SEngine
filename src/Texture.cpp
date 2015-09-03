#include "Texture.h"

Texture::Texture()
:width(0), height(0), internalFormat(GL_RGB), imageFormat(GL_RGB), wrapS(GL_REPEAT), wrapT(GL_MIRRORED_REPEAT), filterMin(GL_MIRRORED_REPEAT), filterMax(GL_LINEAR)
{
	glGenTextures(1, &ID);
	isActive = false;
}

void Texture::load(GLuint w, GLuint h, unsigned char* data)
{
	width = w;
	height = h;

	glBindTexture(GL_TEXTURE_2D, ID);

	glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, imageFormat, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapS);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filterMin);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filterMax);

	glBindTexture(GL_TEXTURE_2D, 0);

	isActive = true;
}

void Texture::bind()
{ 
	glBindTexture(GL_TEXTURE_2D, ID); 
}

void Texture::unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
	isActive = false;
}