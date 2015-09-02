#include "ResourceManager.h"

std::map<std::string, Texture> ResourceManager::textures;
std::map<std::string, Shader> ResourceManager::shaders;

Shader ResourceManager::loadShader(std::string vShader, std::string fShader, std::string name)
{
	shaders[name] = loadShaderFromFile(vShader, fShader);
	return shaders[name];
}

Texture ResourceManager::loadTexture(std::string fileName, GLboolean alpha, std::string name)
{
	textures[name] = loadTextureFromFile(fileName, alpha);
	return textures[name];
}

Shader ResourceManager::loadShaderFromFile(std::string vShader, std::string fShader)
{
	// 1. Retrieve the vertex/fragment source code from filePath
	std::string vertexCode;
	std::string fragmentCode;

	// Open files
	

	std::ifstream vertexShaderFile(vShader);
	std::ifstream fragmentShaderFile(fShader);
	std::stringstream vShaderStream, fShaderStream;
	// Read file's buffer contents into streams
	vShaderStream << vertexShaderFile.rdbuf();
	fShaderStream << fragmentShaderFile.rdbuf();
	// close file handlers
	vertexShaderFile.close();
	fragmentShaderFile.close();
	// Convert stream into string
	vertexCode = vShaderStream.str();
	fragmentCode = fShaderStream.str();

	const GLchar *vShaderCode = vertexCode.c_str();
	const GLchar *fShaderCode = fragmentCode.c_str();
	// 2. Now create shader object from source code
	Shader shader;
	shader.load(vShaderCode, fShaderCode);
	return shader;
}

Texture ResourceManager::loadTextureFromFile(std::string fileName, GLboolean alpha)
{
	Texture retTex;

	if (alpha)
	{
		retTex.internalFormat = GL_RGBA;
		retTex.imageFormat = GL_RGBA;
	}
	
	int width;
	int height;

	unsigned char* image = SOIL_load_image(fileName.c_str(), &width, &height, 0, retTex.imageFormat == GL_RGBA ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);

	retTex.load(width, height, image);

	SOIL_free_image_data(image);
	return retTex;
}