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
	string nomRessource;
	map<string, Action*> actions;
	Role* evolution;
};

