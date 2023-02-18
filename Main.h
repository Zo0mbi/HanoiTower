#pragma once
#include "TourHanoi.h"
#include <stack>
#include <cstdlib> // Utiliser pour system("cls") pour vider la console

int main();

void environnementJeux();

void jouerTour();

int validerNombre();

int choisirNiveau();

void printNiveau();

void viderConsole();

void gagner();

void regle();

bool verifierTourDepars(int number);

bool verifierTourArrivee(int depars, int arriver);

void deplacerPiece(int depars, int arriver);

