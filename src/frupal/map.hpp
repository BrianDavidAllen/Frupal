#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "grovnick.hpp"

using namespace std;

class Map {
	public:
		Map();
		bool loadFile(string identifier, int dimensions, fstream &file);
		void generateFile(fstream &file);
	private:
		string identifier;
		int dimensions;
		vector<vector<Grovnick>> grovnicks;
};
