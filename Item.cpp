#include "Item.h"

Item::Item(string nom) :
    m_name{nom},
    m_rarity{ Utilities::random_number(0,4) },
    m_value{ setValueByRarity()},
    m_dropRate{ setDropRateByRarity() }
{}

Item::Item(string nom, int rareter) :
    m_name{ nom },
    m_rarity{ rareter },
    m_value{ setValueByRarity() },
    m_dropRate{ setDropRateByRarity() }
{}

Item::~Item()
{
}

const float Item::setDropRateByRarity() {

    // fx = a1 * ( x^(-e) /n )
    const float num = pow(m_rarity + 1.00f, -0.80f) / Constante::RARETER_TAB_SIZE;
    return 1.25f * num;
}

const unsigned int Item::setValueByRarity() {
    return (m_rarity + 1) * 10;
}

string Item::getName() const
{
    return m_name;
}

unsigned int Item::getRarity() const
{
    return m_rarity;
}

unsigned int Item::getValue() const
{
    return m_value;
}

const vector<const Role*> Item::getClassesAutorise() const
{
    return m_classesAutorise;
}

const float Item::getDropRate() const
{
    return m_dropRate;
}

string Item::rolesToString() const
{
    string noms;
    for(const Role* role : m_classesAutorise)
        noms += role->name + " ";

    if(noms.empty())
        return "[ Tous ]";
    return "[ " + noms + "]";
}

string Item::getDescription()
{
    string rareter{ Constante::RARETER_TAB[m_rarity] };
    string valeur(to_string(m_value));
    return string("[Item]: "+ m_name + " " + rareter + " valeur: " + valeur + "$");
}
