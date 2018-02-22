/********************************************
* Titre: Travail pratique #3 - ProduitOrdinaire.h
* Date: 
* Auteur:
*******************************************/


#include <string>
#include <iostream>
#include "ProduitOrdinaire.h"
#include "Fournisseur.h"
using namespace std;

ProduitOrdinaire::ProduitOrdinaire(Fournisseur & fournisseur, const string & nom, int reference, double prix, TypeProduit type, bool estTaxable) : Produit(fournisseur, nom, reference, prix, type)
{
	estTaxable_ = estTaxable;
}

ProduitOrdinaire::~ProduitOrdinaire()
{
}

bool ProduitOrdinaire::obtenirEstTaxable() const
{
	return estTaxable_;
}

void ProduitOrdinaire::modifierEstTaxable(bool estTaxable)
{
	estTaxable_ = estTaxable;
}

ostream & operator<<(ostream & os, const ProduitOrdinaire & produit)
{
	os << static_cast<Produit>(produit) << endl;
	os << "\test Taxable: " << boolalpha;
	os << produit.obtenirEstTaxable() << endl << endl;
	return os;
}

istream & operator>>(istream & is, ProduitOrdinaire & produit)
{
	return is >> static_cast<Produit> (produit) >> produit.estTaxable_;
}
