#ifndef ARME_H
#define ARME_H
#include "Item.h"
#include "Utilities.h"
#include "Constantes.h"

class Arme :
    public Item
{
private:
    int m_minBase{ 1 };
    int m_maxBase{ 10 };

public:

    Arme() = default;

    /// <summary>
    /// Permet d'obtenir une Arme de BASE_MAP et de lui appliquer une rareter.
    /// </summary>
    /// <param name="nom">Le nom inscrit dans la MAP</param>
    /// <param name="rareter">La rareter</param>
    /// <exception cref="std::exception">Si le nom n'est pas dans la MAP</exception>
    Arme(string nom, int rareter);

    /// <summary>
    /// Permet d'obtenir une nouvelle Arme avec rareter au hasard et atk deterministe.
    /// </summary>
    /// <param name="nom">Le nom a donner a l'arme</param>
    /// <param name="minAtk">L'atk minimum</param>
    /// <param name="maxAtk">L'atk maximum</param>
    Arme(string nom, int minAtk, int maxAtk);

    /// <summary>
    /// Permet d'obtenir une nouvelle Arme deterministe.
    /// </summary>
    /// <param name="nom">Le nom de l'arme</param>
    /// <param name="rareter">L'indice de rareter</param>
    /// <param name="minAtk">L'atk minimum</param>
    /// <param name="maxAtk">L'atk maximum</param>
    Arme(string nom, int rareter, int minAtk, int maxAtk);

    ~Arme();

    /// <summary>
    /// Lance et retourne le hasard dommage selon minMaxAtk.
    /// </summary>
    /// <returns>Le resultat du "lancer"</returns>
    const int getDommage() const;

    /// <summary>
    /// Renvoit le dommage minimum de l'arme.
    /// </summary>
    const int getMinDommage();

    /// <summary>
    /// Renvoit le dommage maximum de l'arme.
    /// </summary>
    const int getMaxDommage();

    /// <summary>
    /// Renvoit la description de l'arme en chaine de charactere.
    /// </summary>
    string getDescription();

};


#endif