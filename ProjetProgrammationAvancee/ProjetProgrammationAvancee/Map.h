class Map
{
	public:
		Map();    // lire un fichier txt pour d�finir quelles images ont les tiles
		~Map();
		void afficherMap();


	private:
		// tableau pour d�finir quelle Image contient chaque tiles 
		// Image imageMap[10][6];

		// A changer en fonction de la taille de l'ecran et des tiles
		int posX[10][6] ;
		int posY[10][6] ;
};

