/*
* Titre : PlatVege.h - Travail Pratique #4
* Date : 21 Mars 2019
* Auteurs : Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052
*/

#ifndef PLAT_VEGE_H
#define PLAT_VEGE_H

#include "Vege.h"
#include "Plat.h"
#include "def.h"
class PlatVege :
        public Vege, public Plat, public Taxable
{
public:
	//Constructeur par paramètres
	PlatVege(string nom = "inconnu", double prix = 0, double cout = 0, double vitamines = 0,
    double proteines = 0, double mineraux = 0);
	//Destructeur
    virtual ~PlatVege();

	/*
	* Clone()
	* Retourne un nouveau plat alloué dynamiquement
	*/
    Plat * clone()const;

	/*
	* afficherPlat()
	* Affiche le plat en ajoutant les caractéristiques du platVege
	*/
    virtual void afficherPlat(ostream & os) const;

	/*
	* calculerApportNutritif()
	* Retourne (vitamines_ *proteines_ / mineraux_) * RAPPORT_NUTRITIF
	*/
    virtual double calculerApportNutritif() const;
	void setTaxe() override;
	double getTaxe() const override;
protected:
	double taxe_;
};
#endif
