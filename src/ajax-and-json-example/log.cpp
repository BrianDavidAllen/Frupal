/* Daniel Dupriest, 2017
 * Testing communication between server and client with json library
 */

#include "log.hpp"

Log::Log() {
}

Log::~Log() {
}

void Log::debug(const string & message){
	ofstream file;
	file.open("log.txt", ios::out | ios::app);
	file << "DEBUG: " << message << endl;    
	file.close();
}
