/*
* Date : 25 février 2019
* Auteur : AbdeB
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
    double cout = 0, double ecotaxe = 0);//TODO Faut ajouter quoi ?
    virtual ~PlatBio(); //PAS SURE DU VIRTUAL
	//getters 
	double getEcoTaxe() const;
	//setters 
	void setEcoTaxe(double ecoTaxe);
    void afficherPlat(ostream& os) const override; // TODO ok
    double getPrixDeRevient(); //TODO ok
    Plat * clone() const override; // TODO ok
protected:
	double ecoTaxe_;

};

#endif // !PLAT_VERT_H
