/*
* Titre : PlatBioVege.h - Travail Pratique #4
* Date : 21 Mars 2019
* Auteurs : Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052
*/

#ifndef PLAT_BIOVEGE_H
#define PLAT_BIOVEGE_H

#include "PlatBio.h"
#include "Vege.h"
#include "def.h"
class PlatBioVege :
	public PlatBio, public Vege
{
public:
	//Constructeur par paramètre
	PlatBioVege(string nom = "inconnu", double prix = 0, double cout = 0, double ecotaxe = 0,
                double vitamines = 0, double proteines = 0, double mineraux = 0);
	//Destructeur
    virtual ~PlatBioVege();

	/*
	* Clone()
	* Retourne un nouveau plat alloué dynamiquement
	*/
    Plat * clone() const override;
	
	/*
	* afficherPlat()
	* Affiche le plat + les caractéristiques du platBio + les caractéristiques du platVege
	*/
    void afficherPlat(ostream & os) const override;
	
	/*
	* calculerApportNutritif()
	* Calcul (vitamines_*proteines_ / mineraux_)*RAPPORT_NUTRITIF_BIO* AVANTAGE_SANS_PESTICIDE
	*/
    double calculerApportNutritif() const override;

};
#endif
