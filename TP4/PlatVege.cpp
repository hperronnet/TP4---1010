/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "PlatVege.h"

PlatVege::PlatVege(string nom, double prix, double cout,
                   double vitamines, double proteines, double mineraux) : Plat(nom,prix,cout), Vege(nom,vitamines,proteines,mineraux)
{
}

PlatVege::~ PlatVege(){}

Plat* PlatVege::clone()const
{ 
	return new PlatVege(Plat::nom_, prix_, cout_, vitamines_, proteines_, mineraux_); //Classe Vege et Plat ont un nom_, donc on spécifie lequel on veut
}


void PlatVege::afficherPlat(ostream & os) const
{   
	Plat::afficherPlat(os);
	os << "PLAT VEGE  ";
	afficherVege(os);
}

double PlatVege::calculerApportNutritif() const
{
	return (vitamines_ *proteines_ / mineraux_) * RAPPORT_NUTRITIF;
}
