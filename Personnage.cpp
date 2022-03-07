#include "Personnage.h"

Personnage::Personnage()
{
}

Personnage::Personnage(const string nom, const unsigned int hp, const unsigned int hpMax, const int niveau)
    : m_name{ nom }, m_hpBase{ hpMax }, m_hp{ int(hp) }, m_level{ niveau } {}

Personnage::Personnage(const string nom, const int niveau): 
    m_name{nom}, m_level{niveau} {}

Personnage::~Personnage()
{
}

const int Personnage::attaquer(Personnage& ennemi)
{
    return 0;
}

const int Personnage::prendreDegats(const int& degatBrute)
{
    const int vieRestant = m_hp - degatBrute;
    m_hp = vieRestant >= 0 ? vieRestant : 0;
    return degatBrute;
}

string Personnage::getName() const
{
    return m_name;
}

int Personnage::getXp() const
{
    return m_xp;
}

unsigned int Personnage::getLevel() const
{
    return m_level;
}

int Personnage::getHp() const
{
    return m_hp;
}

unsigned int Personnage::getHpBase() const
{
    return m_hpBase;
}

const bool Personnage::estVivant() const
{
    return m_hp > 0;
}
