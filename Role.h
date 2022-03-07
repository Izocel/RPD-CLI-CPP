#pragma once
#include "Utilities.h"
#include "Action.h"

struct Role
{
public:
	string name;
	int attackCoef;
	int defenseCoef;
	int ressourceMax;
	int hpPerLevel;
	string nomRessource;
	const map<string, const Action>* actions;
	const Role* evolution;
	const vector<int> tableXp;
};

