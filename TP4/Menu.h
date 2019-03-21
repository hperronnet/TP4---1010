/*
* Titre : Menu.h - Travail Pratique #4
* Date : 21 Mars 2019
* Auteurs : Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052
*/

#ifndef MENU_H
#define MENU_H 

#include "Plat.h"
#include "PlatBio.h"
#include "PlatBioVege.h"
#include "PlatVege.h"
#include "pointers.h"
#include "def.h"
#include <fstream>
#include <vector>

using std::vector;  //? On ne devrait normalement pas faire de "using" global dans un .h, mais c'est accepté en INF1010.

class Menu {
public: 
	// Constructeurs.
	Menu(); 
	Menu(string fichier, TypeMenu type);
	//Constructeur de copie
	Menu(const Menu& menu);
	//Destructeur
	~Menu();

	// Getters.
	vector<Plat*> getListePlats() const;

	Plat* trouverPlat(string_view nom) const;
    Plat* allouerPlat(Plat* plat);

	/*
	* Surcharge de l'opéateur +=
	* Reçoit un pointeur de la classe de base Plat. La surcharge doit ajouter le pointeur dans les deux vecteurs si besoin. 
	*/
	Menu& operator+=(owner<Plat*> plat); //? Le parametre est indique "owner" pour montrer que cette methode prend possession du pointeur qui lui est passe, mais owner<Plat*> est equivalent à Plat*; voir pointers.h .

	/*
	* Surcharge de l'opéateur = 
	* Ecrase les attributs du menu par les attributs du menu passé en paramètre et qui renvoie ensuite une référence au menu..
	*/
	Menu& operator=(const Menu& menu); 
	void lireMenu(const string& fichier); 
	Plat* trouverPlatMoinsCher() const;
    Plat* lirePlatDe(LectureFichierEnSections& fichier);

	/*
	* Surcharge de l'opéateur << 
	* Affiche tout lemenu et aussi lemenu entièrement végétarien.
	*/
	friend ostream& operator<<(ostream& os, const Menu& menu);

private : 
	vector<owner<Plat*>> listePlats_; //? "owner" est juste un indicateur que la classe est propriétaire des plats (et devra faire un "delete"), mais owner<Plat*> est équivalent à Plat*; voir pointers.h .
	vector<owner<Vege*>> listePlatsVege_;

	TypeMenu type_;
};

#endif // !MENU_H
