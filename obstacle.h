#include <string>
#include <iostream>
#include <fstream>
#include <graphics.h>
class obstacle
{
	public:
		double Xobs ,Yobs,Robs;
obstacle();
obstacle(double Xobs0,double Yobs0,double Robs0);
~obstacle();
void lecture();
void drawObs();
};

