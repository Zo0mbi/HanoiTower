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
	for (int i = tour.size() ; i >= 0; i--)
	{
		if (i != 0)
		{
			cout << tour[i] << " - ";
		}
		else
		{
			cout << tour[i] << endl;
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
	for (int i = niveau; i >= 0; i--)
	{
		tour.push_back(i);
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