/********************************************
* Titre: Travail pratique #3 - Client.h
* Date: 
* Auteur: 
*******************************************/

#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "Usager.h"
#include "Panier.h"
#include "ProduitOrdinaire.h"
#include "ProduitAuxEncheres.h"

using namespace std;
class Client : public Usager
{

public:
	//constructeur par parametre
	Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date);
	//destructeur par defaut
	~Client();
	//constructeur par copie
	Client(const Client& client);
	
	//methode d'accee
	long obtenirDateNaissance() const;
	Panier* obtenirPanier() const;

	//methode de modification
	void modifierDateNaissance(long date);

	// methode qui ajoute un produit au panier du client
	void acheter(ProduitOrdinaire * prod);
	//methode qui vide le panier d'un client
	void livrerPanier();
	//methode qui verifie la mise d'un client et ajoute le produit au panier si elle est plus elever que le prix actuel du produit.
	void miserProduit(ProduitAuxEncheres* produitAuxEncheres, double montantMise);

	//surcharge d'operateur d'affection
	Client& operator=(const Client& client);
	//surcharge d'operateur d'affichage
	friend ostream& operator<<(ostream& os, const Client& client);

private:
	long dateNaissance_;
	Panier *  monPanier_;

};

#endif