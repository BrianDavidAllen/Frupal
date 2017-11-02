#include <iostream>
#include <fstream> 
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(){
	int i = 0;
	int z = 0;
	int random = 0;
	ofstream myfile;
	myfile.open("map.txt");	
	

	srand(time(NULL));
	random = rand();
	cout << random;
	
	for(i = 0; i < 25; i++){
		for(z = 0; z < 25; z++){
			random = rand();
			myfile << i << ", " <<  z << ", " << random % 7 << " none\n";
		}
	}
	myfile.close();
	return 0;
}
