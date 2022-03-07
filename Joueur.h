#pragma once
#include "Personnage.h"
#include "Ennemi.h"
#include "Role.h"
#include "Item.h"
#include "Arme.h"
#include "Armure.h"
#include "Action.h"
#include "Utilities.h"

class Joueur :
    public Personnage
{
private:
    const Role* m_classe;
    int m_ressource;
    Arme* m_arme{ new Arme() };
    Armure* m_armure{ new Armure() };
    vector<Item*> m_inventaire{ vector<Item*>(10)};
    int m_attackTemp{0};
    int m_defenseTemp{0};
    int m_attackPerm{ 0 };
    int m_defensePerm{ 0 };

public:
    /// <summary>
    /// Constructeur de joueur vide
    /// </summary>
    Joueur() = default;

    ~Joueur();

    /// <summary>
    /// Constructeur du joueur
    /// </summary>
    /// <param name="nom">Nom du joueur</param>
    /// <param name="classe">Classe du joueur</param>
    Joueur(string nom, const Role* classe);

    /// <summary>
    /// Attaque un ennemi
    /// </summary>
    /// <param name="ennemi">L'ennemi � attaquer</param>
    /// <returns>Le nombre de d�gats inflig�s</returns>
    const int attaquer(Personnage& ennemi);

    /// <summary>
    /// Fait une action du role du personnage sur l'ennemi 
    /// </summary>
    /// <param name="ennemi">L'ennemi vis�</param>
    /// <param name="index">Index de l'action voulue</param>
    /// <returns>L'action faite</returns>
    string action(Personnage& ennemi, string index);

    /// <summary>
    /// Prends les d�gats inflig�s
    /// </summary>
    /// <param name="damage">Les d�gats</param>
    /// <returns>Les degats recus</returns>
    const int prendreDegats(const int& degatBrute);

    /// <summary>
    /// Permet d'équiper une arme de l'inventaire si le role convient.
    /// Hint: Permutation d'adresses mémoire.
    /// </summary>
    /// <returns>Si l'arme est bien equiper</returns>
    bool setArme(int& refInventaire);
    
    /// <summary>
    /// Permet d'équiper une armure de l'inventaire si le role convient.
    /// Hint: Permutation d'adresses mémoire.
    /// </summary>
    /// <returns>Si l'armure est bien equiper</returns>
    bool setArmure(int& refInventaire);

    /// <summary>
    /// Prend de l'xp et v�rifie s'il y a mont�e de niveau
    /// </summary>
    /// <param name="xp">L'xp gagn�e</param>
    /// <returns>Un string décrivant le gain d'xp</returns>
    string gainXP(int xp);

    /// <summary>
    /// �volue dans la classe suivant la classe du joueur
    /// </summary>
    /// <returns>La nouvelle classe</returns>
    const Role* evolve();

    /// <summary>
    /// Prends un item dans l'inventaire si celui-ci n'est pas plein
    /// </summary>
    /// <param name="newItem">Le nouvel item</param>
    /// <returns>True si l'item a �t� pris, false si l'inventaire est plein</returns>
    bool takeItem(Item*& newItem);

    /// <summary>
    /// Drop l'item dans l'index demand�
    /// </summary>
    /// <param name="index">Index demand�</param>
    /// <returns>L'item drop�</returns>
    Item* dropItem(int& index);

    /// <summary>
    /// Reset les buffs du joueur
    /// </summary>
    void resetBuff();

    /// <summary>
    /// Augmente l'attaque permanente du joueur
    /// </summary>
    void augmentAttack();

    /// <summary>
    /// Augmente la défense permanente du joueur
    /// </summary>
    void augmentDefense();

    const bool estEquipable(int& refInventaire) const;

    /// <summary>
    /// Retourne la valeur de l'item dans l'index d'inventaire demand�
    /// </summary>
    /// <param name="index">Index demand�</param>
    /// <returns>L'item</returns>
    Item* getItem(int& index) const;

    int getRessource() const;
    int getRessourceMax() const;
    const Role* getClasse() const;
    Arme* getArme() const;
    Armure* getArmure() const;
    vector<Item*> getInventaire() const;
    int getAttackCoef() const;
    int getDefenseCoef() const;
    int getDommageBuff() const;
    int getDefenseBuff() const;
    bool estAtkBufTemp() const;
    bool estDefBufTemp() const;
    void recupHp();
    const map<string, const Action> getActions() const;

};

