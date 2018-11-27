#include "Asteroide.h"
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

Asteroide::Asteroide()
{
	srand(time(NULL));
	vitesseDeplacement = 3;
	longueur = 20;
	largeur = 20;
	posX = rand() % 1080;
	posY = rand() % 1000;
	posY = posY - 2 * posY;
	image = SDL_LoadBMP("meteorBrown_big1.bmp");
}

void Asteroide::deplacement()
{
	posY = posY + vitesseDeplacement;
	if (posY > 1086)
		posY = posY - 1140;

}

void Asteroide::dessinerAsteroide(Asteroide ast, SDL_Window* fenetre)
{
	if (ast.image)
	{
		SDL_Rect dest = { ast.posX, ast.posY, 0, 0 };
		SDL_BlitSurface(ast.image, NULL, SDL_GetWindowSurface(fenetre), &dest); //Copie du sprite
		//SDL_UpdateWindowSurface(fenetre); //Mise à jour de la fenetre pour prendre en compte la copie du sprite
		//SDL_FreeSurface(vaisseauJoueur.image); //Liberation de la ressource occupée par le sprite
	}
	else
	{
		fprintf(stdout, "Echec de chargement du sprite (%s)\n", SDL_GetError());
	}
		
}

Asteroide::~Asteroide()
{

}
