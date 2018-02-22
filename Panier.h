/********************************************
* Titre: Travail pratique #3 - Panier.h
* Date: 
* Auteur: 
*******************************************/

#ifndef PANIER_H
#define PANIER_H

#include <string>
#include <vector>
#include "Produit.h"
#include "ProduitOrdinaire.h"
#include "ProduitAuxEncheres.h"
const double TAUX_TAXE = 0.15;
using namespace std;
class Panier
{
public:
	
	//Constructeur par defaut
	Panier(int idClient);
	//destructeur par defaut
	~Panier();

	//Methode d'acces
	vector<Produit*>  obtenirContenuPanier()const;
	int obtenirNombreContenu() const;
	double obtenirTotalApayer() const;
	double calculerTotalApayer() const ;
	int obtenirIdClient() const;

	// Methode de modification
	void modifierTotalAPayer(double totalAPayer);
	void modifierIdClient(int idClient);

	//Methode qui ajoute un produit au vecteur de produit
	void ajouter(Produit * prod);
	//Methode vide et detruit le contenu du vecteur de produit
	void livrer();

	//Methode qui traverse tous les produits du vecteur et determine celui qui a le prix le plus elever
	Produit* trouverProduitPlusCher();
	//Surcharge d'operateur d'affichage
	friend ostream& operator<<(ostream& os, const Panier & panier);

private:
	double totalAPayer_;
	int idClient_;
	vector<Produit*> contenuPanier_;
	

};

#endif