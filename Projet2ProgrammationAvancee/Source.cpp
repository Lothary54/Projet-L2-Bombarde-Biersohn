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
	vector<Asteroide> asteroide(30); // de 0 à 29  ==> 30 astéroides
	Map map1;
	//Doit être effectué une seule fois, or de la boucle de jeu
	map1.afficherMap();
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

	SDL_Surface* tile[5][3];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			tile[i][j] = SDL_LoadBMP("darkPurple.bmp");
			if (tile[i][j])
			{
				SDL_Rect dest = { i * 256, j * 256, 0, 0 };
				SDL_BlitSurface(tile[i][j], NULL, SDL_GetWindowSurface(fenetre), &dest); //Copie du sprite
				SDL_UpdateWindowSurface(fenetre); //Mise à jour de la fenetre pour prendre en compte la copie du sprite
				SDL_FreeSurface(tile[i][j]); //Liberation de la ressource occupée par le sprite
			}
			else
			{
				fprintf(stdout, "Echec de chargement du sprite (%s)\n", SDL_GetError());
			}
		}
	}

	//Boucle principale
	while (!terminer)
	{
		
		while( SDL_PollEvent( &evenements) )
			switch (evenements.type)
			{
				case SDL_QUIT:
					terminer = true;
					break;
				case SDL_KEYDOWN:
					switch (evenements.key.keysym.sym)
					{
						case SDLK_ESCAPE:
						case SDLK_q:
							terminer = true;
							break;
					}
			}


	}
	//Fin de la boucle principale
	//Quitter SDL
	SDL_DestroyWindow(fenetre);
	SDL_Quit();



	return EXIT_SUCCESS;




}