/* Group D, 2017
 * Map class and functions.
 * Austin Baugh
 */
#include "map.hpp"

Map::Map(): dimensions(25) {
    Logger log("map.log");
}


// Parses the provided string to a new Grovnick object that is added
// If the data is corrupted, false will be returned
bool Map::addGrovnick(string line, int &currentX, int &currentY) {
	//Break line into strings
	istringstream stream(line);
	vector<string> grovnickInfo;
	while(stream)
	{
    	string s;
        if (!getline(stream, s, ',')) break;
        	grovnickInfo.push_back(s);
    }

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
bool Map::loadFile(string identifier, int dimensions, stringstream &file) {
    log.write("Inside Map::loadFile()");
	this->identifier = identifier;
	//this->dimensions = dimensions;

	// Push a blank row of grovnicks
	vector<Grovnick> row;
	grovnicks.push_back(row);
	// Each line represents a single grovnick
	string line;
	// These are the coordinates of the current grovnick (may it be in the file or not)
	int currentX = 0, currentY = 0;
    while(getline(file, line)) {
        if(!addGrovnick(line, currentX, currentY)) {
            log.write("addGrovnick() failed");
			return false;
        }
    }
	//fillMissingGrovnicks(currentX, currentY, dimensions, dimensions - 1);

	return true;
}

// Erases the grovnicks from the previous game, and begins loading the default file
bool Map::reloadDefaultFile(string identifier, int dimensions, stringstream &file) {
	for(int i = 0; i < this->dimensions; i++)
		grovnicks[i].clear();
	grovnicks.clear();

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

	stringstream ss;

	for(int y = 0; y < dimensions; y++)
		for(int x = 0; x < dimensions; x++)
			ss << grovnicks[y][x].saveState();

	file << ss.str();
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
	Grovnick * toReturn = NULL;
	try
	{
		toReturn = &(grovnicks.at(loopedY).at(loopedX));
	}
	catch (out_of_range& error)
	{
		Error::sendError(error.what());
	}
	return toReturn;
}

string Map::getGrovnickContent(Grovnick *& grovnick){
	string content = grovnick->getContent();
	return content;
}

//David Gilmore: Sets grovnicks around the hero to visible.
void Map::setHeroVision(int x, int y, bool hasBio) {

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

  if(hasBio) {

  temp = getGrovnick(x,y+2);
  temp->setVisible();//north
  temp = getGrovnick(x,y-2);
  temp->setVisible();//south
  temp = getGrovnick(x-1,y+2);
  temp->setVisible();
  temp = getGrovnick(x+1,y+2);
  temp->setVisible();
  temp = getGrovnick(x-2,y+2);
  temp->setVisible();
  temp = getGrovnick(x+2,y+2);
  temp->setVisible();
  temp = getGrovnick(x-2,y);
  temp->setVisible();//west
  temp = getGrovnick(x+2,y);
  temp->setVisible();//east
  temp = getGrovnick(x-2,y+1);
  temp->setVisible();//northwest
  temp = getGrovnick(x+2,y+1);
  temp->setVisible();//northeast
  temp = getGrovnick(x-1,y-2);
  temp->setVisible();//southwest
  temp = getGrovnick(x+1,y-2);
  temp->setVisible();//southeast
  temp = getGrovnick(x-2,y-1);
  temp->setVisible();
  temp = getGrovnick(x-2,y-2);
  temp->setVisible();
  temp = getGrovnick(x+2,y-1);
  temp->setVisible();
  temp = getGrovnick(x+2,y-2);
  temp->setVisible();
  }

  
}
//David Gilmore: sets a grovnick to visited when the hero steps on a tile.
void Map::setHeroVisited(int x, int y)
{
   Grovnick * temp = nullptr;
   temp = getGrovnick(x,y);
   temp->setVisible();
}

//David Gilmore: sends all of the grovnicks as a json object. 
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
