#pragma once
#include <string>
using namespace std;

struct pipe
{   
    string name;
    int length;
    int diameter;
    bool repair;
    pipe(string n, int l, int d, bool r);
    pipe();
    string getPipeName();
    int getPipeLength();
    int getPipeDiameter();
    bool isRepairing();
    void setIsRepairing(bool t);
};