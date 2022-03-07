#include "TestEnnemies.h"

int TestEnnemis::ennemisRandom()
{
	using namespace Utilities;
	using namespace Constante;

	init_random();

	Ennemi defaultEnnemi;
	vector<Ennemi> vecteurEnnemisCommuns;
	vector<Ennemi> vecteurEnnemisRares;

	int nCommun = 4;
	int nRare = 4;

	int rndNomCommun = random_number(0, nCommun);
	int rndNomRare = random_number(0, nRare);

	int total = 30;

	for(size_t i = 0; i < total; i++)
	{
		const int rndLvl = random_number(1, 6);

		string nomX{ ENNEMICOMMUN_NOM_TAB[rndNomCommun] };
		string nomY{ ENNEMIRARE_NOM_TAB[rndNomRare] };

		Ennemi ennemiX{ nomX, "Commun", rndLvl };
		Ennemi ennemiY{ nomY, "Rare", rndLvl };

		vecteurEnnemisCommuns.push_back(ennemiX);
		vecteurEnnemisRares.push_back(ennemiY);
	}
	return 0;
}
