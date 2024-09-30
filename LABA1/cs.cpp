#include "cs.h"

cs::cs()
{
	name = "Name";
	numberOfWorkshops = 1;
	workshopsInOperation = 1;
	efficiency = 52;
}

cs::cs(string n, int now, int w, int e)
{
	name = n;
	numberOfWorkshops = now;
	workshopsInOperation = w;
	efficiency = e;
}

void cs::changeOperatingWorkshops(int n)
{
	workshopsInOperation += n;
}

string cs::getName()
{
	return name;
}

int cs::getNumberOfWorkshops()
{
	return numberOfWorkshops;
}

int cs::getWorkshopsInOperation()
{
	return workshopsInOperation;
}

int cs::getEfficiency()
{
	return efficiency;
}