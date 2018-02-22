/********************************************
* Titre: Travail pratique #3 - Client.cpp
* Date: 
* Auteur: 
*******************************************/

#include "Client.h"
#include "Fournisseur.h"


Client::Client(const string & nom, const string & prenom, int identifiant, const string & codePostal, long date) : Usager(nom, prenom, identifiant, codePostal)
{
	dateNaissance_ = date;
	monPanier_ = nullptr;
}

Client::~Client()
{
	if (monPanier_ != nullptr)
		delete monPanier_;
}

Client::Client(const Client & client) :
	Usager(client.obtenirNom(), client.obtenirPrenom(), client.obtenirIdentifiant(), client.obtenirCodePostal()),	
	dateNaissance_{ client.dateNaissance_ }
{
	if (client.monPanier_ == nullptr)
		monPanier_ = nullptr;
	else {
		monPanier_ = new Panier(client.obtenirIdentifiant());
		for (int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++) {
			monPanier_->ajouter(client.monPanier_->obtenirContenuPanier()[i]);
		}
		int idClient = this->obtenirIdentifiant();
		monPanier_->modifierTotalAPayer(client.monPanier_->obtenirTotalApayer());
	}
}


// Methodes d'acces
long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}

Panier * Client::obtenirPanier() const
{
	return monPanier_;
}


// Methodes de modification
void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

// Autres méthodes
void Client::acheter(ProduitOrdinaire * prod)
{
	if (monPanier_ == nullptr)
		monPanier_ = new Panier(this->obtenirIdentifiant());
	monPanier_->ajouter(prod);
	// obtenir une note aléatoire
	int note = rand() % NIVEAUX_SATISFACTION;
	// faire la mise à jour de la satisfaction au fournisseur
	prod->obtenirFournisseur().noter(note);
}

void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
	monPanier_ = nullptr;
}


void Client::miserProduit(ProduitAuxEncheres* produitAuxEncheres, double montantMise) {
	// à faire
	if (produitAuxEncheres->obtenirPrixBase() < montantMise)
	{
		produitAuxEncheres->modifierPrix(montantMise);
		produitAuxEncheres->modifierIdentifiantClient(this->obtenirIdentifiant());
		if (monPanier_ == nullptr)
		{
			monPanier_->ajouter(produitAuxEncheres);
		}
	}
}

Client & Client::operator=(const Client & client)
{
	if (this != &client) {
		Usager temp(*this);
		temp = static_cast<Usager> (client);
		dateNaissance_ = client.obtenirDateNaissance();
		if (client.monPanier_ != nullptr) {
			delete monPanier_;
			monPanier_ = new Panier(obtenirIdentifiant());
			for (int i = 0; i < client.monPanier_->obtenirNombreContenu(); i++) {
				monPanier_->ajouter(client.monPanier_->obtenirContenuPanier()[i]);
			}
		}
		else
			monPanier_ = nullptr;
	}
	return *this;
}


ostream & operator<<(ostream & os, const Client & client)
{
	// à faire
	if (client.monPanier_ == nullptr)
	{
		os << "Mr./Mme." << client.obtenirNom() <<  ", votre Panier est vide!" << endl;
	}
	else
	{
		os << *client.monPanier_ << endl;
	}
	return os;
}
