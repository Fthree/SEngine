#ifndef __ENTITYDATA__
#define __ENTITYDATA__

#include "tinyxml2.h"
#include "Vector.h"
#include "GFXPkg.h"
#include "Utils.h"

#include <vector>
#include <unordered_map>
#include <string>
#include <memory>
#include <sstream>

class DataLoader
{
public:
	DataLoader();
	~DataLoader();

	/*load data into buffer.
		DataPath is the path to the xml file
		GID's can be found in XML file data.xml
		whichData represents the type of data you want to grab. Entities? Maps? Particles?*/
	bool load(const char *DataPath, std::string whichGroup, std::string whichData);

	/*returns information on the specific ID given.
		ID is the animation ID (ID) within the xml file, this is to grab specific files for a graphics parser*/
	std::shared_ptr<GfxPackage> getDataValue(std::string id) { return dataID_[id]; }

	/*get all the data files grabbed from "load" function*/
	std::vector<std::shared_ptr<GfxPackage>> getPackage() { return data_; }

private:
	std::vector<std::shared_ptr<GfxPackage> > data_;
	std::unordered_map<std::string, std::shared_ptr<GfxPackage> > dataID_;

	std::shared_ptr<GfxPackage> pushData(tinyxml2::XMLElement *el);
};

#endif