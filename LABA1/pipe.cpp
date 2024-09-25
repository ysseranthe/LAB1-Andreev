#include "pipe.h"

pipe::pipe(string n, int l, int d, bool r)
{
	name = n;
	length = l;
	diameter = d;
	repair = r;
}

pipe::pipe()
{
	name = "Name";
	length = 1;
	diameter = 1;
	repair = true;
}

string pipe::getPipeName()
{
	return name;
}

int pipe::getPipeLength()
{
	return length;
}

int pipe::getPipeDiameter()
{
	return diameter;
}

bool pipe::isRepairing()
{
	return repair;
}

void pipe::setIsRepairing(bool t)
{
	repair = t;
}

