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
	int terrainType = 0;
	string contentString = " ";
	string contentArray[] = {"tree", "boulder", "blackberry-bush", "power-bar", "type-1-treasure-chest", "type-2-treasure-chest", "royal-diamonds", "clue", "hatchet", "axe",
				"chainsaw", "chisel", "sledge", "jackhammer", "matchete", "shears", "binoculars", "none"};

	ofstream myfile;
	myfile.open("mapGen.txt");	

	myfile << "Frupal Map\n25\n#############\n";
	// TODO: add player coords
	myfile << "###########\n";
	
	sizeOf = sizeof(contentArray);	

	srand(time(NULL));
	//Generating a random number to be used to weight the contenString and terrain types. 
	for(y = 0; y < 25; y++){
		for(x = 0; x < 25; x++){
			random = rand();
			moreRandom = rand();
			moreRandom = moreRandom % 100;
			if(y == 24 && x == 11){
				contentString = "royal-diamonds";
				terrainType = 0;	
			}
			else if(moreRandom < 5){
				contentString = "power-bar";
				terrainType = 0;				
			}
			else if(moreRandom < 10){
				contentString = "type-1-treasure-chest";
				terrainType = 0;
			}
			else if(moreRandom < 20){
				contentString = "none";
				terrainType = 0;
			}
			else if(moreRandom < 30){
				contentString = "none";
				terrainType = 0;
			}
			else if(moreRandom < 35){
				contentString = "binoculars";
				terrainType = 1;
			}	
			else if(moreRandom < 40){
				contentString = "shears";
				terrainType = 1;
			}
			else if(moreRandom < 45){
				contentString = "machete";
				terrainType = 1;
			}
			else if(moreRandom < 50){
				contentString = "jackhammer";
				terrainType = 1;
			}
			else if(moreRandom < 55){
				contentString = "sledge";
				terrainType = 2;
			}
			else if(moreRandom < 60){
				contentString = "chisel";
				terrainType = 2;
			}
			else if(moreRandom < 65){
				contentString = "chainsaw";
				terrainType = 3;
			}
			else if(moreRandom < 70){
				contentString = "axe";
				terrainType = 4;
				}
			else if(moreRandom < 75){
				contentString = "hatchet";
				terrainType = 4;
			}
			else if(moreRandom < 80){
				contentString = "clue";
				terrainType = 4;
			}
			else if(moreRandom < 85){
				contentString = "type-2-treasure-chest";
				terrainType = 4;
			}
			else if(moreRandom < 90){
				contentString = "blackberry-bush";
				terrainType = 5;
			}
			else if(moreRandom < 95){
				contentString = "boulder";
				terrainType = 5;
			}
			else {
				contentString = "tree";
				terrainType = 5;
			}
			myfile << x << "," << y << ",0," << terrainType << "," << contentString << "\n";
		}
	}
	myfile.close();
	return 0;
}
