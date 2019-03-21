/*
* Titre : PlatBio.h - Travail Pratique #4
* Date : 21 Mars 2019
* Auteurs : Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052
*/

#ifndef PLAT_BIO_H
#define PLAT_BIO_H

#include <string>
#include <iostream>
#include "Plat.h"

using namespace std;

class PlatBio: public Plat {

public:
	// constructeurs
    PlatBio(string nom = "inconnu", double prix = 0,
    double cout = 0, double ecotaxe = 0);
    virtual ~PlatBio();
	//getters 
	double getEcoTaxe() const;
	//setters 
	void setEcoTaxe(double ecoTaxe);

	/*
	* afficherPlat()
	* Appelle la fonction Plat::afficherPlat() puis ajoute des information reliatives au platBio
	* Prend en paramètre un ostream
	*/
    void afficherPlat(ostream& os) const override;

	/*
	* getPrixDeRevient()
	* Retourne le prix - le coût + l’ecotaxe
	*/
    double getPrixDeRevient();

	/*
	* Clone()
	* Retourne un nouveau plat alloué dynamiquement
	*/
    Plat * clone() const override; 
protected:
	double ecoTaxe_;

};

#endif // !PLAT_VERT_H
