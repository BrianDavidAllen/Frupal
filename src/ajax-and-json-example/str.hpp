/**
 * @file str.hpp
 * @author Daniel Dupriest
 * @date 2017
 * DIY string class
 */

#ifndef _UTILITY_H
#define _UTILITY_H

#include <iostream>
#include <cstring>

using namespace std;


/**
 * DIY string class to support common operations
 */
class Str
{
	public:
		/// Constructor
		Str();

		/// Copy constructor
		Str(const Str & s);

		/// Copy constructor for char arrays
		Str(const char * c);

		/// Copy constructor for chars
		Str(const char & c);

		/// Copy constructor for integers
		Str(const int & i);

		/// Destructor
		~Str();

		/// Assignment operator
		Str & operator = (const Str & right);

		/// Append operator
		Str & operator += (const Str & right);

		/// Concatenation operator
		friend Str operator + (const Str & left, const Str & right);

		/// Equals operator
		friend bool operator == (const Str & left, const Str & right);

		/// Not equals operator
		friend bool operator != (const Str & left, const Str & right);

		/// Less than operator
		friend bool operator < (const Str & left, const Str & right);

		/// Less than or equals to operator
		friend bool operator <= (const Str & left, const Str & right);

		/// Greater than operator
		friend bool operator > (const Str & left, const Str & right);

		/// Greater than or equal to operator
		friend bool operator >= (const Str & left, const Str & right);

		/// Insertion operator
		friend ostream & operator << (ostream & out, const Str & right);

		/// Extraction operator
		friend istream & operator >> (istream & in, Str & right);

	private:
		/// Length of the string
		int length;

		/// Contents of the string
		char * text;
};

#endif
