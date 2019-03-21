/*
* Titre : Boisson.h - Travail Pratique #4
* Date : 21 Mars 2019
* Auteurs : Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052
*/

#ifndef BOISSON_h
#define BOISSON_h
#include "Taxable.h"
#include <string>
#include <string_view>
using namespace std;
class Boisson : public Taxable
{

 public:
    Boisson (string_view nom, double prix);
    string_view getNom() const;
    double getPrix () const;
	void setTaxe() override;
	double getTaxe() const override;

protected:
    string nom_;
    double prix_;
    double taxe_;
};


#endif /* Boisson_h */
