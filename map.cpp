#include <iostream>
#include <fstream> 
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(){
	int x = 0;
	int y = 0;
	int terrain = 0;
	ofstream myfile;
	myfile.open("map.txt");	

	srand(time(NULL));
	
	for(y = 0; y < 25; y++){
		for(x = 0; x < 25; x++){
			terrain = rand();
			myfile << x << "," << y << "," << terrain % 7 << ",None\n";
		}
	}
	myfile.close();
	return 0;
}
