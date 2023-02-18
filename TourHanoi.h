#pragma once
#include <vector>
#include <iostream>


class TourHanoi
{
private:
	std::vector<int> tour;

public:
	TourHanoi();
	~TourHanoi(void);
	void affiche();
	void push(int number);
	void construireTour(int niveau);
	int size();
	int peek();
	void pop();
};

