/********************************************
* Titre: Travail pratique #3 - Fournisseur.h
* Date: 
* Auteur: 
*******************************************/

#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
const int NIVEAUX_SATISFACTION = 5;
struct Satisfaction {
	int niveaux_[NIVEAUX_SATISFACTION];
};

#include <string>
#include <vector>
#include "Usager.h"
#include "Produit.h"
using namespace std;
class Produit;
class Fournisseur : public Usager
{
public:
	//constructeur par parametre
	Fournisseur(const string&  nom, const string& prenom, int identifiant, const string& codePostal);
	//methodes d'accees
	vector<Produit*> obtenirCatalogue() const;
	Satisfaction obtenirSatisfaction() const;
	//methode de modification
	void modifierSatisfaction(Satisfaction satisfaction);	
	void noter(int appreciation);
	//methode qui ajoute un produit au vecteur du fournisseur
	void ajouterProduit(Produit* produit);
	//methode qui enleve un produit au vecteur du fournisseur
	void enleverProduit(Produit* produit);
	//surcharge de l'operateur d'affectation
	Fournisseur& operator=(const Fournisseur& fournisseur);
	//surcharge de l'operateur affichage
	friend ostream& operator<<(ostream & os, Fournisseur& fournisseur);

private:
	Satisfaction satisfaction_;
	vector<Produit*> contenuCatalogue_;	
};

#endif