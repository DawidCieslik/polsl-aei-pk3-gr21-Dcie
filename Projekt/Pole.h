#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Enums.h"

class Pole
{
	sf::RectangleShape shape;							//<Ksztalt
	bool CzyZajete;										//<Czy w danym polu znajduje sie pionek/damka
	float x;											//<Wspolrzedna x
	float y;											//<Wspolrzedna y
public:
	Pole();												//<Konstruktor domyslny: ustawia x=0; y=0; CzyZajete=false;
	Pole(const Pole& new_field);						//<Konstruktor 
	Pole(int x, int y);									//<Konstruktor ustawiajacy kwadrat we wskazanych wspolrzednych
	void UstawX(int x);									//<Ustawia kwadrat w podanej wspolrzednej x
	void UstawY(int y);									//<Ustawia kwadrat w podanej wspolrzednej y
	float PodajX();										//<Zwraca aktualna wspolrzedna x kwadratu
	float PodajY();										//<Zwraca aktualna wspolrzedna y kwadratu
	sf::RectangleShape Ksztalt();						//<Ustawia ksztalt
	void Pozycja(int x, int y);							//<Ustawia kwadrat we wskazanym punkcie x y
	void Kolor(sf::Color Kolor);						//<Ustawia kolor kwadratu
	Pole& operator=(const Pole& NowePole);				//<Przypisuje jeden kwadrat drugiemu
};

class ListaPol											//Lista przechowujaca pola
{
public:
	Pole pole;
	ListaPol* pNext;
	ListaPol(const Pole& NowePole) : pole(NowePole), pNext(nullptr) {};
	ListaPol() : pole(), pNext(nullptr) {};
};