#include <stdio.h> // printf, scanf
#include <conio.h> // getch
#include <iostream>
#include <vector> // Pour les tableaux dynamiques

#include "Vaisseau.h" 
#include "Asteroide.h"
#include "Map.h"

using namespace std;

int main() {

	Vaisseau vaisseauJoueur ;
	vector<Asteroide> asteroide(30); // de 0 à 29  ==> 30 astéroides
	Map map1;

	//Doit être effectué une seule fois, or de la boucle de jeu
	map1.afficherMap();


	//Fait partie de la boucle de jeu, les asteroides "tombent" constamment
	for (int i(0); i < int(asteroide.size()); ++i)
	{
		asteroide[i].deplacement();
	}


	return 0;
}