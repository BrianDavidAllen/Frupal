#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "grovnick.hpp"

using namespace std;

class Map {
	public:
		Map();
		bool loadFile(const string identifier, const int dimensions, fstream &file);
		void generateFile(fstream &file);
                Grovnick * getGrovnick(int x, int y);
	        json Json();

    private:
		string *parseLine(const string line) const;
		void fillMissingGrovnicks(int &currentX, int &currentY, const int nextX, const int endY);

		string identifier;
		int dimensions;
		vector<vector<Grovnick>> grovnicks;
};
