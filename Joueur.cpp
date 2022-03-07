#include "Joueur.h"

Joueur::~Joueur()
{

}

Joueur::Joueur(string nom, const Role* classe) : Personnage(nom, 1)
{
	m_classe = classe;
	m_ressource = m_classe->ressourceMax;
	m_inventaire.clear();
}

const int Joueur::attaquer(Personnage& ennemi)
{
	int degats{ m_arme->getDommage() + m_attackTemp 
		+ m_attackPerm + m_classe->attackCoef };
	return ennemi.prendreDegats(degats);
}

const int Joueur::prendreDegats(const int& degatBrute)
{
	int finalDamage{ degatBrute - m_armure->getDefense()  -m_defensePerm 
		- m_classe->defenseCoef - m_defenseTemp };
	if (finalDamage < 0)
		finalDamage = 0;

	m_hp -= finalDamage;
	if (m_hp < 0)
		m_hp = 0;

	return finalDamage;
}


string Joueur::action(Personnage& ennemi, string index)
{
	if (m_classe->actions->at(index).recupRessources != 0)
	{
		m_ressource += m_classe->actions->at(index).recupRessources;
		if (m_ressource > m_classe->ressourceMax)
			m_ressource = m_classe->ressourceMax;

		return m_name + " recupere " + to_string(m_classe->actions->at(index).recupRessources) + " " + m_classe->nomRessource + "!";
	}

	if ((m_ressource  - m_classe->actions->at(index).depenseRessources) < 0)
		return "Niveau de " + m_classe->nomRessource + " trop bas.";

	m_ressource -= m_classe->actions->at(index).depenseRessources;

	if (m_classe->actions->at(index).recupHP > 0)
	{
		m_hp += m_classe->actions->at(index).recupHP;
		if (m_hp > m_hpBase)
			m_hp = m_hpBase;

		return m_name + " recupere " + to_string(m_classe->actions->at(index).recupRessources) + " hp!";
	}

	if (m_classe->actions->at(index).attackCoef != 0)
	{
		m_attackTemp += m_classe->actions->at(index).attackCoef;
		int damage{ attaquer(ennemi) };
		return m_name + " augmente son attaque de " + to_string(m_classe->actions->at(index).attackCoef) + " et attaque " + ennemi.getName() + " avec " + index + " pour " + to_string(damage) + " degats!";
	}

	if (m_classe->actions->at(index).defenseCoef != 0)
	{
		m_defenseTemp += m_classe->actions->at(index).defenseCoef;
		return m_name + " augmente sa defense de " + to_string(m_classe->actions->at(index).defenseCoef) + " points!";
	}

	return m_name + " fait " + index + "!";
}

bool Joueur::setArme(int& refInventaire)
{
	const bool  equipable{ estEquipable(refInventaire) };

	// Inventaire pointe oldArme as Item*
	// Arme pointe vers adresse inventaire as Arme*
	if (equipable) {
		Arme* newArmePtr{ dynamic_cast<Arme*>(m_inventaire[refInventaire]) };
		m_inventaire[refInventaire] = m_arme;
		m_arme = newArmePtr;
	}
	return equipable;
}

bool Joueur::setArmure(int& refInventaire)
{
	const bool  equipable{ estEquipable(refInventaire) };

	// Inventaire pointe oldArmure as Item*
	// Armure pointe vers adress inventaire newArmure as Armure*
	if (equipable) {
		Armure* newArmurePtr{ dynamic_cast<Armure*>(m_inventaire[refInventaire]) };
		m_inventaire[refInventaire] = m_armure;
		m_armure = newArmurePtr;
	}
	return equipable;
}

string Joueur::gainXP(int xp)
{
	m_xp += xp;
	string text{ m_name + " gagne " + to_string(xp) + " points d'experiences!\n" };
	if (m_xp > (1000 * m_level))
	{
		while (m_xp > (1000 * m_level) && m_level < 100)
		{
			m_xp -= getClasse()->tableXp[m_level-1];
			m_level += 1;
			if (m_level % 11 == 0 && m_classe->evolution != nullptr)
			{
				evolve();
				text += "Evolue en " + m_classe->name + "!\n";
			}
			m_hpBase += m_classe->hpPerLevel;
			m_ressource = getClasse()->ressourceMax;
			m_hp = m_hpBase;
		}

		text += "Niveau " + to_string(m_level) + " atteint!\n";
	}
	return text;
}

const Role* Joueur::evolve()
{
	m_classe = m_classe->evolution;
	return m_classe;
}

bool Joueur::takeItem(Item*& newItem)
{
	if (m_inventaire.size() >= 10)
		return false;

	m_inventaire.push_back(newItem);
	return true;
}

Item* Joueur::dropItem(int& index)
{
	Item* temp = m_inventaire[index];
	m_inventaire.erase(m_inventaire.begin() + index);
	return temp;
}

void Joueur::resetBuff()
{
	m_attackTemp = 0;
	m_defenseTemp = 0;
}

void Joueur::augmentAttack()
{
	m_attackPerm += Constante::ATTACK_AUGM;
}

void Joueur::augmentDefense()
{
	m_defensePerm += Constante::DEFENSE_AUGM;
}

const bool Joueur::estEquipable(int& refInventaire) const {
	auto classesItem
		{ m_inventaire[refInventaire]->getClassesAutorise() };

	if (classesItem.size() == 0)
		return true;

	bool valide{ false };
	for(auto classe : classesItem) {
		valide = classe->name == m_classe->name;
		if (valide) break;
	}

	return valide;
}

Item* Joueur::getItem(int& index) const
{
	return m_inventaire[index];
}

const Role* Joueur::getClasse() const
{
	return m_classe;
}

int Joueur::getRessource() const
{
	return m_ressource;
}

int Joueur::getRessourceMax() const
{
	return m_classe->ressourceMax;
}

Arme* Joueur::getArme() const
{
	return m_arme;
}

Armure* Joueur::getArmure() const
{
	return m_armure;
}

vector<Item*> Joueur::getInventaire() const
{
	return m_inventaire;
}

int Joueur::getAttackCoef() const
{
	return m_arme->getDommage() + m_classe->attackCoef + m_attackTemp + m_attackPerm;
}

int Joueur::getDefenseCoef() const
{
	return m_armure->getDefense() + m_classe->defenseCoef + m_defenseTemp + m_defensePerm;
}

int Joueur::getDommageBuff() const
{
	return m_attackTemp + m_attackPerm + m_classe->attackCoef;
}

int Joueur::getDefenseBuff() const
{
	return  m_defenseTemp + m_defensePerm + m_classe->defenseCoef;
}

const map<string, const Action> Joueur::getActions() const
{
	return *m_classe->actions;
}

bool Joueur::estAtkBufTemp() const
{
	return m_attackTemp > 0;
}

bool Joueur::estDefBufTemp() const
{
	return m_defenseTemp > 0;
}

void Joueur::recupHp()
{
	m_hp = m_hpBase;
}