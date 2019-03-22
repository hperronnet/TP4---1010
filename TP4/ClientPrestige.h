/*
* Titre : ClientPrestige.h - Travail Pratique #4
* Date : 21 Mars 2019
* Auteurs : Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052
*/

#ifndef CLIENT_PRESTIGE
#define CLIENT_PRESTIGE

#include "ClientRegulier.h"

#include "def.h"
class ClientPrestige : public ClientRegulier
{
public:
	//Constructeurs
	ClientPrestige();
	ClientPrestige(string_view nom, string_view prenom, int tailleGroupe, 
		           int nbPoints, ZoneHabitation adresse);
	//Destructeur
    virtual ~ClientPrestige(){};

	//Accesseur 
	ZoneHabitation getAdresseCode() const;

	//Autres Fonctions

	 /*
	 * afficherClient()
	 * Appelle la fonction Client::afficherClient()
	 * Prend en paramètre un ostream
	 */
    void afficherClient(ostream & os) const override;
	string getAdressCodeString() const;

	/*
	* getReduction()
	* Retourne la réduction à laquelle est élligible le client
	*  Si il y a livraison et que le Client dispose du nombre de points requis, n'ajoute pas les frais de livraison.
	* Prend en paramètre un restaurant, le montant, et indique si c'est une livraison ou pas
	*/
    double getReduction(const Restaurant & res, double montant, bool estLivraison) override;

private:
	ZoneHabitation adresse_;

};

#endif

