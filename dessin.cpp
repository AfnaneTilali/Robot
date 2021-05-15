//#include "figure.h"
#include "dessin.h"
#include<math.h>
#include <graphics.h>
#include <iostream>
using namespace std;

dessin::~dessin(){};

void dessin::draw(double x,double y){
	setcolor(4);
	figure cercle(x,y);

	circle(cercle.x,cercle.y,r);
	setcolor(1);

	figure ligneD(cercle.x,cercle.y+(r/2));
	///y= c.getX +r/2 x=c.getX
	line(ligneD.x-r/3,ligneD.y,ligneD.x+r/3,ligneD.y);
	
	figure ligneG(cercle.x,y-(r/2));
	line(ligneG.x-r/3,ligneG.y,ligneG.x+r/3,ligneG.y);
	
//	figure ligne(cercle.x,y);
//	line(ligne.x,ligne.y,ligne.x+r*cos(alp),ligne.y+ (int)r*sin(alp));

	/**	
	 *----------------------TRIANGLE DANS LE CERCLE----------------------------
	 ***/

	line(x + (int)r*cos(alp - (M_PI/2)) , y+ (int)r*sin(alp - (M_PI/2)), x + (int)r*cos(alp),y+ (int)r*sin(alp));

	line(x + (int)r*cos(alp), y+ (int)r*sin(alp), x+ (int)r*cos(alp+ (M_PI/2)), y+ (int)r*sin(alp + (M_PI/2)));

	line(x + (int)r*cos(alp- (M_PI/2)), y+ (int)r*sin(alp - (M_PI/2)), x+ (int)r*cos(alp+ (M_PI/2)),y+ (int)r*sin(alp+ (M_PI/2))); 



	/*  int arr[] = {cercle.x, cercle.y+r, cercle.x+r, cercle.y,  
                 cercle.x, cercle.y-r, cercle.x, cercle.y+r};_
    drawpoly(4, arr); 
	 */
	setcolor(WHITE);
};
void dessin::deplacement(){

	double x0=this->x;
	double y0=this->y;
	double Dd=wd*t*R0;
	double Dg=wg*t*R0;
	dr=(Dd+Dg)/2;
	x+=dr*25;
	double dalp=(Dd-Dg)/D;
	alp+=dalp*3.14/180;
	rotation(alp,x0,y0);
};
void dessin::deplacement(double x0,double y0)
{
	x+=x0;
	y+=y0;
};
void dessin::automatiquement(double xG,double yG){

//	double u[4]={x , y , x+r*cos(alp) , y+ (int)r*sin(alp)};
//	double v[4]={x , y , xG ,yG};
    
	double Theta=atan2((x+r*cos(alp)-x )*(yG-y)-(y+ (int)r*sin(alp)-y )*(xG -x ),(x+r*cos(alp)-x )*(xG -x )-(y+ (int)r*sin(alp)-y )*(yG-y));
	double sinT=sin(Theta);
	double cosT=cos(Theta);

	cout << "Direction"<<endl;
	cout<<"--------------->"<<Theta<<endl;
	if(Theta<0){
		if(Theta + M_PI/2 > 0.5){
			wg += 0.05*wg;
			wd -= 0.05*wd;
			cout<<"droite*"<<endl;
		}
		else if(Theta + M_PI/2 < -0.5){
			wg -= 0.05*wg;
			wd += 0.05*wd;
			cout<<"gauche*"<<endl;
		}
		else{

			wg += 0.05*wg;
			wd += 0.05*wd;
			cout<<"devant*"<<endl;
		}
	}else if(Theta>0){

		if(Theta - M_PI/2 <-0.5){
			wg -= 0.05*wg;
			wd += 0.05*wd;
			cout<<"droite"<<endl;
		}
		else if(Theta - M_PI <-0.5){
			wg += 0.05*wg;
			wd -= 0.05*wd;
			cout<<"gauche"<<endl;
		}
		else{

			wg += 0.05*wg;
			wd += 0.05*wd;
			cout<<"direct"<<endl;
		}	
	}	
};
