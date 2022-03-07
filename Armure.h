#pragma once
#include "Item.h"
#include "Utilities.h"
#include "Constantes.h"

class Armure :
    public Item
{
private:
    int m_defenseCoefBase{0};

public:
    /// <summary>
    /// Constructeur d'armure vide
    /// </summary>
    Armure() = default;

    /// <summary>
    /// Constructeur d'armure 
    /// </summary>
    Armure(string name);

    /// <summary>
    /// Constructeur d'armure
    /// </summary>
    /// <param name="name"></param>
    /// <param name="rarity"></param>
    /// <param name="defense"></param>
    Armure(string name, int rarity, int defense);

    /// <summary>
    /// Renvoit la defense de l'armure.
    /// </summary>
    const int getDefense() const;

    /// <summary>
    /// Renvoit la description de l'armure en chaine de charactere.
    /// </summary>
    const string getDescription() const;
};

