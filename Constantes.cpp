#include "Constantes.h"

const vector<int> Constante::defineTableXP()
{
	vector<int> tableXP{};
	for(size_t i = 1; i < 100; i++)
		tableXP.push_back(pow(i*10, 2)/2+1000);
	
	const vector<int> tableFinal{ tableXP };
	return tableFinal;
}