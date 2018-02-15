/********************************************
* Titre: Travail pratique #3 - Fournisseur.cpp
* Date: 
* Auteur:
*******************************************/
#include "Fournisseur.h"

Fournisseur::Fournisseur(const string & nom, const string & prenom, int identifiant, const string & codePostal) : Usager(nom, prenom, identifiant, codePostal)
{
	for (unsigned i = 0; i < NIVEAUX_SATISFACTION; i++)
	{
		satisfaction_.niveaux_[i] = 0;
	}
}

vector<Produit*> Fournisseur::obtenirCatalogue() const
{
	return contenuCatalogue_;
}

Satisfaction Fournisseur::obtenirSatisfaction() const
{
	return satisfaction_;
}

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

void Fournisseur::ajouterProduit(Produit * produit)
{
	contenuCatalogue_.push_back(produit);
}

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

ostream & operator<<(ostream & os, Fournisseur & fournisseur)
{
	// TODO: insérer une instruction return ici
	os << "Produit le plus cher " << static_cast<Produit> (fournisseur) << endl;
	os << "Fournisseur: " << static_cast<Usager> (fournisseur) << endl;
	os << "Notes: " << endl;
	for (unsigned i = 0; i < NIVEAUX_SATISFACTION; i++)
	{
		os << i << " : " << fournisseur.obtenirSatisfaction().niveaux_[i] << endl;
	}
	return os;
}
