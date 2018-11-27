#include <SDL.h>

class Asteroide
{
public:
	Asteroide();
	~Asteroide();
	void deplacement();



private:
	int longueur, largeur;
	//QuelleImage
	SDL_Surface* image;
	int vitesseDeplacement;
	int posX, posY;
};
