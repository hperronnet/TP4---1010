/*
* Titre : PlatBioVege.cpp - Travail Pratique #4
* Date : 21 Mars 2019
* Auteurs : Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052
*/

#include "PlatBioVege.h"

PlatBioVege::PlatBioVege(string nom, double prix, double cout, double ecotaxe, double vitamines, double proteines, double mineraux)
	: PlatBio(nom,prix,cout,ecotaxe), Vege(nom,vitamines,proteines,mineraux)
{
}

PlatBioVege:: ~PlatBioVege(){}


void PlatBioVege::afficherPlat(ostream & os) const
{    
	PlatBio::afficherPlat(os);
	os << "ET PLAT VEGE ";
	afficherVege(os);
}

Plat * PlatBioVege::clone() const
{ 
	return new PlatBioVege(Plat::nom_, prix_, cout_, ecoTaxe_, vitamines_, proteines_, mineraux_);
}

double PlatBioVege::calculerApportNutritif() const
{
	return (vitamines_*proteines_ / mineraux_)*RAPPORT_NUTRITIF_BIO* AVANTAGE_SANS_PESTICIDE;
}
