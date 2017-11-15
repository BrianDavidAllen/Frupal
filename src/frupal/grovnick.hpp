/* Group D, 2017
 * Grovnick class with terrain type and contents.
 */
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

class Grovnick {
	public:
		Grovnick(const int x, const int y, const bool visited, const int terrain, const string content);
        ~Grovnick();
        int getX();
        int getY();
        bool isVisible();
	bool isVisited();
    	int getTerrain();
        void setVisible();
	void setVisited(); 
	string getContent();
		void saveState(ofstream &file) const;
        json toJson();
    private:
		int x, y;
		bool visible;
		bool visited;
		int terrain;
		string content;
};
