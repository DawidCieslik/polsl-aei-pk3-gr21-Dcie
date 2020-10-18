#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Enums.h"
#include "Pole.h"

class Pionek : public Pole
{
	sf::CircleShape kolo;								//Ksztalt pionka (kolo);
	TypPionka typ;										//Typ i kolor pionka;
public:
	const sf::Texture* tekstura;						//Tekstura pionka;
	Pionek();											//Konstruktor domyslny;
	Pionek(const Pionek& NowyPionek);					//Konstruktor kopiujacy;
	Pionek(float x, float y, TypPionka typ);			//Konstruktor ustawiajacy pionka we wskazanych wspolrzednych;
	void UstawX(float x);								//Przypisuje dla pionka podana wspolrzedna x;
	void UstawY(float y);								//Przypisuje dla pionka podana wspolrzedna y;
	void UstawTyp(TypPionka typ);						//Przydziela pionkowi jego typ i kolor;
	float PodajX();										//Zwraca aktualna wspolrzedna x pionka;
	float PodajY();										//Zwraca aktualna wspolrzedna y pionka;
	sf::CircleShape Ksztalt();							//Zwraca ksztalt pionka (kolo);
	void Pozycja(float x, float y);						//Ustawia pionek we wskazanym punkcie (x,y);
	void Tekstura(const sf::Texture* Tekstura);			//Ustawia teksturê pionka;
	void Kolor(const sf::Color& kolor);					//Ustawia kolor pionka;
	Pionek& operator=(const Pionek& NowyPionek);		//Przypisuje jeden pionek drugiemu.
};

class ListaPionkow																		//Lista przechowujaca pionki;
{
public:
	Pionek pionek;																		//Element pola;
	ListaPionkow* pNext;																//Wskaznik na nastepny element listy pol;
	ListaPionkow() : pionek(), pNext(nullptr) {};										//Konstruktor domyslny;
	ListaPionkow(const Pionek& NowyPionek) : pionek(NowyPionek), pNext(nullptr) {};		//Konstruktor kopiujacy.
};