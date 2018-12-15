#include <SDL2/SDL.h>

class Map
{
public:
	Map();
	~Map();
	void dessinerMap(SDL_Window* fenetre);
	void effacerMap(SDL_Window* fenetre);

};

