#ifndef DEF_VAISSEAU
#define DEF_VAISSEAU
#include <SDL.h>

class Vaisseau
{
public:
	Vaisseau();
	~Vaisseau();
	
	bool estVivant();
	void tireLaser();
	void dessinerVaisseau(Vaisseau vaisseauJoueur, SDL_Window* fenetre);
	

	int pointDeVie;
	//QuelleImage
	int posX, posY;
	int xVel, yVel;
	SDL_Surface* image;

private:
	

};



#endif
