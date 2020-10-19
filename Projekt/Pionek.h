#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Enums.h"
#include "Pole.h"

class Pionek : public Pole
{
	sf::CircleShape kolo;								//Ksztalt pionka (kolo);
public:
	Pionek();											//Konstruktor domyslny;
	Pionek(const Pionek& NowyPionek);					//Konstruktor kopiujacy;
	Pionek(int x, int y);								//Konstruktor ustawiajacy pionka we wskazanych wspolrzednych;
	void UstawPunktZaczepienia();						//Ustawia punkt zaczepienia pionka;
	void Promien();										//Ustawia promien pionka;
	void UsunPionka();									//Usuwa pionka;
	void UstawPionka(int &tura);						//Ustawia nowego pionka;
	sf::Vector2f DajPunktZaczepienia();					//Zwraca wspolrzedne punktu zaczepienia;
	int PodajX();										//Zwraca aktualna wspolrzedna x pionka;
	int PodajY();										//Zwraca aktualna wspolrzedna y pionka;
	sf::CircleShape Ksztalt();							//Zwraca ksztalt pionka (kolo);
	void Pozycja(int x, int y);							//Ustawia pionek we wskazanym punkcie (x,y);
	void Kolor(const sf::Color& kolor);					//Ustawia kolor pionka;
	void Kontur();										//Ustawia grubosc konturu pionka;
	void KolorKonturu(const sf::Color kolor);			//Ustawia kolor konturu pionka;
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