#pragma once
#include <string>
using namespace std;

struct pipe
{
    string name;
    unsigned length;
    unsigned diameter;
    bool repair;
    pipe(string n, unsigned l, unsigned d, bool r);
};

void editPipe(pipe &pipeline);
