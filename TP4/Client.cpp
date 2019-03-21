/*
* Titre : Client.cpp - Travail Pratique #4
* Date : 21 Mars 2019
* Auteurs : Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052
*/

#include "Client.h"

Client::Client()
{ tableOccupee_ = nullptr;
}

Client::Client(string_view nom, string_view prenom, int tailleGroupe) :
	nom_(nom), prenom_(prenom), tailleGroupe_(tailleGroupe)
{
    tableOccupee_ = nullptr;
}

int Client::getTailleGroupe() const
{
	return tailleGroupe_;
}

string Client::getNom() const
{
	return nom_;
}

string Client::getPrenom() const
{
	return prenom_;
}
void Client:: setTable(Table * ta)
{ tableOccupee_ = ta;}

Table * Client:: getTable() const
{ return tableOccupee_;}

void Client::afficherClient(ostream & os) const
{
	os << prenom_ << " " << nom_;
	if (tableOccupee_ != nullptr) {
		os << " a une place au resto" << endl;
	}
	else {
		os << " n'a pas de place au resto" << endl;
	}
}