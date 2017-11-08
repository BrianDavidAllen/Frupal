#include "grovnick.hpp"

Grovnick::Grovnick(const int x, const int y, const bool visible, const int terrain, const string content):
	x(x), y(y), visible(visible), terrain(terrain), content(content)
{
	cout << content << endl;
}

Grovnick::~Grovnick()
{
}

int Grovnick::getX()
{
    return x;
}

int Grovnick::getY()
{
    return y;
}

bool Grovnick::isVisible()
{
    return visible;
}
