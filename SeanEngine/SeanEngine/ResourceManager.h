#ifndef __RESOURCEMAN__
#define __RESOURCEMAN__

#include <string>
#include <map>
#include <sstream>
#include <fstream>

#include <SOIL.h>
#include "Texture.h"
#include "Shader.h"

class ResourceManager
{
public:
	static std::map<std::string, Shader> shaders;
	static std::map<std::string, Texture> textures;

	static Shader loadShader(std::string vShader, std::string fShader, std::string name);
	static Texture loadTexture(std::string fileName, GLboolean alpha, std::string name); 

	static Texture &getTexture(std::string name) { return textures[name]; }
	static Shader &getShader(std::string name) { return shaders[name]; }
private:
	static Shader loadShaderFromFile(std::string vShader, std::string fShader);
	static Texture loadTextureFromFile(std::string fileName, GLboolean alpha);

	ResourceManager() {}
};

#endif