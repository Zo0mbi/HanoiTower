// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

#include "Main.h"

using namespace std;

/// <summary>
/// Variable Globale tour1
/// </summary>
TourHanoi tour1;

/// <summary>
/// Variable Globale tour2
/// </summary>
TourHanoi tour2;

/// <summary>
/// Variable Globale tour3
/// </summary>
TourHanoi tour3;

/// <summary>
/// Variable Global pour savoir si tu continue a jouer.
/// </summary>
bool jouer = true;

int main()
{
	//Methode servant a lancer le jeux
	if (jouer)
	{
		environnementJeux();
	}
	else {
		cout << "A la prochaine! Appuyer sur un touche pour quitter.";
		cin.get();
	}
}
//Sert de Game Manager pour le programme.
void environnementJeux() 
{
	regle();
	int niveau{choisirNiveau()};
	while (tour3.size()!=niveau+1)
	{
		system("cls"); // clear console
		printNiveau();
		jouerTour();
	}
	gagner();
}
//Fais jouer le joueur au tour ou il est rendu.
void jouerTour()
{
	int tourDepart;
	int tourArrivee{ 0 };
	//Verification
	do {
		cout << "Choisir la tour de depart" << endl;
		tourDepart = validerNombre();
	} while (!verifierTourDepars(tourDepart));
	//Verification
	do {
		cout << "Choisir la tour de destination" << endl;
		int tourArrivee{ validerNombre() };
	} while ((!verifierTourArrivee(tourArrivee, tourDepart)));
	//Deplacement
	cout << "Deplacement de la tour " << tourDepart << " vers la tour " << tourArrivee << endl;
	deplacerPiece(tourDepart, tourArrivee);
	viderConsole();
}
//verifier que le nombre est un entier entre 1 et 3 inclus
int validerNombre()
{
	int number;
	cin >> number;
	while (number < 1 || number > 3)
	{
		cout << "Veuillez entrer un nombre entre 1 et 3 inclus" << endl;
		cin >> number;
	}
	return number;
}
//sert a choisir le niveau de difficulte | nombre de piece au debut du jeux.
int choisirNiveau()
{
	int niveau;
	do
	{
		cout << "Choisir le niveau de difficulte Entre 3 et 10 inclusivement" << endl;
		cin >> niveau;
	} 
	while (niveau < 3 || niveau > 10);
	cout << endl;
	cout << "Vous avez choisi le niveau " << niveau << endl;
	tour1.construireTour(niveau);
	viderConsole();
	return niveau;
}
//affiche le niveau actuel
void printNiveau()
{
	cout << "Tour 1: ";
	tour1.affiche();
	cout << endl;
	cout << "Tour 2: ";
	tour2.affiche();
	cout << endl;
	cout << "Tour 3: ";
	tour3.affiche();
	cout << endl;
}
//Vide la console
void viderConsole()
{
	cout << "Pour continuer appuyer sur entrer" << endl;
	cin.get();
	system("cls"); // clear console
}
//Dialogue de victoire et demande si on veut rejouer
void gagner()
{
	cout << "Bravo vous avez gagne" << endl;
	cout << "Voulez vous rejouer ?" << endl;
	cout << "1. Oui" << endl;
	cout << "2. Non" << endl;
	int choix;
	cin >> choix;
	if (choix == 1)
	{
		environnementJeux();
	}
	else
	{
		cout << "Merci d'avoir jouer" << endl;
		jouer = false;
	}
}
//Liste les regles du jeux
void regle()
{
	cout << "Bienvenue dans le jeux de la tour de Hanoi" << endl;
	cout << "Le but du jeu est de deplacer toutes les pieces de la tour de depart a la tour d'arrivee." << endl;
	cout << "Pour ce faire, il faut respecter les regles suivantes:" << endl;
	cout << "1. On ne peut deplacer qu'une seule piece a la fois." << endl;
	cout << "2. On ne peut deplacer une piece que sur une autre plus grande." << endl;
	cout << "3. On ne peut pas deplacer une piece sur une autre plus petite." << endl;
	cout << "4. Tout les nombres choisis doivent etre des entiers en chiffres. " << endl;
	viderConsole();
}
//Verifie que la tour de depart n'est pas vide
bool verifierTourDepars(int number)
{
	if (number == 1)
	{
		if (tour1.size() == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else if (number == 2)
	{
		if (tour2.size() == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else if (number == 3)
	{
		if (tour3.size() == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}
//Verifier que la valeur du depars est plus grand que celle de la destination et que 
bool verifierTourArrivee(int depars, int arriver)
{
	//Extrait de code rajouter pour verifier la valeur de la tour.
	int valeur;
	if (depars == 1) {
		valeur = tour1.peek();
	}
	else if (depars == 2)
	{
		valeur = tour2.peek();
	}
	else if (depars == 3)
	{
		valeur = tour3.peek();
	}
	//Sanity check
	if (arriver == 1)
	{
		if (valeur > tour1.peek())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if (arriver == 2)
	{
		if (valeur > tour2.peek())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if (arriver == 3)
	{
		if (valeur > tour3.peek())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
//Deplace les pieces avec les instructions du joueurs
void deplacerPiece(int depars, int arriver)
{
	if (depars == 1)
	{
		if (arriver == 2)
		{
			tour2.push(tour1.peek());
			tour1.pop();
		}
		else if (arriver == 3)
		{
			tour3.push(tour1.peek());
			tour1.pop();
		}
	}
	else if (depars == 2)
	{
		if (arriver == 1)
		{
			tour1.push(tour2.peek());
			tour2.pop();
		}
		else if (arriver == 3)
		{
			tour3.push(tour2.peek());
			tour2.pop();
		}
	}
	else if (depars == 3)
	{
		if (arriver == 1)
		{
			tour1.push(tour3.peek());
			tour3.pop();
		}
		else if (arriver == 2)
		{
			tour2.push(tour3.peek());
			tour3.pop();
		}
	}
}