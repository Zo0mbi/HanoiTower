#include "TourHanoi.h"

using namespace std;

TourHanoi::TourHanoi()
{
	
}

TourHanoi::~TourHanoi(void)
{
	tour.clear();
}

void TourHanoi::affiche()
{
	//starting from the other start of the vector
	for (int i = 0; i < tour.size(); i++)
	{
		if (i != tour.size() - 1)
		{
			cout << tour[i] << " - ";
		}
		else
		{
			cout << tour[i];
		}
	}
}

void TourHanoi::push(int number)
{
	tour.push_back(number);
}

void TourHanoi::pop()
{
	tour.pop_back();
}

void TourHanoi::construireTour(int niveau)
{
	for (int i = niveau; i > 0; i--)
	{
		/*
		* Extrait de code soutirer sur StackOverflow
		* https://stackoverflow.com/a/48251347
		* Autheur: Ron
		* Permet de rajouter un element au debut du vector
		*/
		tour.insert(tour.begin(),i);
		//Fin du code emprunter
	}
}

int TourHanoi::size()
{
	//as du rajouter le + 1 pour etre sur que l'index 0 soit compter
	if (!tour.empty()) {
		return tour.size() + 1;
	}
	return 0;
}

int TourHanoi::peek()
{
	if (!tour.empty())
	{
		return tour.back();
	}
	else {
		return 0;	
	}
}