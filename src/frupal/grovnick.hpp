/* Group D, 2017
 * Grovnick class with terrain type and contents.
 */
#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
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
        void setVisible();
	string getContent();
		string saveState() const;
        json toJson();
	void clearContent();
    private:
		int x, y;
		bool visible;
		int terrain;
		string content;
};
