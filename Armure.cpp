#include "Armure.h"

Armure::Armure(string name): Item(name)
{
    tuple<int, vector<const Role*>> tuple{ Constante::ARMURES.at(name) };
    m_classesAutorise = get<1>(tuple);
    m_defenseCoefBase = get<0>(tuple) + (m_rarity  * get<0>(tuple) * 0.35f);
}

Armure::Armure(string name, int rarity, int defense)
{
    m_name = name;
    m_rarity = rarity;
    m_defenseCoefBase = defense;
}

const int Armure::getDefense() const
{
    return m_defenseCoefBase;
}

const string Armure::getDescription() const
{
    string rareter{ Constante::RARETER_TAB[m_rarity] };
    string valeur(to_string(m_value));
    string defense(to_string(getDefense()));
    return string("[Armure]: " + m_name + " deffense[" + defense + "] " + rareter + " valeur: " + valeur + "$");
}

