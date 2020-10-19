#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Enums.h"

class Pole
{
	sf::RectangleShape kwadrat;							//Ksztalt pola (prostokat);
protected:
	int x;												//Wspolrzedna x;
	int y;												//Wspolrzedna y;
public:
	TypPola typ;										//Typ pola
	Pole();												//Konstruktor domyslny;
	Pole(const Pole& NowePole);							//Konstruktor kopiujacy;
	Pole(int x, int y);									//Konstruktor ustawiajacy pole we wskazanych wspolrzednych;
	void UstawX(int x);									//Przypisuje dla pola podana wspolrzedna x;
	void UstawY(int y);									//Przypisuje dla pola podana wspolrzedna y;
	int PodajX();										//Zwraca aktualna wspolrzedna x pola;
	int PodajY();										//Zwraca aktualna wspolrzedna y pola;
	sf::RectangleShape Ksztalt();						//Zwraca ksztalt pola (prostokat);
	void Pozycja(int x, int y);							//Ustawia pole we wskazanym punkcie (x,y);
	void Kolor(const sf::Color &kolor);					//Ustawia kolor pola;
	void setOutlineColor(sf::Color kolor);				//Ustawia kolor konturu pola;
	Pole& operator=(const Pole& NowePole);				//Przypisuje jedno pole drugiemu.
};

class ListaPol																			//Lista przechowujaca pola;
{
public:
	Pole pole;																			//Element pola;
	ListaPol* pNext;																	//Wskaznik na nastepny element listy pol;
	ListaPol() : pole(), pNext(nullptr) {};												//Konstruktor domyslny;
	ListaPol(const Pole& NowePole) : pole(NowePole), pNext(nullptr) {};					//Konstruktor kopiujacy.
};