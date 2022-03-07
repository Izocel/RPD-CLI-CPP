#ifndef CONSTANTES_H
#define CONSTANTES_H
#include "Utilities.h"
#include "Role.h"
#include "Action.h"

namespace Constante {

	const int LARGEURMENU = 165;

	const string OPENINGLINE{
		" "
		+ string(LARGEURMENU-2, '_')
		+ " "
		+ "\n"
	};

	const string CLOSINGLINE{
		"|"
		+ string(LARGEURMENU-2, '_')
		+ "|"
		+ "\n"
	};

	const string SUBCLOSINGLINE{
		"|"
		+ string(LARGEURMENU-2, '-')
		+ "|"
		+ "\n"
	};

	const string EMPTYLINE{
		"|"
		+ string(LARGEURMENU-2, ' ')
		+ "|"
		+ "\n"
	};

	const string HALFEMPTYLINE{
		"|"
		+ string(LARGEURMENU/2 -3, ' ')
		+ "|"
		+ "\n"
	};

	//Delai pour affichage
	const int DELAY{ 16 };
	const int ATTACK_AUGM{ 10 };
	const int DEFENSE_AUGM{ 10 };

	// Rarete
	const int RARETER_TAB_SIZE = 4;
	const std::string RARETER_TAB[4]
	{
		"Commun",
		"Rare",
		"Epique",
		"Legendaire"
	};

	// Nom Bouclier Guerrier
	const std::string BOUCLIERNOM_TAB[2]
	{
		"Petit bouclier",
		"Grand bouclier"
	};

	// Nom Arme Guerrier
	const std::string ARMENOM_GUERRIER_TAB[3]
	{
		"Epee",
		"Lance",
		"Massue"
	};

	// Nom Arme Magicien
	const std::string ARMENOM_MAGICIEN_TAB[3]
	{
		"Orbe lumiere",
		"Orbe noirceur",
		"Cristal"
	};

	// Nom Arme Asassin
	const std::string ARMENOM_ASSASSIN_TAB[3]
	{
		"Couteau",
		"Hachettes",
		"Sabre"
	};

	// Nom Arme Communes
	const std::string ARMENOM_COMMUNES_TAB[3]
	{
		"Hache",
		"Baton",
		"Lame"
	};


	// Nom Ennemi Commun
	const std::string ENNEMICOMMUN_NOM_TAB[4]
	{
		"Ogre",
		"Ange",
		"Bazul",
		"Mercenaire"
	};

	// Nom Ennemi Rare
	const std::string ENNEMIRARE_NOM_TAB[4]
	{
		"Chef des ogres",
		"Ange malefique",
		"Chevalier bazul",
		"Roi des mercenaires"
	};

	/// <summary>
	/// Map repr�sentant les ennemis commun "nomKey" tuple(atkBase,defBase,hpBase)
	/// </summary>
	const std::map<std::string, const std::tuple<int, int, int> > ENNEMICOMMUN_ATKDEFHP_MAP
	{
		{"Ogre", {7,4,15} },
		{"Ange", {10,3,20} },
		{"Bazul", {10,5,25} },
		{"Mercenaire", {8,4,35} }
	};


	/// <summary>
	/// Map repr�sentant les ennemis rare "nomKey" tuple(atkBase,defBase,hpBase)
	/// </summary>
	const std::map<std::string, const std::tuple<int, int, int>> ENNEMIRARE_ATKDEFHP_MAP
	{
		{"Chef des ogres", {17,8,35} },
		{"Ange malefique", {18,9,40} },
		{"Chevalier bazul", {16,12,50} },
		{"Roi des mercenaires", {16,11,54} }
	};


	/// <summary>
	/// Map repr�sentant les actions  "nomKey" Action{nom, attaque, defense, recupRessource, depenseRessource, recupHp}
	/// </summary>
	const std::map < std::string, const Action > ACTION_BASE_GUERRIER
	{
		{"Defense accrue", {"Defense accrue", 0, 50, 0, 10, 0}},
		{"Recuperation de vie", {"Recuperation de vie", 0, 0, 0, 10, 20}},
		{"Recuperation de ressource", {"Recuperation de ressource", 0, 0, 30, 0, 0}},
	};

	/// <summary>
	/// Map repr�sentant les actions  "nomKey" Action{nom, attaque, defense, recupRessource, depenseRessource, recupHp}
	/// </summary>
	const std::map < std::string, const Action > ACTION_BASE_CHEVALIER
	{
		{"Defense ultime", {"Defense ultime", 0, 100, 0, 20, 0}},
		{"Recuperation de vie", {"Recuperation de vie", 0, 0, 0, 20, 40}},
		{"Recuperation de ressource", {"Recuperation de ressource", 0, 0, 60, 0, 0}},
	};

	/// <summary>
	/// Map repr�sentant les actions  "nomKey" Action{nom, attaque, defense, recupRessource, depenseRessource, recupHp}
	/// </summary>
	const std::map < std::string, const Action > ACTION_BASE_MAGICIEN
	{
		{"Foudre", {"Foudre", 50, 0, 0, 10, 0}},
		{"Recuperation de vie", {"Recuperation de vie", 0, 0, 0, 10, 20}},
		{"Recuperation de ressource", {"Recuperation de ressource", 0, 0, 30, 0, 0}},
	};

	/// <summary>
	/// Map repr�sentant les actions  "nomKey" Action{nom, attaque, defense, recupRessource, depenseRessource, recupHp}
	/// </summary>
	const std::map < std::string, const Action > ACTION_BASE_SORCIER
	{
		{"Rayon solaire", {"Rayon solaire", 100, 0, 0, 20, 0}},
		{"Recuperation de vie", {"Recuperation de vie", 0, 0, 0, 20, 40}},
		{"Recuperation de ressource", {"Recuperation de ressource", 0, 0, 60, 0, 0}},
	};

	/// <summary>
	/// Map repr�sentant les actions  "nomKey" Action{nom, attaque, defense, recupRessource, depenseRessource, recupHp}
	/// </summary>
	const std::map < std::string, const Action > ACTION_BASE_ASSASSIN
	{
		{"Lame vampirique", {"Lame vampirique", 40, 0, 0, 20, 0}},
		{"Recuperation de vie", {"Recuperation de vie", 0, 0, 0, 10, 20}},
		{"Recuperation de ressource", {"Recuperation de ressource", 0, 0, 30, 0, 0}},
	};

	/// <summary>
	/// Map repr�sentant les actions  "nomKey" Action{nom, attaque, defense, recupRessource, depenseRessource, recupHp}
	/// </summary>
	const std::map < std::string, const Action > ACTION_BASE_OMBRE
	{
		{"Dague du silence", {"Dague du silence", 80, 0, 0, 40, 0}},
		{"Recuperation de vie", {"Recuperation de vie", 0, 0, 0, 20, 40}},
		{"Recuperation de ressource", {"Recuperation de ressource", 0, 0, 60, 0, 0}},
	};

	const vector<int> defineTableXP();
	const vector<int> TABLE_XP { defineTableXP() };

	/// <summary>
	/// Map repr�sentant les roles evolutifs Joueur "nomKey" Role{nom, attaqueCoef, defenseCoef, ressourceMax, hpPerLevel, nomRessource, actions, evolution}
	/// </summary>
	const std::map<std::string, const Role> ROLEEVOL_ATKDEFHP_MAP
	{
		{"Chevalier", {"Chevalier", 0, 100, 300, 200, "Endurance", &ACTION_BASE_CHEVALIER, nullptr, TABLE_XP}},
		{"Sorcier", {"Sorcier", 100, 0, 300, 100, "Mana", &ACTION_BASE_SORCIER, nullptr, TABLE_XP}},
		{"Ombre", {"Ombre", 70, 30, 300, 150, "Adrenaline", &ACTION_BASE_OMBRE, nullptr, TABLE_XP}},
	};
	
	/// <summary>
	/// Map repr�sentant les role Joueur "nomKey" Role{nom, attaqueCoef, defenseCoef, ressourceMax, hpPerLevel, nomRessource, actions, evolution}
	/// </summary>
	const std::map<std::string, const Role> ROLEBASE_ATKDEFHP_MAP
	{
		{"Guerrier", {"Guerrier", 0, 25, 100, 100, "Endurance", &ACTION_BASE_GUERRIER, &ROLEEVOL_ATKDEFHP_MAP.at("Chevalier"), TABLE_XP}},
		{"Magicien", {"Magicien", 25, 0, 100, 50, "Mana", &ACTION_BASE_MAGICIEN, &ROLEEVOL_ATKDEFHP_MAP.at("Sorcier"), TABLE_XP}},
		{"Assassin", {"Assassin", 15, 15, 100, 75, "Adrenaline", &ACTION_BASE_ASSASSIN, &ROLEEVOL_ATKDEFHP_MAP.at("Ombre"), TABLE_XP}},
	};

	// Nom Armure
	const std::string ARMURE_NOM_TAB[6]
	{
		"Armure de fer",
		"Armure d'obsidienne",
		"Toge d'apprenti",
		"Toge de maitre",
		"Tenue discrete",
		"Cape d'invisibilite"
	};

	/// <summary>
	/// Map repr�sentant les classes par armure "nomKey" Role{nom, attaqueCoef, defenseCoef, ressourceMax, hpPerLevel, nomRessource, actions, evolution}
	/// </summary>
	const std::map<std::string, tuple<int, vector<const Role*>>> ARMURES
	{
		{"Armure de fer", {5, {&ROLEEVOL_ATKDEFHP_MAP.at("Chevalier"), &ROLEBASE_ATKDEFHP_MAP.at("Guerrier")}}},
		{"Armure d'obsidienne", {15, {&ROLEEVOL_ATKDEFHP_MAP.at("Chevalier"), &ROLEBASE_ATKDEFHP_MAP.at("Guerrier")}}},
		{"Toge d'apprenti", {10, {&ROLEEVOL_ATKDEFHP_MAP.at("Sorcier"), &ROLEBASE_ATKDEFHP_MAP.at("Magicien")}}},
		{"Toge de maitre", {20, {&ROLEEVOL_ATKDEFHP_MAP.at("Sorcier"), &ROLEBASE_ATKDEFHP_MAP.at("Magicien")}}},
		{"Tenue discrete", {8, {&ROLEEVOL_ATKDEFHP_MAP.at("Ombre"), &ROLEBASE_ATKDEFHP_MAP.at("Assassin")}}},
		{"Cape d'invisibilite", {16, {&ROLEEVOL_ATKDEFHP_MAP.at("Ombre"), &ROLEBASE_ATKDEFHP_MAP.at("Assassin")}}}
	};


	/// <summary>
	/// Map repr�sentant les armes de base du jeu "nomKey" (minBaseAtk,baseMaxAtk)
	/// </summary>
	const std::map<std::string, std::tuple<int, int, vector<const Role*>>> ARMEBASE_MAP
	{
		//Communes
		{"Hache", {1,5, {}  } },
		{"Baton", {2,4, {} } },
		{"Lame", {2,5, {} } },

		//Guerrier
		{"Epee", {8,10, {&ROLEBASE_ATKDEFHP_MAP.at("Guerrier")}  } },
		{"Lance", {8,12, {&ROLEBASE_ATKDEFHP_MAP.at("Guerrier")}  } },
		{"Massue", {8,15, {&ROLEBASE_ATKDEFHP_MAP.at("Guerrier")}  } },

		//Magicien
		{"Orbe lumiere", {8,9, {&ROLEBASE_ATKDEFHP_MAP.at("Magicien")}  } },
		{"Orbe noirceur", {6,10, {&ROLEBASE_ATKDEFHP_MAP.at("Magicien")}  } },
		{"Cristal", {12,12, {&ROLEBASE_ATKDEFHP_MAP.at("Magicien")}  } },

		//Assassin
		{"Couteau", {6,11, {&ROLEBASE_ATKDEFHP_MAP.at("Assassin")}  } },
		{"Hachettes", {5,12, {&ROLEBASE_ATKDEFHP_MAP.at("Assassin")}  } },
		{"Sabre", {7,15, {&ROLEBASE_ATKDEFHP_MAP.at("Assassin")}  } }
	};

}
#endif
