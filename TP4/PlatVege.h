/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#ifndef PLAT_VEGE_H
#define PLAT_VEGE_H

#include "Vege.h"
#include "Plat.h"
#include "def.h"
class PlatVege :
        public Vege, public Plat, public Taxable
{
public:
	PlatVege(string nom = "inconnu", double prix = 0, double cout = 0, double vitamines = 0,
    double proteines = 0, double mineraux = 0);//TODO ok
    virtual ~PlatVege(); //Pas sure du virtual
    Plat * clone()const; // TODO ok
    virtual void afficherPlat(ostream & os) const;//TODO ok
    virtual double calculerApportNutritif() const; // TODO ok
	void setTaxe() override;
	double getTaxe() const override;
protected:
	double taxe_;
};
#endif
