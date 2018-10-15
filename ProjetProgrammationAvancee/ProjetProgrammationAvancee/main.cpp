#include <stdio.h> // printf, scanf
#include <conio.h> // getch
#include <iostream>

#include "Vaisseau.h" 

using namespace std;

int main() {

	Vaisseau VaisseauJoueur ;
	int age;

	printf("Bienvenue !\n");
	printf("Entrez votre age : ");
	scanf_s("%d", &age);

	printf("Vous avez %d ans", age);
	_getch();


	return 0;
}