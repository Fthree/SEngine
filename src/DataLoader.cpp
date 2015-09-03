#include "DataLoader.h"


DataLoader::DataLoader()
{
	
}


DataLoader::~DataLoader()
{
}

bool DataLoader::load(const char *DataPath, std::string whichGroup, std::string whichData)
{
	tinyxml2::XMLDocument Doc;

	if (Doc.LoadFile("assets/Assets.xml"))
	{
		//return false;
	}

	tinyxml2::XMLElement *DataType = Doc.FirstChildElement()->FirstChildElement();

	for (tinyxml2::XMLElement *Inner = DataType; DataType->Value() != whichGroup; Inner = Inner->NextSiblingElement())
	{
		DataType = Inner;
	}

	/*
	Pointer is now at <INNER1>
	*/

	//Go through list of Top level sprite holders
	for (tinyxml2::XMLElement *Chars = DataType->FirstChildElement(); Chars != nullptr; Chars = Chars->NextSiblingElement())
	{
		/*
		Pointer is now at <NAMEOFCHAR>
		*/

		//Check if the ID in XML is the same as the load ID provided, continue to next sibling otherwise
		if (Chars->Value() == whichData) 
		{
			//Go throught list of animations and put them into a structure
			for (tinyxml2::XMLElement *Anims = Chars->FirstChildElement(); Anims != nullptr; Anims = Anims->NextSiblingElement())
			{
				/*
				Pointer at <ANIM info>
				*/

				std::shared_ptr<GfxPackage> pkg = pushData(Anims);

				dataID_[(std::string)Anims->Value()] = pkg;

				data_.push_back(pkg);
				continue;
			}
			return true; //Found animation and structuring was successful
		}
		else { continue; } //Continue to next sibling
	}
	return false; //We went through all the objects and the ID wasn't found
}

std::shared_ptr<GfxPackage> DataLoader::pushData(tinyxml2::XMLElement *el)
{
	//Set values for streaming
	const char* widthChar = el->Attribute("width");
	const char* heightChar = el->Attribute("height");
	const char* frameChar = el->Attribute("frames");
	const char* speedDivChar = el->Attribute("speedDivider");
	
	//bridge info
	const char* fromChar = el->Attribute("from");
	const char* toChar = el->Attribute("to");
	const char* typeChar = el->Attribute("type");

	int width;
	int height;
	int frames;
	double speedDivider;
	std::string from;
	std::string to;
	std::string type;

	//Convert from const char* to K value
	utils::streamData(widthChar, width);
	utils::streamData(heightChar, height);
	utils::streamData(frameChar, frames);
	utils::streamData(speedDivChar, speedDivider);

	//Cleanup some char values and set them to their values
	utils::nullToEmpty(fromChar);
	utils::nullToEmpty(toChar);
	utils::nullToEmpty(typeChar);

	from = fromChar;
	to = toChar;
	type = typeChar;

	std::shared_ptr<GfxPackage> pkg;

	pkg.reset(new GfxPackage(
		(std::string)el->Attribute("path"),			//cast to string and set path in right place
		(std::string)el->Value(),					//cast to string and set the private key
		vector(width, height),							//Sets width and height into vector
		frames,											//Sets num frames
		speedDivider,
		from,
		to,
		type));

	return pkg;
}