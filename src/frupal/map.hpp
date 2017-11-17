#pragma once
/* Group D, 2017
 * Map class and functions.
 * Austin Baugh
 */
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "grovnick.hpp"
#include "hero.h"
#include "logger.hpp"

using namespace std;

class Map {
	public:
		Map();
		bool loadFile(string identifier, int dimensions, ifstream &file);
		bool reloadDefaultFile(string identifier, int dimensions, ifstream &file);
		void saveIdentifier(ofstream &file);
		void saveMap(ofstream &file);
		void setHeroVision(int x, int y); 

		void setHeroVisited(int x, int y);
        Grovnick * getGrovnick(int x, int y);
        json toJson();
		string getGrovnickContent(Grovnick *& grovnick);
    private:
		bool addGrovnick(string line, int &currentX, int &currentY);
		void fillMissingGrovnicks(int &currentX, int &currentY, int nextX, int endY);
        Logger log;
		string identifier;
		int dimensions;
		vector<vector<Grovnick>> grovnicks;
};
