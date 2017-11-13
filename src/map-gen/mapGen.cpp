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

	myfile << "Frupal Map\n25\n#############\n";
	// TODO: add player coords
	myfile << "###########\n";
	
	sizeOf = sizeof(contentArray);	

	srand(time(NULL));
	//Generating a random number to be used to weight the contenString and terrian types. 
	for(y = 0; y < 25; y++){
		for(x = 0; x < 25; x++){
			random = rand();
			moreRandom = rand();
			moreRandom = moreRandom % 100;
			if(y == 24 && x == 11){
				contentString = "Royal Diamonds";
				terrianType = 0;	
			}
			else if(moreRandom < 5){
				contentString = "Power Bar";
				terrianType = 0;				
			}
			else if(moreRandom < 10){
				contentString = "Type 1 Treasure Chest";
				terrianType = 0;
			}
			else if(moreRandom < 20){
				contentString = "None";
				terrianType = 0;
			}
			else if(moreRandom < 30){
				contentString = "None";
				terrianType = 0;
			}
			else if(moreRandom < 35){
				contentString = "Binoculars";
				terrianType = 1;
			}	
			else if(moreRandom < 40){
				contentString = "Shears";
				terrianType = 1;
			}
			else if(moreRandom < 45){
				contentString = "Machete";
				terrianType = 1;
			}
			else if(moreRandom < 50){
				contentString = "Jackhammer";
				terrianType = 1;
			}
			else if(moreRandom < 55){
				contentString = "Sledge";
				terrianType = 2;
			}
			else if(moreRandom < 60){
				contentString = "Chisel";
				terrianType = 2;
			}
			else if(moreRandom < 65){
				contentString = "Chainsaw";
				terrianType = 3;
			}
			else if(moreRandom < 70){
				contentString = "Axe";
				terrianType = 4;
				}
			else if(moreRandom < 75){
				contentString = "Hatchet";
				terrianType = 4;
			}
			else if(moreRandom < 80){
				contentString = "Clue";
				terrianType = 4;
			}
			else if(moreRandom < 85){
				contentString = "Type 2 Treasure Chest";
				terrianType = 4;
			}
			else if(moreRandom < 90){
				contentString = "Blackberry";
				terrianType = 5;
			}
			else if(moreRandom < 95){
				contentString = "Boulder";
				terrianType = 5;
			}
			else {
				contentString = "Tree";
				terrianType = 5;
			}
			myfile << x << "," << y << ",0," << terrianType << "," << contentString << "\n";
		}
	}
	myfile.close();
	return 0;
}
