#include "Ennemi.h"

Ennemi::Ennemi(){

}
Ennemi::Ennemi(const string nom, const int hp, const int hpMax, const int niveau) : 
    Personnage(nom, hp, hpMax, niveau)
{
}

Ennemi::Ennemi(const string nom, const string rareter, const int niveau) : 
    Personnage(nom, niveau)
{
    // Utilise les bases ENNEMI
    std::tuple<int,int,int> valeurTuple;

    try
    {
        //Determine sur quelle MAP chercher la base ENNEMI
        if (rareter == "Commun") {
            valeurTuple = Constante::ENNEMICOMMUN_ATKDEFHP_MAP.at(m_name);
        }
        else if (rareter == "Rare") {
            valeurTuple = Constante::ENNEMIRARE_ATKDEFHP_MAP.at(m_name);
        }
    }
    catch (const std::exception&)
    {
        throw exception("Cet ennemi n'existe pas.");
    }


    m_attackCoef = get<0>(valeurTuple) + ((m_level-1) * get<0>(valeurTuple) * 0.75f);
    m_deffenseCoef = get<1>(valeurTuple) + ((m_level - 1) * get<1>(valeurTuple) * 0.37f);
    m_hpBase = get<2>(valeurTuple) + ((m_level - 1) * get<2>(valeurTuple) * 0.55f);
    m_hp = m_hpBase;
}

Ennemi::~Ennemi() {

}

Ennemi& Ennemi::operator=(const Ennemi& rhs)
{
    memcpy(this, &rhs, sizeof(Ennemi));
    return *this;
}


void Ennemi::setDropItem(vector<Item*>& vecteurItem)
{
    const size_t espaceVctr = m_slotDropVctr - vecteurItem.size();
    if (espaceVctr < 0)
        throw length_error("\nLe vecteur de drop est trop petit");

    m_dropVector = vecteurItem;
}

const int Ennemi::calculDef(const int& degatBrute) const
{
    int degats = degatBrute - m_deffenseCoef;
    return  degats >= 0 ? degats : 0;
}

const int Ennemi::attaquer(Personnage& refJoueur)
{
    return refJoueur.prendreDegats(m_attackCoef);
}

const int Ennemi::prendreDegats(const int& degatBrute)
{
    int degatRecu{ calculDef(degatBrute) };
    int vieRestant = m_hp - degatRecu;
    m_hp = vieRestant >= 0 ? vieRestant : 0;

    if (degatRecu < 0)
        getchar();

    return degatRecu;
}

vector<Item*> Ennemi::getDrop() const
{
    return m_dropVector;
}

unsigned int Ennemi::getAttackCoef() const
{
    return m_attackCoef;
}

unsigned int Ennemi::getDefenseCoef() const
{
    return m_deffenseCoef;
}