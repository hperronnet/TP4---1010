/*
* Titre : ClientOccasionnel.cpp - Travail Pratique #4
* Date : 21 Mars 2019
* Auteurs : Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052
*/

#include "ClientOccasionnel.h"

ClientOccasionnel::ClientOccasionnel(string_view nom, string_view prenom, int tailleGroupe)
: Client(nom, prenom, tailleGroupe)
{ 
}
ClientOccasionnel::~ClientOccasionnel(){}

int ClientOccasionnel::getNbPoints() const
{
	return 0;
}

void ClientOccasionnel::afficherClient(ostream & os) const
{
	Client::afficherClient(os);

}
double ClientOccasionnel::getReduction(const Restaurant & res, double montant, bool estLivraison)
{ 
	return 0.0;
}
