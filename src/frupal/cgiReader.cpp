/* Daniel Dupriest, 2017
 * Communication from client with json library
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
