/*
* Titre : PlatBio.cpp - Travail Pratique #4
* Date : 21 Mars 2019
* Auteurs : Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052
*/

#include "PlatBio.h"

PlatBio::PlatBio(string nom, double prix, double cout, double ecotaxe): Plat(nom, prix, cout), ecoTaxe_(ecotaxe)
{
}


PlatBio::~ PlatBio(){}

double PlatBio::getEcoTaxe() const
{
	return ecoTaxe_;
}

void PlatBio::setEcoTaxe(double ecoTaxe)
{
	ecoTaxe_ = ecoTaxe;
}

Plat * PlatBio::clone () const
{
	return new PlatBio(nom_, prix_, cout_, ecoTaxe_);
}

void PlatBio::afficherPlat(ostream& os) const
{	
	Plat::afficherPlat(os);
	os << "Plat Bio    comprend une Taxe ecologique de : " << ecoTaxe_ <<" $ " << endl;
}

double PlatBio::getPrixDeRevient()
{
	return prix_ - cout_ + ecoTaxe_;
}
