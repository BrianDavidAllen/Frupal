#include "map.hpp"

Map::Map() {}

bool Map::loadFile(string identifier, int dimensions, fstream &file) {
	this->identifier = identifier;
	this->dimensions = dimensions;

	string line;
	// Get line from file
	while(getline(file, line)) {
		// Get delimiter positions
		size_t delPos[3];
		char delimiter = ',';
		delPos[0] = line.find(delimiter);
		delPos[1] = line.find(delimiter, delPos[0] + 1);
		delPos[2] = line.find(delimiter, delPos[1] + 1);

		// Gets coordinates
		string xString = line.substr(0, delPos[0]);
		int x = stoi(xString);
		string yString = line.substr(delPos[0] + 1, delPos[1] - delPos[0] - 1);
		int y = stoi(yString);

		// Gets terrain type
		string terrainString = line.substr(delPos[1] + 1, delPos[2] - delPos[1] - 1);
		int terrain = stoi(terrainString);

		// Gets content string
		string contentString = line.substr(delPos[2] + 1);

		Grovnick newGrovnick(x, y, terrain, contentString);

		if(y == grovnicks.size()) {
			vector<Grovnick> row;
			grovnicks.push_back(row);
		}

		grovnicks[y].push_back(newGrovnick);
	}
	return true;
}

void Map::generateFile(fstream &file) {
	// Copy static map file to state-preserving file
	//loadFile(file);
}
