#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "grovnick.hpp"
#include "hero.h"
using namespace std;

class Map {
	public:
		Map();
		bool loadFile(string identifier, int dimensions, ifstream &file);
		void saveIdentifier(ofstream &file);
		void saveMap(ofstream &file);
		void setHeroVision(int x, int y); 
<<<<<<< HEAD
		void setHeroVisited(int x, int y);
        Grovnick * getGrovnick(int x, int y);
=======
        Grovnick *getGrovnick(int x, int y);
>>>>>>> a554635d6bb51b7454bd6598753b196725e73593
        json toJson();

    private:
		string *parseLine(string line);
		bool addGrovnick(string line, int &currentX, int &currentY);
		void fillMissingGrovnicks(int &currentX, int &currentY, int nextX, int endY);

		string identifier;
		int dimensions;
		vector<vector<Grovnick>> grovnicks;
};
