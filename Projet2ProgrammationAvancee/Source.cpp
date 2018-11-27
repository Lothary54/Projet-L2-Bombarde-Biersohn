#include <iostream>
#include <stdio.h> // printf, scanf
#include <conio.h> // getch
#include <stdlib.h>
#include <stdbool.h>
#include <vector> // Pour les tableaux dynamiques

#include "Vaisseau.h" 
#include "Asteroide.h"
#include "Map.h"

#include <SDL.h>
using namespace std;

int main(int argc, char * argv[])
{

	Vaisseau vaisseauJoueur;
	Map map1;
	vector<Asteroide> asteroide(30); // de 0 à 29  ==> 30 astéroides
	
	//Fait partie de la boucle de jeu, les asteroides "tombent" constamment
	for (int i(0); i < int(asteroide.size()); ++i)
	{
		asteroide[i].deplacement();
	}


	SDL_Window* fenetre;  //Declaration de la fenêtre
	SDL_Event evenements; //Evenements liés à la fenêtre
	bool terminer = false;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)  //Initialisation de la SDL
	{
		printf("Erreur d'initialisation de la SDL: %s", SDL_GetError());
		SDL_Quit();
		return EXIT_FAILURE;
	}
	//Création de la fenêtre
	fenetre = SDL_CreateWindow("Ysoa", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_FULLSCREEN_DESKTOP);
	if (fenetre == NULL) // En cas d'erreur
	{
		printf("Erreur de la creation de la fenetre: %s", SDL_GetError());
		SDL_Quit();
		return EXIT_FAILURE;
	}

	
	//Dessin de la map pour la première fois
	map1.dessinerMap(fenetre);

	//Dessin du Vaisseau pour la première fois
	vaisseauJoueur.dessinerVaisseau(vaisseauJoueur, fenetre);




	//Boucle principale
	while (!terminer)
	{
		SDL_PollEvent(&evenements);
		if (evenements.type == SDL_KEYDOWN)
		{
			switch (evenements.key.keysym.sym)
			{
			case SDLK_ESCAPE: terminer = true; break;
			case SDLK_z: 
				if (vaisseauJoueur.yVel  > (-1) )
					vaisseauJoueur.yVel  -= 1; 
				break;
			case SDLK_s: 
				if (vaisseauJoueur.yVel  < 1 )
					vaisseauJoueur.yVel += 1; 
				break;
			case SDLK_q:
				if (vaisseauJoueur.xVel > (-1 ))
					vaisseauJoueur.xVel  -= 1; 
				break;
			case SDLK_d: 
				if (vaisseauJoueur.xVel  < 1 )
					vaisseauJoueur.xVel  += 1; 
				break;
			default: break;
			}
		}

		else if (evenements.type == SDL_KEYUP)
		{
			switch (evenements.key.keysym.sym)
			{
			case SDLK_z: 
				vaisseauJoueur.yVel = 0;
			case SDLK_s: 
				vaisseauJoueur.yVel = 0;
			case SDLK_q: 
				vaisseauJoueur.xVel = 0;
			case SDLK_d:
				vaisseauJoueur.xVel = 0;
			default: break;
			}
		}
	

		vaisseauJoueur.posX += vaisseauJoueur.xVel;
		vaisseauJoueur.posY += vaisseauJoueur.yVel;
		
		vaisseauJoueur.dessinerVaisseau(vaisseauJoueur, fenetre);
		
	}
	//Fin de la boucle principale

	//Liberation de la ressource occupée par le sprite
	SDL_FreeSurface(vaisseauJoueur.image); 
	//Quitter SDL
	SDL_DestroyWindow(fenetre);
	SDL_Quit();



	return EXIT_SUCCESS;




}