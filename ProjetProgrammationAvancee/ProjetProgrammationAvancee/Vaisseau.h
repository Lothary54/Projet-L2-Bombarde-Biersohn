#ifndef DEF_VAISSEAU
#define DEF_VAISSEAU


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
		//QuelleImage
		int posX, posY;
		
		
};



#endif