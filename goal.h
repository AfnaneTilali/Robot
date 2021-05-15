#include <string>
#include <iostream>
#include <fstream>
#include "dessin.h"
#include <graphics.h>
class but
{
	public:
		double x ,y,r;
but();
but(double x0,double y0);
~but();
void drawGl();
bool Win(dessin* robot);
};

