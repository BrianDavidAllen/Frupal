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
	string contentString = " ";
	string contentArray[] = {"Tree", "Boulder", "Blackberry bushes", "Power Bar", "Type 1 Treasure Chest", "Type 2 Treasure Chest", "Royal Diamonds", "Clue", "Hatchet", "Axe",
				"Chainsaw", "Chisel", "Sledge", "Jackhamer", "Matchete", "Shears", "Binoculars", "None"};

	ofstream myfile;
	myfile.open("mapGen.txt");	
	
	sizeOf = sizeof(contentArray);	

	srand(time(NULL));
	/*random = rand();
	cout << random;*/
	
	for(y = 0; y < 25; y++){
		for(x = 0; x < 25; x++){
			random = rand();
			moreRandom = rand();
			moreRandom = moreRandom % 100;
			if(moreRandom < 10){
				contentString = "powerBar";
			}
			else if(moreRandom < 20){
				contentString = "t1Treasure";
			}
			else if(moreRandom < 30){
				contentString = "none";
			}
			else if(moreRandom < 35){
				contentString = "binoculars";
			}	
			else if(moreRandom < 40){
				contentString = "shears";
			}
			else if(moreRandom < 45){
				contentString = "machete";
			}
			else if(moreRandom < 50){
				contentString = "jackhammer";
			}
			else if(moreRandom < 55){
				contentString = "sledge";
			}
			else if(moreRandom < 60){
				contentString = "chisel";
			}
			else if(moreRandom < 65){
				contentString = "chainsaw";
			}
			else if(moreRandom < 70){
				contentString = "axe";
			}
			else if(moreRandom < 75){
				contentString = "hatchet";
			}
			else if(moreRandom < 80){
				contentString = "clue";
			}
			else if(moreRandom < 85){
				contentString = "t2Treasure";
			}
			else if(moreRandom < 90){
				contentString = "blackberry";
			}
			else if(moreRandom < 95){
				contentString = "boulder";
			}
			else {
				contentString = "tree";
			}
			myfile << y  << ", " <<  x << ", " << random % 7 << ", 0, 0, " << contentString << "\n";
		}
	}
	myfile.close();
	return 0;
}
