#ifndef UTILITIES_H
#define UTILITIES_H
#include <map>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include <chrono>
#include <sstream>
#include <stdlib.h>
#include <queue>


using namespace std;

namespace Utilities {

	/// <summary>
	/// Fonction pour init le random
	/// </summary>
	void init_random();

	/// <summary>
	/// Retourne un nombre random entre le min et le maxExclus
	/// </summary>
	/// <param name="min">Le nombre minimum</param>
	/// <param name="max">Le nombre maximum exclusif</param>
	/// <returns>Le nombre random</returns>
	int random_number(int min, int maxExclus);


	/// <summary>
	/// Retourne un float random entre le min et le maxExclus
	/// Utiliser un retour Int pour maxExclus
	/// Precision: 15 bits
	/// </summary>
	/// <param name="min">Le nombre minimum</param>
	/// <param name="maxExclus">Le nombre maximum exclusif</param>
	/// <returns>Le float random</returns>
	float random_float(float min, float maxExclus);

	/// <summary>
	/// Renvoir l'heure UTC en seconde
	/// </summary>
	/// <returns>Les seconde écoulé de puis 19000</returns>
	const time_t getUtcNow();

	/// <summary>
	/// Retourne un string selon le format demander sur lepoch.
	/// </summary>
	/// <param name="rawtimeEpoch">Secondes écoulées depuis l'année 1900</param>
	/// <param name="format">strftime format</param>
	/// <returns>Le string au format demandé</returns>
	const std::string parseTimeT(time_t& rawtimeEpoch, const char* format);

	/// <summary>
	/// Permet l'attente d'un certain temps en milliseconde par un boucle.
	/// </summary>
	/// <param name="delaiMs">Les millisecondes</param>
	void delai(clock_t delaiMs);

	/// <summary>
	/// Permet l'affichage d'un texte avec un delai entre chaque charactere.
	/// </summary>
	/// <param name="texte">Le texte a afficher</param>
	/// <param name="delaiCharMs">Les millisecondes entre les chars</param>
	void afficheDelai(string texte, clock_t delaiCharMs);

	/// ATTENTION N'EST PAS TOUJOURS VALIDES RESTE KLKE TEST A FAIRE
	std::vector<std::string> splitStr(std::string& needle, std::string haystack);


}


#endif