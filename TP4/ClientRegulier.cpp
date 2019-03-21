/*
* Titre : ClientRegulier.h - Travail Pratique #4
* Date : 21 Mars 2019
* Auteurs : Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052
*/

#include "ClientRegulier.h"

ClientRegulier::ClientRegulier()
{
	nbPoints_ = 0;
}

ClientRegulier::ClientRegulier(string_view nom, string_view prenom, int tailleGroupe, int npoints) : Client(nom,prenom,tailleGroupe), nbPoints_(npoints)
{
}

ClientRegulier::~ClientRegulier() {}

int ClientRegulier::getNbPoints() const
{
	return nbPoints_;
}


void ClientRegulier::augmenterNbPoints(int bonus)
{
	nbPoints_ += bonus;
}


void ClientRegulier::afficherClient(ostream & os) const
{
	Client::afficherClient(os);
}

double ClientRegulier::getReduction(const Restaurant & res, double montant, bool estLivraison)
{
	if (estLivraison) {
		cout << " Le client " << prenom_ << " " << nom_ << " n'est pas admissible à la livraison" << endl;
		return 0.0;
	} else if (nbPoints_ > SEUIL_DEBUT_REDUCTION) {
		return (-montant * TAUX_REDUC_REGULIER);
	}
	return 0.0;
}
