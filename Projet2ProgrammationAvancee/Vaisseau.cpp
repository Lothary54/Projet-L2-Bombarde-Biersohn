#include "Vaisseau.h"




Vaisseau::Vaisseau()

{
	pointDeVie = 3;
	posX = 300;
	posY = 300;
}


void Vaisseau::deplacement()
{


}


void Vaisseau::tireLaser()
{


}

bool Vaisseau::estVivant()
{
	return true;

}

Vaisseau::~Vaisseau()
{
	/* Rien � mettre ici car on ne fait pas d'allocation dynamique
	dans la classe Vaisseau. Le destructeur est donc pour l'instant inutile mais
	En temps normal, un destructeur fait souvent des delete et quelques
	autres v�rifications si n�cessaire avant la destruction de l'objet. */
}
