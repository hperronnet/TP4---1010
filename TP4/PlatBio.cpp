/*
* Date : 25 f�vrier 2019
* Auteur : AbdeB
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

//TODO
Plat * PlatBio:: clone () const
{
	return new PlatBio(nom_, prix_, cout_, ecoTaxe_);
}

void PlatBio::afficherPlat(ostream& os) const
{	
	Plat plat = static_cast<Plat>(*this);
	plat.afficherPlat(os);						//Devrait appeler la fonction de Plat
	os << "Plat Bio    comprend une Taxe ecologique de : " << ecoTaxe_ <<" $ " << endl;
}

double PlatBio::getPrixDeRevient()
{
	return prix_ - cout_ + ecoTaxe_;
}
