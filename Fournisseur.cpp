/********************************************
* Titre: Travail pratique #3 - Fournisseur.cpp
* Date: 
* Auteur:
*******************************************/
#include "Fournisseur.h"

//constructeur par parametre
Fournisseur::Fournisseur(const string & nom, const string & prenom, int identifiant, const string & codePostal) : Usager(nom, prenom, identifiant, codePostal)
{
	for (unsigned i = 0; i < NIVEAUX_SATISFACTION; i++)
	{
		satisfaction_.niveaux_[i] = 0;
	}
}

//methodes d'accees
vector<Produit*> Fournisseur::obtenirCatalogue() const
{
	return contenuCatalogue_;
}

Satisfaction Fournisseur::obtenirSatisfaction() const
{
	return satisfaction_;
}

//methode de modification
void Fournisseur::modifierSatisfaction(Satisfaction satisfaction)
{
	for (unsigned i = 0; i < NIVEAUX_SATISFACTION; i++)
	{
		satisfaction_.niveaux_[i] = satisfaction.niveaux_[i];
	}
}

void Fournisseur::noter(int appreciation)
{
	satisfaction_.niveaux_[appreciation]++;
}

//methode qui ajoute un produit au vecteur du fournisseur
void Fournisseur::ajouterProduit(Produit * produit)
{
	contenuCatalogue_.push_back(produit);
}

//methode qui enleve un produit au vecteur du fournisseur
void Fournisseur::enleverProduit(Produit * produit)
{
	for (unsigned i = 0; i < contenuCatalogue_.size(); i++)
	{
		if (*contenuCatalogue_[i] == *produit)
		{
			contenuCatalogue_.erase(contenuCatalogue_.begin() + i);
		}
	}
}

//surcharge de l'operateur d'affectation
Fournisseur & Fournisseur::operator=(const Fournisseur & fournisseur)
{
	if (this != &fournisseur)
	{
		static_cast<Usager&> (*this) = fournisseur;
		
		for (unsigned i = 0; i < NIVEAUX_SATISFACTION; i++)
		{
			satisfaction_.niveaux_[i] = fournisseur.obtenirSatisfaction().niveaux_[i];
		}
		contenuCatalogue_ = fournisseur.obtenirCatalogue();
	}
	return *this;

}

//surcharge de l'operateur affichage
ostream & operator<<(ostream & os, Fournisseur & fournisseur)
{
	os << "Fournisseur: " << static_cast<Usager> (fournisseur) << endl;
	os << "\tNotes: " << endl;
	for (unsigned i = 0; i < NIVEAUX_SATISFACTION; i++)
	{
		os << "\t" << i << " : " << fournisseur.obtenirSatisfaction().niveaux_[i] << endl;
	}
	os << endl;
	return os;
}
