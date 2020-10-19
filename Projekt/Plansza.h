#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Pionek.h"
#include "Error.h"
#include "Enums.h"

class Plansza : public Pionek
{
	ListaPol* pHead;									//Lista przechowujaca pola;
	ListaPionkow* pPionek;								//Lista przechowujaca pionki;

public:
	Plansza();											//Konstruktor domyœlny;
	~Plansza();											//Destruktor;
	Pionek& DajPionek(int i, int j);					//Zwraca pionka;
	Pole& DajPole(int i, int j);						//Zwraca pole;
	void InicjalizujPlansze();							//Inicjalizuje plansze;
;	void RozstawPionki();								//Rozstawia pionki na planszy;
	void WyswietlPlansze(sf::RenderWindow &window);		//Wyswietla plansze na ekranie;
	void RysujPionki(sf::RenderWindow& window);			//Wyswietla pionki na ekranie;
	Plansza& operator+=(ListaPol* NowePole);			//Dodaje nowe pole do listy pol;
	Plansza& operator+=(ListaPionkow* NowyPionek);		//Dodaje nowego pionka do listy pionkow.
};

