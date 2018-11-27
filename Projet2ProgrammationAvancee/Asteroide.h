#include <SDL.h>

class Asteroide
{
public:
	Asteroide();
	~Asteroide();
	void deplacement();
	void dessinerAsteroide(Asteroide ast, SDL_Window* fenetre);
	int posX, posY;

private:
	int longueur, largeur;
	//QuelleImage
	SDL_Surface* image;
	int vitesseDeplacement;
	
};
