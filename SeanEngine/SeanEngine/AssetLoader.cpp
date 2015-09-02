#include "AssetLoader.h"

bool AssetLoader::load(std::string input)
{
	std::ifstream file(input);

	std::cout << input << "\n";

	if (!file)
	{
		return false;
	}

	toml::Parser parser(file);

	table = parser.parse();

	if (!table.valid())
	{
		std::cout << "::::::::FAILED LOADING TOML FILE::::::::\n" << input << "\nINVALID FILE\n";
		return false;
	}
}