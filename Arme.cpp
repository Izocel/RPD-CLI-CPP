#include "Arme.h"

Arme::Arme(string nom, int minAtk, int maxAtk) :
    Item(nom), m_minBase{ minAtk * m_rarity + 1 }, m_maxBase{ maxAtk * m_rarity + 1 } {}

Arme::Arme(string nom, int rareter) :
    Item(nom, rareter)
{
    // Utilise les bases ARMES
    std::tuple<int, int, vector<const Role*>> valeurTuple;
    try
    {
        // Determine les valeurs selon la base de l'arme par le nom
        valeurTuple = Constante::ARMEBASE_MAP.at(m_name);
    }
    catch (const std::exception&)
    {
        throw exception{ "Cette arme n'existe pas." };
    }

    m_minBase = get<0>(valeurTuple) + (m_rarity * get<0>(valeurTuple) * 0.65f);
    m_maxBase = get<1>(valeurTuple) + (m_rarity * get<1>(valeurTuple) * 0.65f);
    m_classesAutorise = get<2>(valeurTuple);
}

Arme::Arme(string nom, int rareter, int minAtk, int maxAtk) :
    Item(nom, rareter), m_minBase{ minAtk * m_rarity }, m_maxBase{ maxAtk * m_rarity }
{}

Arme::~Arme()
{
}

const int Arme::getDommage() const
{
    return Utilities::random_number(m_minBase, m_maxBase+1);
}

const int Arme::getMinDommage()
{
    return m_minBase;
}

const int Arme::getMaxDommage()
{
    return m_maxBase;
}

string Arme::getDescription()
{
    string rareter{ Constante::RARETER_TAB[m_rarity] };
    string valeur(to_string(m_value));
    string atkMin(to_string(m_minBase));
    string atkMax(to_string(m_maxBase));
    return string("[Arme]:   " + m_name + " dommage[" + atkMin + "-" + atkMax + "] " + rareter + " valeur: " + valeur + "$");
}

