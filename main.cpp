#include <graphics.h>
#include "obstacle.h"
#include "goal.h"
#include <iostream>
#include<math.h>
#include<conio.h>
#include <fstream>
#include <string>
using namespace std;
obstacle obs[15];
int n=0;
void lecture(){

	ifstream fichier("./Obstacle.obs");
	if(fichier){

		string ligne; // les lignes lues
		
		while(getline(fichier, ligne)){
			
			int esp1=ligne.find(' ',0);
			string s = "";
			for(int i=0 ; i<esp1 ; i++)
				s = s + ligne.at(i);

			stringstream ok1(s); 
			// The object has the value 12345 and stream 
			// it to the integer x 

			int Xobs1 = 0; 
			ok1 >> Xobs1;
			int esp2=ligne.find(' ',esp1+1); 
			s = "";
			for(int i=esp1+1;i<esp2;i++)
				s = s + ligne.at(i);
				
			stringstream ok2(s); 

			// The object has the value 12345 and stream 
			// it to the integer x 
			int Yobs1 = 0; 
			ok2 >> Yobs1;
			int r1=0;
			s = "";
			for(int i=esp2+1; i<ligne.length(); i++)
				s=s+ligne.at(i);
			
			stringstream ok3(s); 
			// The object has the value 12345 and stream 
			// it to the integer x 
			ok3 >> r1;
			setcolor(RED);
			obs[n].Xobs=Xobs1;
			obs[n].Yobs=Yobs1;
			obs[n].Robs=r1;
			obs[n].drawObs();
			string str= "obs"+n; 

			n++;
		} 	
	}

	else cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;

}

bool colision(dessin* d,obstacle o) {
	double dist =sqrt(pow(d->x-o.Xobs,2)+pow(d->y-o.Yobs,2));

	if(dist<abs(d->r+o.Robs)){
		cout<<"collision"<<endl;
		d->x=o.Xobs+(((d->x-o.Xobs)/dist)*(d->r+o.Robs));
		d->y=o.Yobs+(((d->y-o.Yobs)/dist)*(d->r+o.Robs));
		d->wd+=0.5;
		return true;
	}
	return false;
}
void enregistrement(dessin* robot){
	string const nomFichier("./position.pts");

	ifstream fichier(nomFichier.c_str());

	string Buffer = ""; //Variable contenant le texte à réécrire dans le fichier

	if(fichier)
	{
		int cpt=0;
		string ligne; //Une variable pour stocker les lignes lues
		int k=0;

		while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
		{
			k++;
		}
		cout<<k<<endl;
		fichier.close();

		int t=0; 
		if(k>1000)t=1;
		ifstream file(nomFichier.c_str());
		string line;
		int Line = 0;

		while (getline( file, line ) ) //on parcours le fichier et on initialise line à la ligne actuelle
		{
			Line++;

			if(Line !=t) {	//Si la ligne atteinte est différente de la ligne à supprimer...
				Buffer += line + "\n";//On ajoute le contenu de la ligne dans le contenu à réécrire
				//cout<<"tets"<<endl;
			}
		}

		file.close();
		ofstream monFlux(nomFichier.c_str());	
		monFlux<< Buffer; //On écris le texte dedans

		monFlux << "<" << robot->x << " >"<< "<" << robot->y << " >" << "<" << robot->x << " >"<< "<" << robot->wd << " >"<< "<" << robot->wg << " >"<< endl;
		monFlux.close();

	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
	}
}
int main() {
	initwindow(1600,700,"Test"); 
	lecture();
	double x=250;
	double y=300;

	dessin robot(x,y);

	// cout << robot.x<<endl;
	int i;
	robot.draw(robot.x,robot.y);
	delay(10);
	int c=getch();
	obstacle o(1,1,1);
	but b(600 ,200);
	while(c!=27)
	{
		cleardevice();
		//	robot.rotation(3.14/15,obs.x,obs.y);
		cout <<robot.wg<<endl;
		cout <<robot.wd<<endl;
		//	cout <<i<<endl;
		cout <<"///////////////"<<endl;
		b.drawGl();
		robot.draw(robot.x,robot.y);
		robot.automatiquement(b.x,b.y);
		bool t;
		for(int i=0;i<15;i++){
			bool t=	colision(&robot, obs[i]);
			//	if(t)robot.wd-=10;
			obs[i].drawObs();		
		}		
		// robot.draw(robot.x,robot.y);
		delay(10);
		robot.deplacement();
		if(b.Win(&robot))break;
		enregistrement(&robot);
	}
	cleardevice();
	while(getch()){
		outtextxy(400,500, "YOU WIN"); 
	}

	//	if(getch()) close();
	cout<<((pow(15,2)+pow(17.5,2)+pow(13.5,2)+pow(19.5,2)+pow(21.5,2)+pow(18,2))/6)-(17.5*17.5)<<endl;
	return 0;
}


