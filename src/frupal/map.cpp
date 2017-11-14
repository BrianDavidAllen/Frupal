#include "map.hpp"

Map::Map(): dimensions(0) {
    Logger log("map.log");
}

// Splits a string based on the delimiter ',' into a static array (w/ size 5) of strings.
// Takes in the string being split and returns the array of strings.
string *Map::parseLine(string line) {
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

// Parses the provided string to a new Grovnick object that is added
// If the data is corrupted, false will be returned
bool Map::addGrovnick(string line, int &currentX, int &currentY) {
	string *grovnickInfo = parseLine(line);

	// Get coordinates
	int x = stoi(grovnickInfo[0]);
	if(x < 0 || x >= dimensions) return false;
	int y = stoi(grovnickInfo[1]);
	if(y < 0 || y >= dimensions) return false;

	// get visibility
	bool visited = false;
	if(grovnickInfo[2] == "1") visited = true;

	// Get terrain type
	int terrain = stoi(grovnickInfo[3]);
		if(terrain > 5) return false;

	Grovnick newGrovnick(x, y, visited, terrain, grovnickInfo[4]);

	fillMissingGrovnicks(currentX, currentY, x, y);
	grovnicks[y].push_back(newGrovnick);
	if(currentX == dimensions - 1 && currentY < dimensions - 1) {
		vector<Grovnick> row;
		grovnicks.push_back(row);

		currentX = 0;
		currentY++;
	} else
		currentX++;
	return true;
}

// Loads the map portion of the state-preserving file.
// Takes in the identifier for the map, its dimentions, and the state-preserving filestream.
// Returns true if the file is not corrupted and false otherwise.
bool Map::loadFile(string identifier, int dimensions, ifstream &file) {
    log.write("Inside Map::loadFile()");
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
        if(!addGrovnick(line, currentX, currentY)) {
            log.write("addGrovnick() failed");
			return false;
        }
    }
	fillMissingGrovnicks(currentX, currentY, dimensions, dimensions - 1);

	return true;
}

// Erases the grovnicks from the previous game, and begins loading the default file
bool Map::reloadDefaultFile(string identifier, int dimensions, ifstream &file) {
	for(int i = 0; i < this->dimensions; i++)
		grovnicks[i].erase(grovnicks[i].begin(), grovnicks[i].begin() + this->dimensions);
	grovnicks.erase(grovnicks.begin(), grovnicks.begin() + this->dimensions);

	return loadFile(identifier, dimensions, file);
}

// Adds empty grovnicks up to the specified (nextX, endY),
// from the current (currentX, currentY)
void Map::fillMissingGrovnicks(int &currentX, int &currentY, int nextX, int endY) {
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

void Map::saveIdentifier(ofstream &file) {
    log.write("Inside Map::saveIdentifier()");
    file << identifier << '\n' << dimensions << '\n';
	file << "##########\n";
}

void Map::saveMap(ofstream &file) {
    log.write("Inside Map::saveMap()");
    file << "##########\n";
	for(int y = 0; y < dimensions; y++)
		for(int x = 0; x < dimensions; x++)
			grovnicks[y][x].saveState(file);
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

void Map::setHeroVision(int x, int y) {

  Grovnick * temp; 
  temp = getGrovnick(x, y+1);
  temp->setVisible();//north
  temp = getGrovnick(x, y-1);
  temp->setVisible();//south
  temp = getGrovnick(x-1,y);
  temp->setVisible();//west
  temp = getGrovnick(x+1,y);
  temp->setVisible();//east
  temp = getGrovnick(x-1,y+1);
  temp->setVisible();//northwest
  temp = getGrovnick(x+1,y+1);
  temp->setVisible();//northeast
  temp = getGrovnick(x-1,y-1);
  temp->setVisible();//southwest
  temp = getGrovnick(x+1,y-1);
  temp->setVisible();//southeast
}

void Map::setHeroVisited(int x, int y)
{
   Grovnick * temp = nullptr;
   temp = getGrovnick(x,y);
   temp->setVisited();
}

json Map::toJson()
{
   json map;
   map["grovnicks"] = nullptr;
   for(int x = 0; x < dimensions; ++x)
   {
    for(int y = 0; y < dimensions; ++y)
     {
       map["grovnicks"].push_back(grovnicks[y][x].toJson()); 
       
     }
   }
   return map;
}
