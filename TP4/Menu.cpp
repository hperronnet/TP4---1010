/*
* Titre : Menu.cpp - Travail Pratique #4
* Date : 21 Mars 2019
* Auteurs : Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052
*/

#include "Menu.h"
#include "LectureFichierEnSections.h"
#include <cassert>  //? Contient "assert" qui permet de s'assurer qu'une expression est vraie, et terminer le programme avec un message d'erreur en cas contraire.
using namespace std;

// Constructeurs.

Menu::Menu() :
	type_{TypeMenu::Matin}
{
}

Menu::Menu(string fichier, TypeMenu type) :
	type_{type}
{
	lireMenu(fichier); 
}

Menu::~Menu()
{
	for (Plat* plat : listePlats_) {
		delete plat;
	}
}

Plat* Menu::allouerPlat(Plat* plat) {
    return plat->clone();
}


Menu::Menu(const Menu & menu) : type_(menu.type_)
{
	for (Plat* plat : menu.listePlats_)
	{
		PlatVege* platVege = dynamic_cast<PlatVege*>(plat);		//Si le type du plat est PlatVege, dynamic_cast est réussi et le plat retourné est différent de nullptr
		PlatBio* platBio = dynamic_cast<PlatBio*>(plat);		//Pareil pour PlatBio et PlatBioVege
		PlatBioVege* platBioVege = dynamic_cast<PlatBioVege*>(plat);

		if (platVege != nullptr) {				//On ajoute le platVege dans les deux listes			
			listePlats_.push_back(platVege);
			listePlatsVege_.push_back(platVege);
		}
		else if (platBio != nullptr) {
			listePlats_.push_back(platBio);
		}
		else if (platBioVege != nullptr) {		//On ajoute le platVege dans les deux listes
			listePlats_.push_back(platBioVege);
			listePlatsVege_.push_back(platBioVege);
		}
		else {									//Si le plat ne correspond à aucun type spécial, on l'ajoute dans la lsite sans cast.
			listePlats_.push_back(plat);
		}

	}
}

Menu & Menu::operator=(const Menu & menu)
{
	if (this != &menu)						//On vérie que l'adresse du menu à copier et le menu acutel ne sont pas les mêmes
	{
		type_ = menu.type_;					//On écrase les menus
		for (Plat* plat : listePlats_) {
			delete plat;
		}
		listePlats_.clear();
		listePlatsVege_.clear();

		for (Plat* plat : menu.listePlats_) {
			PlatVege* platVege = dynamic_cast<PlatVege*>(plat);		//Si le type du plat est PlatVege, dynamic_cast est réussi et le plat retourné est différent de nullptr
			PlatBio* platBio = dynamic_cast<PlatBio*>(plat);		//Pareil pour PlatBio et PlatBioVege
			PlatBioVege* platBioVege = dynamic_cast<PlatBioVege*>(plat);

			//On remplit le nouveau menu avec des plats alloués dynamiquement
			if (platVege != nullptr) {								
				listePlats_.push_back(allouerPlat(platVege));
				listePlatsVege_.push_back(platVege);
			}
			else if (platBio != nullptr) {
				listePlats_.push_back(allouerPlat(platBio));
			}
			else if (platBioVege != nullptr) {
				listePlats_.push_back(allouerPlat(platBioVege));
				listePlatsVege_.push_back(platBioVege);
			}
			else {
				listePlats_.push_back(allouerPlat(plat));
			}
		}
	}
	return *this;
}

// Getters.

vector<Plat*> Menu::getListePlats() const
{
	return listePlats_;
}

// Autres methodes.

Menu& Menu::operator+=(owner<Plat*> plat) 
{
	PlatVege* platVege = dynamic_cast<PlatVege*>(plat);			//Si le type du plat est PlatVege, dynamic_cast est réussi et le plat retourné est différent de nullptr
	PlatBio* platBio = dynamic_cast<PlatBio*>(plat);			//Pareil pour PlatBio et PlatBioVege
	PlatBioVege* platBioVege = dynamic_cast<PlatBioVege*>(plat);

	//On ajoute le plat dans les différentes listes selon son type
	if (platVege != nullptr) {
		listePlats_.push_back(platVege);
		listePlatsVege_.push_back(platVege);
	}
	else if (platBio != nullptr) {
		listePlats_.push_back(platBio);
	}
	else if (platBioVege != nullptr) {
		listePlats_.push_back(platBioVege);
		listePlatsVege_.push_back(platBioVege);
	}
	else {
		listePlats_.push_back(plat);
	}
	return *this;
}

void Menu::lireMenu(const string& nomFichier) {
	LectureFichierEnSections fichier{nomFichier};
	fichier.allerASection(entetesDesTypesDeMenu[static_cast<int>(type_)]);
	while (!fichier.estFinSection())
		*this += lirePlatDe(fichier);
}

Plat* Menu::trouverPlatMoinsCher() const
{
	assert(!listePlats_.empty() && "La liste de plats de doit pas etre vide pour trouver le plat le moins cher.");
	Plat* minimum = listePlats_[0];
	for (Plat* plat : listePlats_)
		if (*plat < *minimum)
			minimum = plat;

	return minimum;
}

Plat* Menu::trouverPlat(string_view nom) const
{
	for (Plat* plat : listePlats_)
		if (plat->getNom() == nom)
			return plat; 

	return nullptr; 
}
Plat* Menu::lirePlatDe(LectureFichierEnSections& fichier)
{
    auto lectureLigne = fichier.lecteurDeLigne();
    
    string nom, typeStr;
    TypePlat type;
    double prix, coutDeRevient;
    lectureLigne >> nom >> typeStr >> prix >> coutDeRevient;
    type = TypePlat(stoi(typeStr));
    double ecotaxe, vitamines, proteines, mineraux;
    switch (type) {
        case TypePlat::Bio :
            lectureLigne >> ecotaxe;
            return new PlatBio{ nom, prix, coutDeRevient, ecotaxe };
        case TypePlat::BioVege:
            lectureLigne >> ecotaxe >> vitamines >> proteines >> mineraux;
            return new PlatBioVege(nom, prix, coutDeRevient, ecotaxe, vitamines, proteines, mineraux);
        case TypePlat::Vege:
            lectureLigne >> vitamines >> proteines >> mineraux;
            return new PlatVege(nom, prix, coutDeRevient, vitamines, proteines, mineraux);
        default:
            return new Plat{nom, prix, coutDeRevient};
    }
    
}

// Fonctions globales.

ostream& operator<<(ostream& os, const Menu& menu)
{   
	for (Plat* plat : menu.listePlats_) {
		PlatVege* platVege = dynamic_cast<PlatVege*>(plat);			//Si le type du plat est PlatVege, dynamic_cast est réussi et le plat retourné est différent de nullptr
		PlatBio* platBio = dynamic_cast<PlatBio*>(plat);			//Pareil pour PlatBio et PlatBioVege
		PlatBioVege* platBioVege = dynamic_cast<PlatBioVege*>(plat);
		
		//On affiche le plat en fonction de son type
		if (platVege != nullptr) {
			platVege->PlatVege::afficherPlat(os);
		} else if (platBioVege != nullptr) {
			platBioVege->PlatBioVege::afficherPlat(os);
		} else if (platBio != nullptr) {
			platBio->PlatBio::afficherPlat(os);
		} else {
			plat->Plat::afficherPlat(os);
		}

	}

	os << endl <<  "MENU ENTIEREMENT VEGETARIEN" << endl;
	//Puis on affiche le menu végétarien
	for (Plat* plat : menu.listePlats_) {
		PlatVege* platVege = dynamic_cast<PlatVege*>(plat);
		PlatBioVege* platBioVege = dynamic_cast<PlatBioVege*>(plat);
		if (platVege != nullptr) {
			os << "PLAT VEGE  ";
			platVege->afficherVege(os);
		}
		else if (platBioVege != nullptr) {
			os << "PLAT VEGE  ";
			platBioVege->afficherVege(os);
		}
	}
	
	return os;
}
