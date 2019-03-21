/*
* Titre : Plat.h - Travail Pratique #4
* Date : 21 Mars 2019
* Auteurs : Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052
*/


#ifndef PLAT_H
#define PLAT_H

#include "LectureFichierEnSections.h"
#include <string>
#include <string_view>
#include <iostream>
#include "def.h"
using std::string, std::string_view, std::ostream;  //? On ne devrait normalement pas faire de "using" global dans un .h, mais c'est accepte en INF1010.

class Plat {
public:
	// constructeur
	Plat(string_view nom = "inconnu", double prix = 0, double cout = 0);
    virtual ~Plat();
	//getters 
	string getNom() const;
	double getPrix() const;
	double getCout() const;

	//setters 
	void setNom(string nom);
	void setPrix(double prix);

	//methodes en plus
	double getPrixRevient();

	/*
	* Clone() : fonction virtuelle
	* Retourne un nouveau plat alloué dynamiquement
	*/
    virtual Plat *  clone () const;
	bool operator < (const Plat& plat) const;

	/*
	* afficherPlat : fonction virtuelle
	* Prend en paramètre un ostream
	*/
    virtual void afficherPlat(ostream& os) const; 



protected:
	string nom_;
	double prix_;
	double cout_;
};

#endif // !PLAT_H
