#pragma once
#include <string>
#include <iostream>

using namespace std;

class Grovnick {
	public:
		Grovnick(int x, int y, int terrain, string content);
	private:
		int x, y;
		bool visible;
		int terrain;
		string content;
};
