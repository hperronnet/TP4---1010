/*
* Titre : Boisson.cpp - Travail Pratique #4
* Date : 21 Mars 2019
* Auteurs : Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052
*/

#include "Boisson.h"
Boisson::Boisson (string_view nom, double prix): nom_(nom), prix_(prix)
{
	setTaxe(); //On initialise la taxe
}


string_view Boisson::getNom() const
{ 
	return nom_;
}

void Boisson::setTaxe() 
{
	taxe_ = 0.12;
}

double Boisson::getTaxe() const {
	return taxe_;
}
double Boisson::getPrix()  const
{
	return prix_;
};


