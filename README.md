# Frupal

Developed by: TheBestCS300Group

## Compiling

Get a copy of the code with git.

`git clone https://github.com/BrianDavidAllen/TheBestCS300Group.git`

Navigate to a directory under src/ with the code you wish to compile. For example, to compile the sample ajax and json code, enter the directory and run g++:

`g++ -std=c++11 -static *.cpp`

The `-std=c++11` option tells the compiler to use the 2011 C++ standard, enabling some very handy features like initializer lists and the auto keyword. The `-static` flag tells the compiler to build into the executable functions used in included libraries like *string*. For security reasons, the PSU linux servers will not allow student cgi scripts to use the string library dynamically. 

## Installation

To run on the server:

1. Copy the contents of `build/` somewhere in your web root
2. Rename your freshly compiled `a.out` as `frupal.cgi`
3. Copy it into the same web directory and overwrite the `frupal.cgi` there
4. `chmod -R 755` everything in the web directory to allow access.

