#pragma once
#include <string>
using namespace std;

struct cs
{
	string name;
	string getName();

	int numberOfWorkshops;
	int workshopsInOperation;
	int efficiency;
	int getNumberOfWorkshops();
	int getWorkshopsInOperation();
	int getEfficiency();

	cs();
	cs(string N, int n, int w, int e);
};