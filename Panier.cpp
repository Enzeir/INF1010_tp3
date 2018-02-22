/********************************************
* Titre: Travail pratique #3 - Panier.cpp
* Date: 
* Auteur: 
*******************************************/

#include "Panier.h"
using namespace std;

Panier::Panier(int idClient) {
	// TODO
	totalAPayer_ = 0.0;
	idClient_ = idClient;
}


Panier::~Panier()
{
	contenuPanier_.clear();
}

// methodes d'accès
vector<Produit*>  Panier::obtenirContenuPanier()const
{
	return contenuPanier_;
}

int Panier::obtenirNombreContenu() const
{
	return (int)contenuPanier_.size();
}


int Panier::obtenirIdClient() const {
	return idClient_;
}

double Panier::obtenirTotalApayer() const {
	return totalAPayer_;
}


double Panier::calculerTotalApayer()  const
{
	 // TODO
	double total = 0;
	if (contenuPanier_.empty())
	{
		total = 0;
	}
	else
	{
		for (unsigned i = 0; i < contenuPanier_.size(); i++)
		{
			if (contenuPanier_[i]->retournerType() == TypeProduitAuxEncheres)
			{
				if (static_cast<ProduitAuxEncheres*>(contenuPanier_[i])->obtenirIdentifiantClient() 
					== idClient_)
				{
					total += contenuPanier_[i]->obtenirPrix();
				}
			}
		}
	}
	return total;
}



void Panier::modifierTotalAPayer(double totalAPayer)
{
	totalAPayer_ = totalAPayer;
}


void Panier::modifierIdClient(int idClient) {
	idClient_ = idClient;
}




void Panier::ajouter(Produit * prod)
{
	// TODO
	double prixTaxe = prod->obtenirPrix() + (prod->obtenirPrix() * TAUX_TAXE);
	if (static_cast<ProduitOrdinaire*> (prod)->obtenirEstTaxable())
	{
		prod->modifierPrix(prixTaxe);
	}
	contenuPanier_.push_back(prod);
}

void Panier::livrer()
{
	totalAPayer_ = 0;
	contenuPanier_.clear();
}

Produit* Panier::trouverProduitPlusCher()
{
	if (contenuPanier_.empty())
		return nullptr;

	Produit* prodPlusChere = contenuPanier_[0];
	for (unsigned int i = 1; i < contenuPanier_.size(); i++)
		if (*contenuPanier_[i] > *prodPlusChere)
			prodPlusChere = contenuPanier_[i];

	return prodPlusChere;
}

ostream & operator<<(ostream & os,  const Panier & panier)
{
	// TODO
	if (panier.contenuPanier_.empty())
	{
		os << "Votre Panier est vide" << endl;
	}
	else
	{
		for (unsigned i = 0; i < panier.contenuPanier_.size(); i++)
		{
			if (panier.contenuPanier_[i]->retournerType() == TypeProduitOrdinaire)
			{
				os << static_cast<ProduitOrdinaire*> (panier.contenuPanier_[i]);
			}
			if (panier.contenuPanier_[i]->retournerType() == TypeProduitAuxEncheres)
			{
				os << static_cast<ProduitAuxEncheres*> (panier.contenuPanier_[i]);
			}
		}
	}
	return os;	
}
