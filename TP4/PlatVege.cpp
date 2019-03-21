/*
* Titre : PlatVege.cpp - Travail Pratique #4
* Date : 21 Mars 2019
* Auteurs : Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052
*/

#include "PlatVege.h"

PlatVege::PlatVege(string nom, double prix, double cout,
                   double vitamines, double proteines, double mineraux) : Plat(nom,prix,cout), Vege(nom,vitamines,proteines,mineraux)
{
	setTaxe();
}

PlatVege::~ PlatVege(){}

Plat* PlatVege::clone()const
{ 
	return new PlatVege(Plat::nom_, prix_, cout_, vitamines_, proteines_, mineraux_); //Classe Vege et Plat ont un nom_, donc on spécifie lequel on veut
}


void PlatVege::afficherPlat(ostream & os) const
{   
	Plat::afficherPlat(os);
	os << "PLAT VEGE ";
	afficherVege(os);
	os << "(Apport nutritif de " << calculerApportNutritif() << "mg)" << endl;
}

double PlatVege::calculerApportNutritif() const
{
	return (vitamines_ *proteines_ / mineraux_) * RAPPORT_NUTRITIF;
}

void PlatVege::setTaxe()
{
	taxe_ = 0.07;
}


double PlatVege::getTaxe() const {
	return taxe_;
}