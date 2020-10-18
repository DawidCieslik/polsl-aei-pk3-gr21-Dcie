#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Enums.h"

class Pole
{
	sf::RectangleShape kwadrat;							//Ksztalt pola (prostokat);
	bool CzyZajete;										//Czy w danym polu znajduje sie pionek/damka;
protected:
	float x;											//Wspolrzedna x;
	float y;											//Wspolrzedna y;
public:
	const sf::Texture* tekstura;						//Tekstura pola
	Pole();												//Konstruktor domyslny;
	Pole(const Pole& NowePole);							//Konstruktor kopiujacy;
	Pole(float x, float y);								//Konstruktor ustawiajacy pole we wskazanych wspolrzednych;
	void UstawX(float x);								//Przypisuje dla pola podana wspolrzedna x;
	void UstawY(float y);								//Przypisuje dla pola podana wspolrzedna y;
	float PodajX();										//Zwraca aktualna wspolrzedna x pola;
	float PodajY();										//Zwraca aktualna wspolrzedna y pola;
	sf::RectangleShape Ksztalt();						//Zwraca ksztalt pola (prostokat);
	void Pozycja(float x, float y);						//Ustawia pole we wskazanym punkcie (x,y);
	void Tekstura(const sf::Texture *Tekstura);			//Ustawia teksturê pola;
	void Kolor(const sf::Color &kolor);					//Ustawia kolor pola;
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