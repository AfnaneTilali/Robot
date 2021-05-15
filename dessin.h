#include <graphics.h>
#include "figure.h"
class dessin : public figure
{
	public:
		double r;
static const double D=0.05;
static const double R0=0.02;
static const double t=0.1;
static const double W0MAX=10;
double alp;
double wd,wg;
double dr;

public:
	dessin(){
	x=0;y=0;r=25;
	wg=10,wd=10;
	alp=0;
}
~dessin();
dessin(double x0,double y0) {
	x=x0;
	y=y0;
	r=25;
	wg=10,wd=10;
	alp=0;
}
void draw(double x,double y);
void deplacement();
void deplacement(double x0,double y0);
void automatiquement(double xG,double yG);
};

