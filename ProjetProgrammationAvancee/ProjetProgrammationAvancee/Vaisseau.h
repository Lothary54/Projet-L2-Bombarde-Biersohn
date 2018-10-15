#ifndef DEF_VAISSEAU
#define DEF_VAISSEAU

#include <string>

class Vaisseau
{
	public:
		Vaisseau();
		~Vaisseau();
		void deplacement();
		bool estVivant();
		void tireLaser();


	private:
		int pointDeVie;
		std::string nomVaisseau; //Pas de using namespace std, il faut donc mettre std:: devant string
		//QuelleImage
		
		
};



#endif