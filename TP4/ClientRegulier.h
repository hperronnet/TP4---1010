/*
* Titre : ClientRegulier.h - Travail Pratique #4
* Date : 21 Mars 2019
* Auteurs : Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052
*/

#ifndef CLIENT_REG
#define CLIENT_REG
#include "Client.h"
//#include "Restaurant.h"
#include "def.h"
class Restaurant;

class ClientRegulier : public Client
{
 public:
	//Constructeurs
	ClientRegulier();
	ClientRegulier(string_view nom, string_view prenom, int tailleGroupe, int nbPoints);
	//Destructeur
    ~ClientRegulier();

	//Accesseurs
     int getNbPoints() const ;

	//Autres Methodes
	void augmenterNbPoints(int bonus);

	/*
	* afficherClient()
	* Affiche le client et prend un ostream en paramètre
	*/
    void afficherClient(ostream & os) const override;

	/*
	* getReduction()
	* Retourne la réduaction du client si il y est éligible (nb de points suffisants)
	* Prend en paramètre un restaurant, le montant, et indique si c'est une livraison ou pas
	*/
    double getReduction(const Restaurant & res, double montant , bool estLivraison) override;// TODO
protected:
	int nbPoints_;
};
#endif
