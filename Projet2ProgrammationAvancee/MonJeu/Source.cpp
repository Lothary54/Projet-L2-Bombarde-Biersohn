#include <iostream>
#include <stdio.h> // printf, scanf
//#include <conio.h> // getch
#include <stdlib.h>
#include <stdbool.h>
#include <vector> // Pour les tableaux dynamiques

#include "Vaisseau.h" 
#include "Asteroide.h"
#include "Map.h"
#include "time.h"
#include <SDL2/SDL.h>
using namespace std;

int main(int argc, char * argv[])
{

	Vaisseau vaisseauJoueur;
	Map map1;
	vector<Asteroide> asteroide(16); // de 0 à 29  ==> 30 astéroides
	
	for (int i(0); i < 16; ++i) {
		asteroide[i].posX = rand() % 990 ;
		asteroide[i].posY = rand() % 1000;
		asteroide[i].posY = asteroide[i].posY - 2 * asteroide[i].posY;
        int quelleImage = rand() % 4;
        if(quelleImage == 0)
            asteroide[i].image = SDL_LoadBMP("meteorBrown_big1.bmp");
        else if(quelleImage == 1)
             asteroide[i].image = SDL_LoadBMP("meteorBrown_big2.bmp");
        else if(quelleImage == 2)
             asteroide[i].image = SDL_LoadBMP("meteorBrown_big3.bmp");
        else if(quelleImage == 3)
             asteroide[i].image = SDL_LoadBMP("meteorBrown_big4.bmp");
	
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
	fenetre = SDL_CreateWindow("Ysoa", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_FULLSCREEN);
	if (fenetre == NULL) // En cas d'erreur
	{
		printf("Erreur de la creation de la fenetre: %s", SDL_GetError());
		SDL_Quit();
		return EXIT_FAILURE;
	}

    SDL_AudioSpec audioBufferSpec;
    Uint8 *audioBuffer;
    Uint32 audioBufferLen;
    
    if(!SDL_LoadWAV("test3.wav", &audioBufferSpec, &audioBuffer, &audioBufferLen)) {
        printf("Erreur lors du chargement du fichier WAV  \n");
        return 1;
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
				if (vaisseauJoueur.yVel > (-1)) {
					vaisseauJoueur.yVel -= 5;
					
				}
				break;
			case SDLK_s: 
				if (vaisseauJoueur.yVel < 1) {
					vaisseauJoueur.yVel += 5;
				
				}
				break;
			case SDLK_q:
				if (vaisseauJoueur.xVel > (-1)) {
					vaisseauJoueur.xVel -= 5;
					
				}
				break;
			case SDLK_d: 
				if (vaisseauJoueur.xVel < 1) {
					vaisseauJoueur.xVel += 5;
					
				}
				break;
			default: break;
			}
		}

		else if (evenements.type == SDL_KEYUP)
		{
			switch (evenements.key.keysym.sym)
			{
			case SDLK_z: 
				vaisseauJoueur.yVel = 0; break;
			case SDLK_s: 
				vaisseauJoueur.yVel = 0; break;
			case SDLK_q: 
				vaisseauJoueur.xVel = 0; break;
			case SDLK_d:
				vaisseauJoueur.xVel = 0; break;
			default: break;
			}
		}
	
        if(vaisseauJoueur.posX < 964 && vaisseauJoueur.posX > 0)
            vaisseauJoueur.posX += vaisseauJoueur.xVel;
        else if(vaisseauJoueur.posX >= 964)
            vaisseauJoueur.posX = vaisseauJoueur.posX - 20;
        else
            vaisseauJoueur.posX = vaisseauJoueur.posX + 20;
        if(vaisseauJoueur.posY < 710)
            vaisseauJoueur.posY += vaisseauJoueur.yVel;
        else
            vaisseauJoueur.posY = vaisseauJoueur.posY - 20;
		
		
		map1.dessinerMap(fenetre);
		for (int i(0); i < 16; ++i) {
			asteroide[i].deplacement();
			asteroide[i].dessinerAsteroide(asteroide[i], fenetre);
		}
		vaisseauJoueur.dessinerVaisseau(vaisseauJoueur, fenetre);
		SDL_UpdateWindowSurface(fenetre);
        
        // Collisions
        for (int i(0); i < 16; ++i) {
            if(vaisseauJoueur.posX >= asteroide[i].posX && vaisseauJoueur.posX <= asteroide[i].posX + 90)
                if(vaisseauJoueur.posY >= asteroide[i].posY && vaisseauJoueur.posY <= asteroide[i].posY + 70) {
                    for (int i(0); i < 16; ++i) 
                        asteroide[i].posY = asteroide[i].posY - 1000;
                    vaisseauJoueur.posX = 460;
                    vaisseauJoueur.posY = 570;
                }
            if(vaisseauJoueur.posX + 60 >= asteroide[i].posX && vaisseauJoueur.posX +60<= asteroide[i].posX + 90)
                if(vaisseauJoueur.posY >= asteroide[i].posY && vaisseauJoueur.posY <= asteroide[i].posY + 70) {
                    for (int i(0); i < 16; ++i) 
                        asteroide[i].posY = asteroide[i].posY - 1000;
                    vaisseauJoueur.posX = 460;
                    vaisseauJoueur.posY = 570;
                }
            if(vaisseauJoueur.posX + 60 >= asteroide[i].posX && vaisseauJoueur.posX +60<= asteroide[i].posX + 90)
                if(vaisseauJoueur.posY + 60 >= asteroide[i].posY && vaisseauJoueur.posY + 60 <= asteroide[i].posY + 70) {
                    for (int i(0); i < 16; ++i) 
                        asteroide[i].posY = asteroide[i].posY - 1000;
                    vaisseauJoueur.posX = 460;
                    vaisseauJoueur.posY = 570;
                }
            if(vaisseauJoueur.posX  >= asteroide[i].posX && vaisseauJoueur.posX <= asteroide[i].posX + 90)
                if(vaisseauJoueur.posY + 60 >= asteroide[i].posY && vaisseauJoueur.posY + 60 <= asteroide[i].posY + 70) {
                    for (int i(0); i < 16; ++i) 
                        asteroide[i].posY = asteroide[i].posY - 1000;
                    vaisseauJoueur.posX = 460;
                    vaisseauJoueur.posY = 570;
                }
            
        }
        
        
        
        
        
		
	}
	//Fin de la boucle principale

	//Liberation de la ressource occupée par le sprite
	SDL_FreeSurface(vaisseauJoueur.image); 
    for (int i(0); i < 16; ++i) 
        SDL_FreeSurface(asteroide[i].image); //Liberation de la ressource occupée par le sprite
    //map1.effacerMap(fenetre);
	//Quitter SDL
    SDL_FreeWAV(audioBuffer);
	SDL_DestroyWindow(fenetre);
	SDL_Quit();



	return EXIT_SUCCESS;




}
