#ifndef ITEM_H
#define ITEM_H
#include "Utilities.h"
#include "Constantes.h"
#include "Role.h"

class Item
{

protected:

	std::string m_name{"Default"};
	int m_rarity{0};
	unsigned int m_value{0};
	float m_dropRate{0.0f};
	vector<const Role*> m_classesAutorise{};
	

	/// <summary>
	/// Determine la valeur de l'item selon ca rereter
	/// </summary>
	/// <returns>La valeur $$</returns>
	const unsigned int setValueByRarity();
	
	/// <summary>
	/// Fonction déterminant le drop rate selon la rareter.
	/// En réduisant l'exposant on augmente la chance de drop (pourrait etre utiliser avec le niveau du joueur)
	/// Modele : f1(x)= 1-(x^(0.35)-0.95)
	/// </summary>
	const float setDropRateByRarity();

public:

	Item() = default;

	/// <summary>
	/// Permet d'obtenir un Item non-deterministe.
	/// </summary>
	/// <param name="nom">Le nom de l'item</param>
	Item(string nom);

	/// <summary>
	/// Permet d'obtenir un Item deterministe par la rareter.
	/// </summary>
	/// <param name="nom">Le nom de l'item</param>
	/// <param name="rareter">La rareter de l'item</param>
	Item(string nom, int rareter);

	~Item();
	
	/// <summary>
	/// Renvoit le nom de l'item.
	/// </summary>
	/// <returns>Le nom</returns>
	string getName() const;

	/// <summary>
	/// Renvoit la rareter de l'item.
	/// </summary>
	/// <returns>La rareter</returns>
	unsigned int getRarity() const;

	/// <summary>
	/// Renvoit la valeur de l'item.
	/// </summary>
	/// <returns>Le valeur de l'item</returns>
	unsigned int getValue() const;

	/// <summary>
	/// Renvoit la liste des Roles autoriser pour l'item.
	/// Vide pour aucune restriction...
	/// </summary>
	/// <returns>Un vecteur de Role*</returns>
	virtual const vector<const Role*> getClassesAutorise() const;

	/// <summary>
	/// Renvoit le ratio chance d'etre laisser derriere entre 0-1
	/// </summary>
	/// <returns>Le ratio</returns>
	const float getDropRate() const;

	/// <summary>
	/// Retourne le nom des classes autorisees ou "Tous"
	/// </summary>
	/// <returns>La chaine des roles autorises</returns>
	virtual string rolesToString() const;

	/// <summary>
	/// Renvoit la description de l'item en chaine de charactere.
	/// </summary>
	virtual string getDescription();
	
};

#endif