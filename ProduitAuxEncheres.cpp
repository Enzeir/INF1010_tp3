/********************************************
* Titre: Travail pratique #3 - ProduitAuxEncheres.cpp
* Date: 
* Auteur:
*******************************************/

#include "ProduitAuxEncheres.h"

ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur & fournisseur, const string & nom, int reference, double prix, TypeProduit type) : Produit(fournisseur, nom, reference, prix, type)
{
	prixBase_ = 0;
	identifiantClient_ = 0;
}

int ProduitAuxEncheres::obtenirIdentifiantClient() const
{
	return identifiantClient_;
}

double ProduitAuxEncheres::obtenirPrixBase() const
{
	return prixBase_;
}

void ProduitAuxEncheres::modifierIdentifiantClient(int identifiantClient)
{
	identifiantClient_ = identifiantClient;
}

void ProduitAuxEncheres::modifierPrixBase(double prixBase)
{
	prixBase_ = prixBase;
}

istream & operator>>(istream & is, ProduitAuxEncheres & produit)
{
	// TODO: insérer une instruction return ici
	return is >> static_cast<Produit> (produit) >> produit.prixBase_ >> produit.identifiantClient_;
}

ostream & operator<<(ostream & os, const ProduitAuxEncheres & produit)
{
	// TODO: insérer une instruction return ici
	os << "nom: " << produit.obtenirNom() << endl;
	os << "ref: " << produit.obtenirReference() << endl;
	os << "prix actuel: " << produit.obtenirPrix() << endl;
	os << "Fournisseur: " << produit.obtenirFournisseur() << endl;
	os << "Prix de Base: " << produit.obtenirPrixBase() << endl;
	os << "Identifiant Client: " << produit.obtenirIdentifiantClient() << endl;
	return os;
}
