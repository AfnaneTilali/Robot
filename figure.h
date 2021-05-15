#include <graphics.h>

class figure
{
	public:
		double x, y,robs;
public:	
	figure();
~figure();
figure(double x0, double y0);

void rotation(double theta, double x0, double y0);
void drawobs();
void deplacement(double x0,double y0);
};


