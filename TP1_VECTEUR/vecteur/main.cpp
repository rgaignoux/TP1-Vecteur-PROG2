#include "vecteur.h"
#include <iostream>

void modifierComposante(Vecteur &v) {
	std::cout << "Composante à modifier : ";
	size_t i;
	std::cin >> i;

	std::cout << "Par la valeur : ";
	float valeur;
	std::cin >> valeur;

	v.set(i, valeur);
	std::cout << "Modification effectuée !";
}

int main() {

	Vecteur v;
	v[0] = 2.0;
	afficherVecteur(&v);

	return 0;
}
