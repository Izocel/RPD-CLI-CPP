#ifndef ENNEMI_H
#define ENNEMI_H
#include "Personnage.h"
#include "Joueur.h"
#include "Utilities.h"
#include "Item.h"
#include "Constantes.h"

class Ennemi :
    public Personnage
{
private:
    unsigned int m_attackCoef{5};
    unsigned int m_deffenseCoef{1};
    mutable size_t m_slotDropVctr{ 50 };
    vector<Item*> m_dropVector{};

    /// <summary>
    /// Renvoit une valeur entre 0 et +uintMax des degat brutes moins la deffense.
    /// </summary>
    /// <param name="degatBrute">Les degats brutes</param>
    /// <returns>Le dommage recu reel</returns>
    const int calculDef(const int& degatBrute) const;

public:
    Ennemi();

    /// <summary>
    /// Permet d'obtenir un Ennemi deterministe.
    /// </summary>
    /// <param name="nom">Nom de l'ennemi</param>
    /// <param name="hp">HP de base</param>
    /// <param name="hpMax">HP max</param>
    /// <param name="niveau">Niveau de base</param>
    Ennemi(const string nom, const int hp, const int hpMax, const int niveau);

    /// <summary>
    /// Permet d'obtenir un Ennemi selon la BASE_MAP et la rareter.
    /// Augmente ces "stats" selon le niveau.
    /// </summary>
    /// <param name="nom">Le nom present dans la MAP</param>
    /// <param name="rareter">La rareter dont il fait partie.</param>
    /// <param name="niveau">Le niveau a attribuer</param>
    /// <exception cref="std::exception">Si l'ennemi n'existe pas dans une BASE_MAP</exception>
    Ennemi(const string nom, const string rareter, const int niveau);
    ~Ennemi();

    /// <summary>
    /// Applique vecteurItem au dropVector de l'ennemi.
    /// </summary>
    /// <param name="vecteurItem">Le vecteur a appliquer</param>
    /// <exception cref="std::length_error">Sera lancer si vecteurItem > m_slotDropVctr</exception>
    void setDropItem(vector<Item*>& vecteurItem);


    // Operateur d'assignation (deep copy) instance sur instance
    Ennemi& operator=(const Ennemi& rhs);

    
    /// <summary>
    /// Permet d'attaquer un Joueur
    /// </summary>
    /// <param name="refJoueur">Le joueur a attaquer</param>
    /// <returns>Les dommages r�el subit</returns>
    const int attaquer(Personnage& refJoueur);

    /// <summary>
    /// Permet de recevoir des degats brute et les convertie en d�gat reel.
    /// </summary>
    /// <param name="degatBrute">Les points de degat brute</param>
    /// <returns>Les degat reel subit</returns>
    const int prendreDegats(const int& degatBrute);

    /// <summary>
    /// Renvoit le vecteur d'items a laisser derriere
    /// </summary>
    /// <returns>Le vecteur Item</returns>
    vector<Item*> getDrop() const;

    unsigned int getAttackCoef() const;

    unsigned int getDefenseCoef() const;
};

#endif