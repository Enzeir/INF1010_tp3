/********************************************
* Titre: Travail pratique #3 - Produit.h
* Date: 
* Auteur: 
*******************************************/

#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
#include <iostream>
#include <typeinfo>
#include "Usager.h"
#include "Fournisseur.h"
class Fournisseur;

enum TypeProduit { TypeProduitOrdinaire = 0, TypeProduitAuxEncheres = 1 };

class Produit {

public:
	//constructeur par parametre de la classe produit
	Produit(Fournisseur& fournisseur, const string& nom ="outil", int reference = 0, 
		    double prix = 0.0, TypeProduit type = TypeProduitOrdinaire);
	//destructeur par defaut
	~Produit();
	
	//methode d'acces
	string obtenirNom() const;
	int obtenirReference() const;
	double obtenirPrix() const;
	Fournisseur & obtenirFournisseur() const;
	TypeProduit retournerType();

	//methode de modifications
	void modifierNom(const string& nom);
	void modifierReference(int reference);
	void modifierPrix(double prix);
		
	//surchage d'operateur
	bool operator > (const Produit& produit) const;
	bool operator <(const Produit& produit) const;
	bool operator ==(const Produit& produit) const;
	
	//surcharge d'operateur d'entree de valeur
	friend istream& operator>>(istream& is, Produit& produit);

	//surcharge d'operateur d'affichage
    friend ostream& operator<<(ostream& os, const Produit& produit);
   
private :
	string nom_;
	int reference_;
    double prix_;
	Fournisseur & fournisseur_;
	TypeProduit type_;

};
#endif 
