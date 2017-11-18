/* Daniel Dupriest 2017
 * Error messaging class
 */

#pragma once
#include <string>
#include <iostream>

using namespace std;

class Error {
	public:
		static void sendError(string message);
};
