/********************************************
* Titre: Travail pratique #3 - Panier.cpp
* Date: 
* Auteur: 
*******************************************/

#include "Panier.h"
using namespace std;

//Constructeur par defaut
Panier::Panier(int idClient) {
	totalAPayer_ = 0.0;
	idClient_ = idClient;
}

//destructeur par defaut
Panier::~Panier()
{
	contenuPanier_.clear();
}

//Methode d'acces

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
			if (contenuPanier_[i]->retournerType() == TypeProduitOrdinaire)
			{
				total += contenuPanier_[i]->obtenirPrix();
			}
		}
	}
	return total;
}


// Methode de modification
void Panier::modifierTotalAPayer(double totalAPayer)
{

	totalAPayer_ = totalAPayer;
}


void Panier::modifierIdClient(int idClient) {
	idClient_ = idClient;
}



//Methode qui ajoute un produit au vecteur de produit
void Panier::ajouter(Produit * prod)
{
	double prixTaxe = prod->obtenirPrix() + (prod->obtenirPrix() * TAUX_TAXE);
	if (static_cast<ProduitOrdinaire*> (prod)->obtenirEstTaxable())
	{
		totalAPayer_ += prixTaxe;
	}
	contenuPanier_.push_back(prod);
}

//Methode vide et detruit le contenu du vecteur de produit
void Panier::livrer()
{
	totalAPayer_ = 0;
	contenuPanier_.clear();
}

//Methode qui traverse tous les produits du vecteur et determine celui qui a le prix le plus elever
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

//Surcharge d'operateur d'affichage
ostream & operator<<(ostream & os,  const Panier & panier)
{
	if (panier.contenuPanier_.empty())
	{
		os << "Votre Panier est vide!" << endl;
	}
	else
	{
		for (unsigned i = 0; i < panier.contenuPanier_.size(); i++)
		{
			if (panier.contenuPanier_[i]->retournerType() == TypeProduitOrdinaire)
			{
				os << "------------------------------------------" << endl;
				os << "Produit Ordinaire: ";
				os << *static_cast<ProduitOrdinaire*> (panier.contenuPanier_[i]);

			}
			if (panier.contenuPanier_[i]->retournerType() == TypeProduitAuxEncheres)
			{
				os << "------------------------------------------" << endl;
				os << "Produit Aux Enchere: ";
				os << *static_cast<ProduitAuxEncheres*> (panier.contenuPanier_[i]);
			}
		}
	}
	os << "*********************************************************" << endl;
	os << "----> Total a Payer: " << panier.calculerTotalApayer() << endl;
	os << "*********************************************************" << endl;
	return os;	
}
