/* Daniel Dupriest, 2017
 * Testing communication between server and client with json library
 */

#include "cgiReader.hpp"

CgiReader::CgiReader() {
}

CgiReader::~CgiReader() {
}

json CgiReader::getCommand() {
    json j;
	if(!feof(stdin))
    	cin >> j;
	else
		j["message"] = "Nothing to read";
    return j;
}
