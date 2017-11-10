#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "grovnick.hpp"

using namespace std;

class Map {
	public:
		Map();
		bool loadFile(const string identifier, const int dimensions, ifstream &file);
		void saveIdentifier(ofstream &file) const;
		void saveMap(ofstream &file) const;
        Grovnick * getGrovnick(int x, int y);
        json toJson();

    private:
		string *parseLine(const string line) const;
		void fillMissingGrovnicks(int &currentX, int &currentY, const int nextX, const int endY);

		string identifier;
		int dimensions;
		vector<vector<Grovnick>> grovnicks;
};
