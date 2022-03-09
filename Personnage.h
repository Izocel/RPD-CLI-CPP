#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include "Utilities.h"

class Personnage
{
protected:
	string m_name{"Personnage"};
	int m_xp{0};
	int m_level{1};
	unsigned int m_hpBase{100};
	int m_hp{ int(m_hpBase) };


	Personnage();
	// Constructeur parametrique: Initialisation membre par paramêtre
	Personnage(const string nom, const unsigned int hp, const unsigned int hpMax, const int niveau);
	Personnage(const string nom, const int niveau);

public:

	~Personnage();

	/// <summary>
	/// Permet l'héritage de la méthode doit être implémenter sur les enfants.
	/// </summary>
	/// <returns>0</returns>
	virtual const int attaquer(Personnage& ennemi);

	/// <summary>
	/// Permet de recevoir des degats brute.
	/// </summary>
	/// <param name="degat">Les points de degat brute</param>
	/// <returns>Les dégat subit</returns>
	virtual const int prendreDegats(const int& degatBrute);

	/// <summary>
	/// Renvoit le nom du personnage.
	/// </summary>
	/// <returns>Le nom</returns>
	string getName() const;

	/// <summary>
	/// Renvoit l'xp actuel du personnage.
	/// </summary>
	/// <returns>L'xp actuel</returns>
	int getXp()const;

	/// <summary>
	/// Retourne le niveau actuel du personnage.
	/// </summary>
	/// <returns>Le niveau</returns>
	unsigned int getLevel() const;

	/// <summary>
	/// Renvoit les points de vie actuel du personnage.
	/// </summary>
	/// <returns>Les points de vie</returns>
	int getHp() const;

	/// <summary>
	/// Renvoit la quantite maximum des points de vie.
	/// </summary>
	/// <returns>Les pv maximum</returns>
	unsigned int getHpBase() const;

	/// <summary>
	/// Renvoit true si le personnage a >=1 point de vie
	/// </summary>
	/// <returns>True si est vivant, sinon false</returns>
	const bool estVivant() const;


};

#endif