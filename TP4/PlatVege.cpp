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
	os << "PLAT ----" << Plat::nom_ << " - " << prix_ << " $ (" << cout_ << " $ pour le restaurant)." << endl << "PLAT VEGE  ";
	afficherVege(os);
}

double PlatVege::calculerApportNutritif() const
{
	return (vitamines_ *proteines_ / mineraux_) * RAPPORT_NUTRITIF;
}

void PlatVege::setTaxe()
{
	taxe_ = 0.12*prix_;
}


double PlatVege::getTaxe() const {
	return taxe_;
}