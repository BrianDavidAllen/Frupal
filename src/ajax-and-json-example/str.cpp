/**
 * @file str.cpp
 * @author Daniel Dupriest
 * @date 2017
 * DIY substitute for the string library.
 */

#include "str.hpp"
#include <cstdio>

///////////////
// Str class //

Str::Str()
{
	text = new char;
	*text = '\0';
	length = 0;
}

Str::Str(const Str & s)
{
	text = new char[s.length+1];
	strcpy(text, s.text);
	length = strlen(text);
}

Str::Str(const char * c)
{
	text = new char[strlen(c)+1];
	strcpy(text, c);
	length = strlen(text);
}

Str::Str(const char & c)
{
	text = new char[2];
	text[0] = c;
	text[1] = '\0';
	length = 1;
}

Str::Str(const int & i)
{
	int columns = i / 10 + 1;
	text = new char[columns + 1];
	sprintf(text, "%d", i);
	length = columns;
}

Str::~Str()
{
	delete [] text;
	text = NULL;
}

Str & Str::operator = (const Str & right)
{
	if(this == &right)
		return *this;
	delete [] text;
	text = new char[right.length + 1];
	strcpy(text, right.text);
	length = right.length;
	return *this;
}

Str & Str::operator += (const Str & right)
{
	char * temp = text;
	int newLength = length + right.length;
	text = new char[newLength + 1];
	strcpy(text, temp);
	strcat(text, right.text);
	length = newLength;
	delete [] temp;
	return *this;
}

Str operator + (const Str & left, const Str & right)
{
	Str output(left);
	output += right;
	return output;
}

bool operator == (const Str & left, const Str & right)
{
	return !strcmp(left.text, right.text);
}

bool operator != (const Str & left, const Str & right)
{
	return strcmp(left.text, right.text);
}

bool operator < (const Str & left, const Str & right)
{
	return (strcmp(left.text, right.text) < 0);
}

bool operator <= (const Str & left, const Str & right)
{
	return (strcmp(left.text, right.text) < 1);
}

bool operator > (const Str & left, const Str & right)
{
	return (strcmp(left.text, right.text) > 0);
}

bool operator >= (const Str & left, const Str & right)
{
	return (strcmp(left.text, right.text) > -1);
}

ostream & operator << (ostream & out, const Str & right)
{
	/* For debugging string length problems
	out << right.text << "(" << right.length << ")";
	*/

	out << right.text;
	return out;
}

istream & operator >> (istream & in, Str & right)
{
	char * temp = new char[1024];
	cin.get(temp, 1024, '\n');
	delete [] right.text;
	right.text = new char[strlen(temp)+1];
	strcpy(right.text, temp);
	delete [] temp;
	right.length = strlen(right.text);
	return in;
}
