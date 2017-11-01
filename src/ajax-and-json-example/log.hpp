/* Daniel Dupriest, 2017
 * Testing communication between server and client with json library
 */
#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Log {
    public:
        ~Log();
        static void debug(const string & message);
    private:
		Log();
};

