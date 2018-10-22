#include <iostream>
#include <stdio.h> // printf, scanf
#include <conio.h> // getch
#include <vector> // Pour les tableaux dynamiques

#include "Vaisseau.h" 
#include "Asteroide.h"
#include "Map.h"

#include <SDL.h>
using namespace std;

int main(int argc, char * argv[])
{

	Vaisseau vaisseauJoueur;
	vector<Asteroide> asteroide(30); // de 0 à 29  ==> 30 astéroides
	Map map1;

	//Doit être effectué une seule fois, or de la boucle de jeu
	map1.afficherMap();


	//Fait partie de la boucle de jeu, les asteroides "tombent" constamment
	for (int i(0); i < int(asteroide.size()); ++i)
	{
		asteroide[i].deplacement();
	}


	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{

		cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
	}
	else
	{
		cout << "SDL initialization succeeded !";
	}

	cin.get();
	return 0;




}