#pragma once
#include <string>
#include <iostream>

using namespace std;

class Grovnick {
	public:
		Grovnick(const int x, const int y, const bool visible, const int terrain, const string content);
        ~Grovnick();
        int getX();
        int getY();
        bool isVisible();
    private:
		int x, y;
		bool visible;
		int terrain;
		string content;
};
