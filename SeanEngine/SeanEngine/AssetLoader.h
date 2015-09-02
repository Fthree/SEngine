#ifndef TOML_LOADER_H
#define TOML_LOADER_H

#include "toml.h"
#include <string>
#include <iostream>
#include <fstream>

class AssetLoader
{
public:
	AssetLoader(){}

	bool load(std::string input);

	std::string get(std::string location) { return table.get<std::string>(location); }
private:

	toml::Value table;
};

#endif