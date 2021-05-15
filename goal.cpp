#include "goal.h"
#include <string>
#include <iostream>
#include <graphics.h>
#include <fstream>
#include <cstdlib>
//#include "dessin.h"
#include <sstream> 
#include<math.h>
using namespace std; 
but::but()
{
	x = y = 0;
	r = 50;
}

but::but(double x0,double y0){

	x = x0;
	y = y0;
	r = 50;	
}

but::~but(){}

void but:: drawGl()
{   
	setcolor(10);
	double x0 = this->x;
	double y0 = this->y;
	double r0 = this->r;
	circle(x0,y0,r0);
}

bool but::Win(dessin* robot)
{
	double dist =sqrt(pow(robot->x - this->x ,2) + pow(robot->y - this->y ,2));
	int h = (robot-> r + this->r) /2;
	if(dist < (abs(h))){
		cleardevice();
		outtextxy(100, 100, "YOU WIN"); 
		return true;
	}
	return false;
}

