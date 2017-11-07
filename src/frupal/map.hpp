#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "grovnick.hpp"

using namespace std;

class Map {
	public:
		Map();
		void loadFile(fstream &file);
		void generateFile(fstream &file);
	private:
		int dimensions;
		vector<vector<Grovnick>> grovnicks;
};
