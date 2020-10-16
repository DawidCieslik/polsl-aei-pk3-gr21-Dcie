#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Pole.h"
#include "Enums.h"

class Plansza
{
	ListaPol* pHead;									//<Lista przechowujaca pola

public:
	Plansza();
	~Plansza();
	sf::RectangleShape PodajKsztalt(int i, int j);		//<Zwraca ksztalt danego pola
	void InicjalizujPlansze();							//<Inicjalizuje plansze
	void WyswietlPlansze(sf::RenderWindow &window);		//<Wyswietla plansze na ekranie
	Plansza& operator+=(ListaPol* NowePole);			//<Dodaje nowe pole do listy pol
};

