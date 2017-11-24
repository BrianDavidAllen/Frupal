#include <iostream>
#include <fstream> 
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Perlin.h"
#include <math.h>

using namespace std;

const int DIMENSION = 25;
const int PLAYER_X = 11;
const int PLAYER_Y = 13;
const int NUMBER_OF_WALLS = 4;
const int MAX_WALL_LENGTH = 6;
const float PERLIN_ZOOM = .2;
const float PERLIN_Z = .5;

int terrain[DIMENSION][DIMENSION];
string objects[DIMENSION][DIMENSION];

void add(int number, string object)
{
    for(int i = 0; i < number; ++i)
    {
        int x, y;
        do
        {
            x = rand()%DIMENSION;
            y = rand()%DIMENSION;
        }
        while((x == PLAYER_X && y == PLAYER_Y)
            || terrain[x][y] == 2   //water
            || terrain[x][y] == 3   //wall
            || objects[x][y] != "none");
        objects[x][y] = object;
    }
}

void generateTerrain()
{
    Perlin p;
    float perlinMax = 0;
    float perlinMin = 0;
    float perlin[DIMENSION][DIMENSION];

    //Generate perlin noise
    for(int x = 0; x < DIMENSION; ++x)
    {
        for(int y = 0; y < DIMENSION; ++y)
        {
            float result = p.noise(x*PERLIN_ZOOM, y*PERLIN_ZOOM, PERLIN_Z);
            if(result > perlinMax)
                perlinMax = result;
            if(result < perlinMin)
                perlinMin = result;
            perlin[x][y] = result;
        }
    }

    //Scale noise to 0-1 and set terrain type
    for(int x = 0; x < DIMENSION; ++x)
    {
        for(int y = 0; y < DIMENSION; ++y)
        {
            float raw = perlin[x][y];
            float range = perlinMax-perlinMin;
            float adjusted = (raw-perlinMin) / range;
            
            int type;
            if(adjusted < .2)   //water
                type = 2;
            else if(adjusted < .3)  //swamp
                type = 5;
            else if(adjusted < .6)  //grass
                type = 0;
            else if(adjusted < .9)  //forest
                type = 1;
            else    //bog
                type = 4;

            terrain[x][y] = type;
        }
    }

    //Add some walls
    for(int i = 0; i < NUMBER_OF_WALLS; ++i)
    {
        bool horizontalWall = rand()%2 == 0;
        int wallLength = rand()%MAX_WALL_LENGTH + 1;
        if(horizontalWall)
        {
            int startX = rand()%(DIMENSION-wallLength);
            int startY = rand()%DIMENSION;
            for(int j = 0; j < wallLength; ++j)
            {
                terrain[startX+j][startY] = 3;
            }
        }
        else
        {
            int startX = rand()%DIMENSION;
            int startY = rand()%(DIMENSION-wallLength);
            for(int j = 0; j < wallLength; ++j)
            {
                terrain[startX][startY+j] = 3;
            }
        }
    }   
}

void generateObjects()
{
    for(int x = 0; x < DIMENSION; ++x)
        for(int y = 0; y < DIMENSION; ++y)
            objects[x][y] = "none";
    add(6, "tree");
    add(6, "boulder");
    add(6, "blackberry-bush");
    add(5, "power-bar");
    add(3, "type-1-treasure-chest");
    add(1, "type-2-treasure-chest");
    add(1, "royal-diamonds");
    add(2, "clue");
    add(2, "hatchet");
    add(1, "axe");
    add(1, "chainsaw");
    add(2, "chisel");
    add(1, "sledge");
    add(1, "jackhammer");
    add(1, "machete");
    add(2, "shears");
    add(1, "binoculars");
}

void writeMap(ofstream & file)
{
	file << "Frupal Map" << endl;
    file << DIMENSION << endl;
    file << "#############" << endl;
	file << "#############" << endl;
    for(int y = 0; y < DIMENSION; ++y)
        for(int x = 0; x < DIMENSION; ++x)
            file << x << "," << y << ",0," << terrain[x][y] << "," << objects[x][y] << endl;
}

void showMap()
{
    cout << " ╔";
    for(int i = 0; i < DIMENSION; ++i)
        cout << "═";
    cout << "╗" << endl;
    for(int x = 0; x < DIMENSION; ++x)
    {
        cout << " ║";
        for( int y = 0; y < DIMENSION; ++y)
        {
            int type = terrain[x][y];
            string glyph = "";
            if(type == 0)
                glyph = "▒";
            else if(type == 1)
                glyph = "▓";
            else if(type == 2)
                glyph = "~";
            else if(type == 3)
                glyph = "╬";
            else if(type == 4)
                glyph = "█";
            else
                glyph = "░";
            
            string object = objects[x][y];
            if(x == PLAYER_X && y == PLAYER_Y)
                glyph = "@";
            else if(object == "royal-diamonds")
                glyph = "D";

            cout << glyph;
        }
        cout << "║" << endl;
    }
    cout << " ╚";
    for(int i = 0; i < DIMENSION; ++i)
        cout << "═";
    cout << "╝" << endl << endl;
}

int main()
{
    srand(time(NULL));
   
    generateTerrain();
    generateObjects();

	ofstream mapFile;
	mapFile.open("default.txt");
    writeMap(mapFile);
    mapFile.close();
    
    remove("state.txt");
    remove("heroState.txt");

    cout << "Generated new " << DIMENSION << "x" << DIMENSION << " map." << endl;
    cout << "Please verify the location of the player, the Royal Diamonds and any walls before playing." << endl << endl;
    cout << " █ - bog" << endl;
    cout << " ▓ - forest" << endl;
    cout << " ▒ - plains" << endl;
    cout << " ░ - swamp" << endl;
    cout << " ~ - water" << endl;
    cout << " ╬ - wall" << endl;
    cout << " @ - player" << endl;
    cout << " D - Royal Diamonds" << endl << endl;

    showMap();

    cout << "Map file 'default.txt' overwritten and state files deleted." << endl << endl;

	return 0;
}
