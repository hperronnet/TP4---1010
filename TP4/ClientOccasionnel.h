/*
* Titre : ClientOccasionnel.h - Travail Pratique #4
* Date : 21 Mars 2019
* Auteurs : Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052
*/

#ifndef CLIENT_OCCASIONNEL
#define CLIENT_OCCASIONNEL

#include "Client.h"

class ClientOccasionnel : public Client
{
public:
	//Constructeur
	ClientOccasionnel(string_view nom, string_view prenom, int tailleGroupe);
	//Destructeur
	~ClientOccasionnel();

	/*
	* getNbPoints()
	* Retourne 0 car un client occasionnel à 0 point
	*/
	int getNbPoints() const override;

	/*
	* afficherClient()
	* Appelle la fonction Client::afficherClient()
	* Prend en paramètre un ostream
	*/
	void afficherClient(ostream & os) const override;

	/*
	* getReduction()
	* Retourne 0 car un client occasionnel n'a aucune réduction
	* Prend en paramètre un restaurant, le montant, et indique si c'est une livraison ou pas
	*/
	double getReduction(const Restaurant & res, double montant, bool estLivraison) override;
};
#endif
