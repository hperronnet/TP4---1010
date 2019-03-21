/*
* Titre : Taxable.h - Travail Pratique #4
* Date : 21 Mars 2019
* Auteurs : Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052
*/

#ifndef TAXABLE_H
#define TAXABLE_H
class Taxable
{
public:
	/*
	* setTaxe() : fonction virtuelle pure - pas d'implémentation
	*/
    virtual void setTaxe () = 0;

	/*
	* getTaxe() : fonction virtuelle pure - pas d'implémentation
	*/
    virtual double getTaxe()const = 0;
};

#endif /* Taxable_h */
