/** \brief Ce fichier doit contenir l'ensemble des implémentations
 relatives à la classe vecteur et aux fonctionnalités la concernant */

#include <cassert>
#include <iostream>
#include "vecteur.h"

Vecteur::Vecteur(size_t size, float valeur_defaut) : size(size), valeurs(new float[size]) {
	assert(size > 0);
	std::cout << "Construction d'un vecteur" << std::endl;
	for (size_t i = 0; i < size; i++) {
		valeurs[i] = valeur_defaut;
	}
}

void Vecteur::copy(const Vecteur &v) {
	size = v.dimensions();
	valeurs = new float[size];
	for (size_t i = 0; i < size; i++) {
		valeurs[i] = v.get(i);
	}
}

Vecteur::Vecteur(const Vecteur &v) {
	copy(v);
}

Vecteur::~Vecteur() {
	delete[] valeurs;
}

float Vecteur::get(size_t i) const {
	assert(i < size);
	return valeurs[i];
}

void Vecteur::set(size_t i, float valeur) {
	assert(i < size);
	valeurs[i] = valeur;
}

size_t Vecteur::dimensions() const {
	return size;
}

Vecteur& Vecteur::operator =(const Vecteur &v) {
	if (this != &v) {
		if (valeurs != NULL)
			delete[] valeurs;
		copy(v);
	}
	return (*this);
}

Vecteur Vecteur::operator +(const Vecteur &v) {
	return add(this, &v);
}

float& Vecteur::operator[](size_t i) {
	assert(i < size);
	return valeurs[i];
}

float Vecteur::operator[](size_t i) const {
	assert(i < size);
	return valeurs[i];
}

void afficherVecteur(const Vecteur *v, std::ostream &out) {
	size_t dim = v->dimensions();
	out << "Vecteur de dimension " << dim << endl << "Composantes : ";
	for (size_t i = 0; i < dim; i++) {
		out << v->get(i) << " ";
	}
	out << endl;
}

Vecteur* lireVecteur(std::istream &in) {
	size_t size;
	std::cout << "Taille du vecteur : ";
	in >> size;
	Vecteur *v = new Vecteur(size);
	for (size_t i = 0; i < size; i++) {
		float valeur;
		std::cout << "Valeur composante " << i << " : ";
		in >> valeur;
		v->set(i, valeur);
	}

	return v;
}

Vecteur add(const Vecteur *v1, const Vecteur *v2) {
	assert(v1->dimensions() == v2->dimensions());
	size_t size = v1->dimensions();
	Vecteur v(size); // variable locale
	for (size_t i = 0; i < size; i++) {
		float valeur = v1->get(i) + v2->get(i);
		v.set(i, valeur);
	}
	return v; // on renvoie une copie du vecteur, car si on renvoyait la reference, comme c'est une variable locale elle n'existerait plus
}

float operator*(const Vecteur &v1, const Vecteur &v2) {
	assert(v1.dimensions() == v2.dimensions());
	float prod_scal = 0;
	for (size_t i = 0; i < v1.dimensions(); i++) {
		prod_scal += v1.get(i) * v2.get(i);
	}

	return prod_scal;
}

std::istream& operator>>(std::istream &in, Vecteur &v) {
	for (size_t i = 0; i < v.dimensions(); i++) {
		std::cout << "Composante " << i + 1;
		float valeur;
		in >> valeur;
		v.set(i, valeur);
		std::cout << endl;
	}
	return in;
}

std::ostream& operator<<(std::ostream &out, Vecteur &v) {
	afficherVecteur(&v);
	return out;
}
