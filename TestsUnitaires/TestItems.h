#ifndef TESTITEMS_H
#define TESTITEMS_H
#include "../Utilities.h"
#include "../Constantes.h"
#include "../Item.h"
#include "../Arme.h"
#include "../Armure.h"


/// <summary>
/// Attention il serait préférable pour certaine méthode d'être tester dans l'environement Main.cpp
/// </summary>
namespace TestItems {
	vector<Arme> armesGuerrier;
	vector<Arme> armesMagicien;
	vector<Arme> armesAssassin;
	vector<Arme> armesCommunes;
	vector<Item> copieToutesArmes;
	

	void resultatRollItemEnnemy();
	void dynamicCast();
	void armesRandom();
	int findClasse(const Role&, vector<const Role*>);
}
#endif