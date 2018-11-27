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

}