/* Daniel Dupriest, 2017
 * Testing communication between server and client with json library
 */

#include "game.hpp"

int main() {
	//Just a simple encapsulation to read in the cgi
	CgiReader cgi;

	//Build the json object
	json jsonFromClient = cgi.getCommand();
	
	//Turn the json into one long string
	string stringifiedJson = jsonFromClient.dump();

	//Let the client know we are sending in json format
    cout << "Content-Type:application/json; charset=utf-8" << endl << endl;

	//Send the actual json
	cout << stringifiedJson << endl;

    return 0;
}
