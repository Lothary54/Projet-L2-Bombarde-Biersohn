#include "Vaisseau.h"

using namespace std;



Vaisseau::Vaisseau()

{
	pointDeVie = 3;
	nomVaisseau = "VaisseauJoueur";
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
	/* Rien à mettre ici car on ne fait pas d'allocation dynamique
	dans la classe Vaisseau. Le destructeur est donc pour l'instant inutile mais
	En temps normal, un destructeur fait souvent des delete et quelques
	autres vérifications si nécessaire avant la destruction de l'objet. */
}



