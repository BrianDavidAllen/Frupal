#include "map.hpp"

Map::Map() {}

string *Map::parseLine(const string line) const {
	static string result[5];
	char delimiter = ',';
	size_t previousDel, nextDel;
	
	previousDel = line.find(delimiter);
	result[0] = line.substr(0, previousDel);
	for(int i = 1; i < 4; i++) {
		nextDel = line.find(delimiter, previousDel + 1);
		unsigned stringLength = nextDel - previousDel - 1;
		result[i] = line.substr(previousDel + 1, stringLength);
		previousDel = nextDel;
	}
	result[4] = line.substr(previousDel + 1);

	return result;
}

bool Map::loadFile(const string identifier, const int dimensions, fstream &file) {
	this->identifier = identifier;
	this->dimensions = dimensions;

	// Push a blank row of grovnicks
	vector<Grovnick> row;
	grovnicks.push_back(row);
	// Each line represents a single grovnick
	string line;
	// These are the coordinates of the current grovnick (may it be in the file or not)
	int currentX, currentY = 0;
	while(getline(file, line)) {
		string *grovnickInfo = parseLine(line);

		// Get coordinates
		int x = stoi(grovnickInfo[0]);
		if(x >= dimensions) return false;
		int y = stoi(grovnickInfo[1]);
		if(y >= dimensions) return false;

		// Get visibility
		bool visible = false;
		if(grovnickInfo[2] == "1") visible = true;

		// Get terrain type
		int terrain = stoi(grovnickInfo[3]);
		if(terrain >= 7) return false;

		fillMissingGrovnicks(currentX, currentY, x, y);

		Grovnick newGrovnick(x, y, visible, terrain, grovnickInfo[4]);
		grovnicks[y].push_back(newGrovnick);

		if(currentX == dimensions - 1 && currentY < dimensions - 1) {
			grovnicks.push_back(row);

			currentX = 0;
			currentY++;
		} else
			currentX++;
	}

	fillMissingGrovnicks(currentX, currentY, dimensions, dimensions - 1);

	return true;
}

void Map::fillMissingGrovnicks(int &currentX, int &currentY, const int nextX, const int endY) {
	vector<Grovnick> row;
	// Fill any missing rows first
	for(; currentY < endY; currentY++) {
		grovnicks.push_back(row);

		for(; currentX < dimensions; currentX++) {
			Grovnick blankGrovnick(currentX, currentY, false, 0, "None");
			grovnicks[currentY].push_back(blankGrovnick);
		}

		currentX = 0;
	}

	// Then, fill any missing grovnicks on the current row
	for(; currentX < nextX; currentX++) {
		Grovnick blankGrovnick(currentX, currentY, false, 0, "None");
		grovnicks[currentY].push_back(blankGrovnick);
	}
}

void Map::generateFile(fstream &file) {
	// TODO: Copy static map file to state-preserving file
}

Grovnick * Map::getGrovnick(int x, int y) {
    int loopedX = 0;
    int loopedY = 0;
    if(x < 0)
        loopedX = dimensions + x;
    else
        loopedX = x % dimensions;
    if(y < 0)
        loopedY = dimensions + y;
    else
        loopedY = y % dimensions;
    return &(grovnicks[loopedY][loopedX]);
}
