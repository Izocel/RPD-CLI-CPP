#ifndef MAIN_H
#define MAIN_H

#include "Joueur.h"
#include "Ennemi.h"
#include "Constantes.h"

/// <summary>
/// Affichage du statut des acteurs du jeu
/// </summary>
/// <param name="joueur">Le joueur</param>
/// <param name="ennemi">L'ennemi</param>
/// <param name="action">L'action</param>
/// <returns>Le texte de l'affichage</returns>
string affichageCombat(Joueur& joueur, Ennemi& ennemi, string action);

int menuJoueur(Joueur& joueur, string action);

/// <summary>
/// D�finit le joueur en d�but de partie selon les entr�es utilisateur
/// </summary>
/// <returns>Le nouveau joueur</returns>
Joueur debutPartie();

/// <summary>
/// Prend le choix du joueur entre la valeur min et la valeur max(inclu)
/// </summary>
/// <param name="min">Le minimum</param>
/// <param name="max">Le maximum</param>
/// <returns></returns>
int prendreChoix(int min, int max);

template <typename T, typename R>
/// <summary>
/// Retourne toutes les cl�s d'une map dans un vecteur
/// </summary>
/// <param name="map">la map</param>
/// <returns>Le vecteur</returns>
vector<T> vectorKeys(const map<T, R> map);

/// <summary>
/// Fonction pour g�rer le loot d'un ennemi apres un combat
/// </summary>
void gestionLoot(Joueur& joueur, vector<Item*> loot);

/// <summary>
/// Loop de la partie
/// </summary>
void gameLoop();

/// <summary>
/// Fait le combat entre le joueur et l'ennemi
/// </summary>
/// <param name="joueur"></param>
void combat(Joueur& joueur);

/// <summary>
/// Genere un ennemi aleatoire selon le nivea du joueur.
/// Il Ppeut etre jusqu'a +-3 niveau du joueur.
/// Si le niveau du joueur est un diviseur de 5 -> ennemi Rare
/// </summary>
/// <param name="niveauJoueur">Le niveau du joueur</param>
/// <returns>L'ennemi generer</returns>
Ennemi genererEnnemi(unsigned int& niveauJoueur);

/// <summary>
/// Calcule l'xp que le joueur re�oit d'un ennemi
/// </summary>
/// <param name="joueur"></param>
/// <param name="ennemi"></param>
/// <returns></returns>
int calculXP(int joueur, int ennemi);

/// <summary>
/// Affiche un petit texte avec delai simulat la fouille d'un ennemi.
/// </summary>
/// <param name="lootSize">La quantite laisser par l'ennemi</param>
void introGestionLoot(size_t& lootSize);


/// <summary>
/// Affiche un vecteur d'item en ligne sur la console.
/// Utilise la méthode respective selon la classe de l'item.
/// </summary>
/// <param name="vctrItem">Le vecteur d'Item*</param>
/// <param name="size">La quantite d'item contenu</param>
void afficherVecteurItem(vector<Item*>& vctrItem);

/// <summary>
/// Determine la classe de l'item.
/// </summary>
/// <param name="itemPtr">Un pointeur de classe Item</param>
/// <returns>La classe de l'item en string</returns>
string typeOfItem(Item*& itemPtr);

/// <summary>
/// Renvoit une Arme grace a un pointeur Item
/// </summary>
/// <param name="armePtr">Le pointeur Item de nature Arme</param>
/// <returns>Une Arme</returns>
Arme itemAsArme(Item*& armePtr);

/// <summary>
/// Renvoit une Armure grace a un pointeur Item
/// </summary>
/// <param name="armurePtr">Le pointeur Item de nature Armure</param>
/// <returns>Une Armure</returns>
Armure itemAsArmure(Item*& armurePtr);


/// <summary>
/// Genere un arme au hasard...
/// </summary>
/// <returns>Une arme</returns>
const Arme armeHasard();

/// <summary>
/// Genere un armure au hasard...
/// </summary>
/// <returns>Une armure</returns>
const Armure armureHasard();

/// <summary>
/// Genere d'abord une arme ou armure au hasard et effectue un lancer.
/// Juste pcq c'est intéressant sinon il suffisait de faire le lancer avant la génération ;)
/// Ce lancer determine si l'item sera attribuer à l'ennemi selon le dropRate;
/// </summary>
/// <param name="size">Le nombre maximum possible d'item a tenter</param>
/// <returns></returns>
vector<Item*> newVecteurDrop(const int& size);

/// <summary>
/// Permet d'augmenter une statistique du joueur à chaque niveau
/// </summary>
/// <param name="joueur">Le joueur</param>
void augmentStats(Joueur& joueur);

/// <summary>
/// Permet de gérer l'inventaire du joueur durant la gameloop
/// </summary>
/// <param name="joueur">Le joueur</param>
void gestionInventaire(Joueur& joueur);

/// <summary>
/// Affiche l'équipement présent du joueur
/// </summary>
/// <param name="joueur">Le joueur</param>
void afficherEquipement(Joueur& joueur);


#endif