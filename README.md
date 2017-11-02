# Frupal

Developed by: TheBestCS300Group

## Compiling

Get a copy of the code with git.

`git clone https://github.com/BrianDavidAllen/TheBestCS300Group.git`

Navigate to a directory under src/ with the code you wish to compile. For example, to compile the sample ajax and json code, enter the directory and run g++:

g++ -std=c++11 -static *.cpp

The *-std=c++11* option tells the compiler to use the 2011 C++ standard, enabling some very handy features like initializer lists and the auto keyword. The *-static* flag tells the compiler to build into the executable functions used in included libraries like *string*. For security reasons, the PSU linux servers will not allow student cgi scripts to use the string library dynamically. 

## Design Overview

### Frupal Web Client

The HTML, CSS and javascript which runs on the user's web browser.

It currently only sends a simple json object consisting of:

```json
{
  "action": "nameOfAction",
  "name": "playerName"
}
```

## Frupal Server

The cgi script which receives json objects from the web page. It currently just returns exactly what it receives.

### CgiReader Class

A basic class used by the server to read in json from stdin. Returned with a getCommand() function.
