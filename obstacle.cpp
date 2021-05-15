#include "obstacle.h"
#include <string>
#include <iostream>
#include <graphics.h>
#include <fstream>
#include <cstdlib>

#include <sstream> 
using namespace std; 
obstacle::obstacle()
{
	Xobs =Yobs=Robs=0;
}

obstacle::obstacle(double Xobs0,double Yobs0,double Robs0){
	Xobs=Xobs0;
	Yobs=Yobs0;
	Robs=Robs0;	
}

obstacle::~obstacle()
{}

void obstacle::lecture()
{
	ifstream fichier("./Obstacle.obs");
	if(fichier)
	{
		int cpt=0;
		string ligne; //Une variable pour stocker les lignes lues

		while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
		{
			int esp1=ligne.find(' ',0);
			string x="";
			for(int i=0 ; i<esp1 ; i++)
			{
				x=x+ligne.at(i);
			}
			// object from the class stringstream 
			stringstream ok1(x); 

			// The object has the value 12345 and stream 
			// it to the integer x 
			int Xobs1 = 0; 
			ok1 >> Xobs1;
			int esp2=ligne.find(' ',esp1+1); 
			x="";
			for(int i=esp1+1;i<esp2;i++)
			{
				x=x+ligne.at(i);
			}
			stringstream ok2(x); 

			// The object has the value 12345 and stream 
			// it to the integer x 
			int Yobs1 = 0; 
			ok2 >> Yobs1;
			int r1=0;
			x="";
			for(int i=esp2+1;i<ligne.length();i++)
			{
				x=x+ligne.at(i);
			}
			stringstream ok3(x);
			// The object has the value 12345 and stream 
			// it to the integer x 
			ok3 >> r1;
			setcolor(RED);
			this->Xobs=Xobs1;
			this->Yobs=Yobs1;
			this->Robs=r1;
			this->drawObs();
			string str= "obs"+cpt; 
		}
	}
	else cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
}

void obstacle:: drawObs()
{setcolor(RED);
double x=Xobs;
double y=Yobs;
double r=Robs;
circle(x,y,r);

}
