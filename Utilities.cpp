#include "Utilities.h"
#include <iostream>

int Utilities::random_number(int min, int maxExclus)
{
	if (min == maxExclus) return min;
	int ri = min + static_cast <int> (rand()) /
		(static_cast <int> (RAND_MAX / (maxExclus - min)));

	if (ri == maxExclus)
		return random_number(min, maxExclus);
	return ri;
}

float Utilities::random_float(float min, float maxExclus)
{
	if (min == maxExclus) return min;
	float fr = min + static_cast <float> (rand()) / 
		(static_cast <float> (RAND_MAX / (maxExclus - min)));

	if (fr == maxExclus)
		return random_float(min, maxExclus);

	return fr;
}


void Utilities::init_random()
{
	auto end = chrono::system_clock::now();
	srand(chrono::system_clock::to_time_t(end));
}

const time_t Utilities::getUtcNow()
{
	time_t t;
	struct tm tmp;
	t = time(NULL);
	gmtime_s(&tmp, &t);
	return t;
}


const std::string Utilities::parseTimeT(time_t& rawtimeEpoch, const char* format)
{
	tm timeS;
	char buffer[80];
	abs(rawtimeEpoch);

	// tm struct
	gmtime_s(&timeS, &rawtimeEpoch);

	// Écriture buffer
	strftime(buffer, 80, format, &timeS);
	return buffer;
}

/// ATTENTION N'EST PAS TOUJOURS VALIDE RESTE KLKE IMPLÉMENTATION A FAIRE
std::vector<std::string> Utilities::splitStr(std::string& needle, std::string haystack) {

	std::vector<std::string> hays;

	size_t pos = haystack.find(needle, 0);
	size_t len = haystack.length();
	size_t posNext = len;
	std::string hay;
	bool first = true;

	while (pos > -1)
	{
		posNext = haystack.find(needle, pos + 1);

		if (first && pos != 0) {
			hay = haystack.substr(0, pos);
			first = false;
		}
		else {
			hay = haystack.substr(pos + 1, posNext - 1);
		}


		if (!hay.empty())
			hays.push_back(hay);

		haystack.erase(0, posNext);
		pos = haystack.find(needle, 0);
		len = haystack.length();
	}
	return hays;
}

void Utilities::delai(clock_t delaiMs) {
	const clock_t msStart{ clock()};
	while (clock() - msStart <= delaiMs) {
	}
}


void Utilities::afficheDelai(string texte, clock_t delaiCharMs)
{
	for(auto charactere : texte)
	{
		delai(delaiCharMs);
		std::cout << charactere;
	}
}
