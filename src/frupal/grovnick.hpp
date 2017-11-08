#pragma once
#include <string>
#include <iostream>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

class Grovnick {
	public:
		Grovnick(const int x, const int y, const bool visible, const int terrain, const string content);
        ~Grovnick();
        int getX();
        int getY();
        bool isVisible();
	int getTerrain();
	json toJson();
    private:
		int x, y;
		bool visible;
		int terrain;
		string content;
};
