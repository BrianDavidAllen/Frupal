/* Daniel Dupriest, 2017
 * Testing communication between server and client with json library
 */
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include "json.hpp"

using namespace std;

class Terrain {
    public:
        Terrain();
        ~Terrain();
        virtual string getName() = 0;
};

class Plain : public Terrain {
    public:
        Plain();
        ~Plain();
        string getName();
};

