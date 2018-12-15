#include "Map.h"
#include <stdio.h> 


Map::Map()
{
}


Map::~Map()
{
}

void Map::dessinerMap(SDL_Window* fenetre)
{
	//Creation de la map
	SDL_Surface* tile[8][4];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{

			tile[i][j] = SDL_LoadBMP("darkPurple.bmp");
			if (tile[i][j])
			{
				SDL_Rect dest = { i * 256, j * 256, 0, 0 };
				SDL_BlitSurface(tile[i][j], NULL, SDL_GetWindowSurface(fenetre), &dest); //Copie du sprite
				
				SDL_FreeSurface(tile[i][j]); //Liberation de la ressource occupée par le sprite
			}
			else
			{
				fprintf(stdout, "Echec de chargement du sprite (%s)\n", SDL_GetError());
			}
		}
	}
	//SDL_UpdateWindowSurface(fenetre); //Mise à jour de la fenetre pour prendre en compte la copie du sprite

}



void Map::effacerMap(SDL_Window* fenetre)
{
    SDL_Surface* tile[8][4];
	//Suppression de la map
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++)
            SDL_FreeSurface(tile[i][j]); //Liberation de la ressource occupée par le sprite
            
    }
}
