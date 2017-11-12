#include <iostream>
#include <fstream> 
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

int main(){
	int y = 0;
	int x = 0;
	int sizeOf = 0;
	int random = 0;
	int moreRandom = 0;
	int terrianType = 0;
	string contentString = " ";
	string contentArray[] = {"Tree", "Boulder", "Blackberry bushes", "Power Bar", "Type 1 Treasure Chest", "Type 2 Treasure Chest", "Royal Diamonds", "Clue", "Hatchet", "Axe",
				"Chainsaw", "Chisel", "Sledge", "Jackhamer", "Matchete", "Shears", "Binoculars", "None"};

	ofstream myfile;
	myfile.open("mapGen.txt");	
	
	sizeOf = sizeof(contentArray);	

	srand(time(NULL));
	//Generating a random number to be used to weight the contenString and terrian types. 
	for(y = 0; y < 25; y++){
		for(x = 0; x < 25; x++){
			random = rand();
			moreRandom = rand();
			moreRandom = moreRandom % 100;
			if(y == 24 && x == 11){
				contentString = "royalDiamond";
				terrianType = 0;	
			}
			else if(moreRandom < 5){
				contentString = "powerBar";
				terrianType = 0;				
			}
			else if(moreRandom < 10){
				contentString = "t1Treasure";
				terrianType = 0;
			}
			else if(moreRandom < 20){
				contentString = "none";
				terrianType = 0;
			}
			else if(moreRandom < 30){
				contentString = "none";
				terrianType = 0;
			}
			else if(moreRandom < 35){
				contentString = "binoculars";
				terrianType = 1;
			}	
			else if(moreRandom < 40){
				contentString = "shears";
				terrianType = 1;
			}
			else if(moreRandom < 45){
				contentString = "machete";
				terrianType = 1;
			}
			else if(moreRandom < 50){
				contentString = "jackhammer";
				terrianType = 1;
			}
			else if(moreRandom < 55){
				contentString = "sledge";
				terrianType = 2;
			}
			else if(moreRandom < 60){
				contentString = "chisel";
				terrianType = 2;
			}
			else if(moreRandom < 65){
				contentString = "chainsaw";
				terrianType = 3;
			}
			else if(moreRandom < 70){
				contentString = "axe";
				terrianType = 4;
				}
			else if(moreRandom < 75){
				contentString = "hatchet";
				terrianType = 4;
			}
			else if(moreRandom < 80){
				contentString = "clue";
				terrianType = 4;
			}
			else if(moreRandom < 85){
				contentString = "t2Treasure";
				terrianType = 4;
			}
			else if(moreRandom < 90){
				contentString = "blackberry";
				terrianType = 5;
			}
			else if(moreRandom < 95){
				contentString = "boulder";
				terrianType = 5;
			}
			else {
				contentString = "tree";
				terrianType = 5;
			}
			myfile << y  << "," <<  x << "," << terrianType << ",0,0," << contentString << "\n";
		}
	}
	myfile.close();
	return 0;
}
