#include "Vaisseau.h"
#include <stdio.h> 
#include <SDL2/SDL.h>


Vaisseau::Vaisseau()

{
	pointDeVie = 3;
	posX = 460;
	posY = 570;
	xVel = 0;
	yVel = 0;
	image = SDL_LoadBMP("ship1.bmp");
	
}



void Vaisseau::tireLaser()
{


}

void Vaisseau::dessinerVaisseau(Vaisseau vaisseauJoueur, SDL_Window* fenetre)
{
	if (vaisseauJoueur.image)
	{
		SDL_Rect dest = { vaisseauJoueur.posX, vaisseauJoueur.posY, 0, 0 };
		SDL_BlitSurface(vaisseauJoueur.image, NULL, SDL_GetWindowSurface(fenetre), &dest); //Copie du sprite
		//SDL_UpdateWindowSurface(fenetre); //Mise à jour de la fenetre pour prendre en compte la copie du sprite
		//SDL_FreeSurface(vaisseauJoueur.image); //Liberation de la ressource occupée par le sprite
	}
	else
	{
		fprintf(stdout, "Echec de chargement du sprite (%s)\n", SDL_GetError());
	}

}



bool Vaisseau::estVivant()
{
	return true;

}





Vaisseau::~Vaisseau()
{
	/* Rien à mettre ici car on ne fait pas d'allocation dynamique
	dans la classe Vaisseau. Le destructeur est donc pour l'instant inutile mais
	En temps normal, un destructeur fait souvent des delete et quelques
	autres vérifications si nécessaire avant la destruction de l'objet. */
}
