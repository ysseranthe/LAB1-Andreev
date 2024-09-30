#pragma once
#include <string>
using namespace std;

struct pipe
{   
    int length;
    int diameter;
    int getPipeLength();
    int getPipeDiameter();

    bool repair;
    bool isRepairing();

    pipe();
    pipe(string n, int l, int d, bool r);

    string name;
    string getPipeName();

    void setIsRepairing(bool t);
};