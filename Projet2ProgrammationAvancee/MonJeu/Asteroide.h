#include <SDL2/SDL.h>

class Asteroide
{
public:
	Asteroide();
	~Asteroide();
	void deplacement();
	void dessinerAsteroide(Asteroide ast, SDL_Window* fenetre);
	int posX, posY, quelleImage;
	SDL_Surface* image;

private:
	int longueur, largeur;
	int vitesseDeplacement;
	
};
