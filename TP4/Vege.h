/*
* Titre : Vege.h - Travail Pratique #4
* Date : 21 Mars 2019
* Auteurs : Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052
*/

#ifndef VEGE_H
#define VEGE_H
#include <iostream>
#include <string_view>
#include <string>
#include"Taxable.h"
using namespace std;
class Vege
{
public:
	Vege(string nom, double vitamines, double proteines, double mineraux);
	double getVitamines();
	double getProteines();
	double getMineraux();
	void setVitamines(double vitamines);
	void setProteines(double proteines);
	void setMineraux(double mineraux);

	/*
	* afficherVege() : fonction virtuelle
	* Prend en param�tre un ostream et affiche les vitamines, prot�ines et mineraux d'un plat v�g�
	*/
    void afficherVege(ostream & os)const;

	/*
	* calculerApportNutritif() : fonction virtuelle pure � ne pas impl�menter
	*/
    virtual double calculerApportNutritif() const = 0;//TODO ok + V�rifier que c'est bien une m�thode virtuelle pure

protected: 
	double vitamines_;
	double proteines_;
	double mineraux_;
    
    string nom_;
};
#endif
