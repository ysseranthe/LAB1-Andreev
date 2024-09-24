#include "pipe.h"

void editPipe(pipe &pipeline) {
	pipeline.repair = 1 - pipeline.repair;
}

pipe::pipe(string n, unsigned l, unsigned d, bool r)
{
	name = n;
	length = l;
	diameter = d;
	repair = r;
}
