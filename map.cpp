#include <iostream>
#include <fstream> 
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(){
	string identifier = "Frupal Map";
	string blankSpace = "###############";
	int dimensions = 25;

	int x = 0;
	int y = 0;
	int visible = 0;
	int terrain = 0;
	ofstream myfile;
	myfile.open("map.txt");	

	myfile << identifier << "\n" << dimensions << "\n" << blankSpace << "\n";
	// TODO: Write player information here
	myfile << blankSpace << "\n";

	srand(time(NULL));
	for(y = 0; y < dimensions; y++){
		for(x = 0; x < dimensions; x++){
			terrain = rand();
			// TODO: Make sure the visibility of the tiles surrounding the player is set to '1'
			myfile << x << "," << y << "," << visible << "," << terrain % 7 << ",None\n";
		}
	}

	myfile.close();
	return 0;
}
