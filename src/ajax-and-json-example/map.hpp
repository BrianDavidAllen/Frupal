/* Daniel Dupriest, 2017
 * Testing communication between server and client with json library
 */
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include "json.hpp"
#include "terrain.hpp"

using namespace std;


class Map {
    public:
        Map();  //Creates map of default 64x64 size
        ~Map();
    private:
        int dimension;
        vector< vector<Terrain> > grid;
};

