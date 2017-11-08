#include <iostream>
#include <fstream> 
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

int main(){
	string identifier = "Frupal Map";
	string blankSpace = "###############";
	int dimensions = 25;

	int sizeOf = 0;
	int terrain = 0;
	int moreRandom = 0;
	string contentString = " ";
	string contentArray[] = {"Tree", "Boulder", "Blackberry bushes", "Power Bar", "Type 1 Treasure Chest", "Type 2 Treasure Chest", "Royal Diamonds", "Clue", "Hatchet", "Axe",
				"Chainsaw", "Chisel", "Sledge", "Jackhamer", "Matchete", "Shears", "Binoculars", "None"};

	ofstream myfile;
	myfile.open("../../build/mapGen.txt");	
	
	sizeOf = sizeof(contentArray);	

	myfile << identifier << "\n" << dimensions << "\n" << blankSpace << "\n";
	// TODO: Write player information here
	myfile << blankSpace << "\n";

	srand(time(NULL));
	
	for(int y = 0; y < dimensions; y++){
		for(int x = 0; x < dimensions; x++){
			terrain = rand();
			moreRandom = rand();
			moreRandom = moreRandom % 100;
			if(moreRandom < 10){
				contentString = "Power Bar";
			}
			else if(moreRandom < 20){
				contentString = "Type 1 Treasure Chest";
			}
			else if(moreRandom < 30){
				contentString = "None";
			}
			else if(moreRandom < 35){
				contentString = "Binoculars";
			}	
			else if(moreRandom < 40){
				contentString = "Shears";
			}
			else if(moreRandom < 45){
				contentString = "Machete";
			}
			else if(moreRandom < 50){
				contentString = "Jackhammer";
			}
			else if(moreRandom < 55){
				contentString = "Sledge";
			}
			else if(moreRandom < 60){
				contentString = "Chisel";
			}
			else if(moreRandom < 65){
				contentString = "Chainsaw";
			}
			else if(moreRandom < 70){
				contentString = "Axe";
			}
			else if(moreRandom < 75){
				contentString = "Hatchet";
			}
			else if(moreRandom < 80){
				contentString = "Clue";
			}
			else if(moreRandom < 85){
				contentString = "Type 2 Treasure Chest";
			}
			else if(moreRandom < 90){
				contentString = "Blackberry Bush";
			}
			else if(moreRandom < 95){
				contentString = "Boulder";
			}
			else {
				contentString = "Tree";
			}
			myfile << x << "," << y << ",0," << terrain % 7 << "," << contentString << "\n";
		}
	}
	myfile.close();
	return 0;
}
