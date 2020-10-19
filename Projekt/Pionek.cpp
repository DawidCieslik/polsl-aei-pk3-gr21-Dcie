#include "Pionek.h"

Pionek::Pionek()
{
	x = 0;
	y = 0;
	kolo.setRadius(RozmiarPionka);
	kolo.setOutlineThickness(4);
	kolo.setOutlineColor(czarny);
}

Pionek::Pionek(const Pionek& NowyPionek)
{
	x = NowyPionek.x;
	y = NowyPionek.y;
}

Pionek::Pionek(int x, int y)
{
	this->x = x;
	this->y = y;
	kolo.setRadius(RozmiarPionka);
	kolo.setOutlineThickness(4);
	kolo.setOutlineColor(czarny);
}

void Pionek::UstawX(int x)
{
	this->x = x;
}

void Pionek::UstawY(int y)
{
	this->y = y;
}

void Pionek::setOrigin()
{
	kolo.setOrigin(0,-50);
}

sf::Vector2f Pionek::getOrigin()
{
	return kolo.getOrigin();
}

int Pionek::PodajX()
{
	return x;
}

int Pionek::PodajY()
{
	return y;
}

sf::CircleShape Pionek::Ksztalt()
{
	return kolo;
}

void Pionek::Pozycja(int x, int y)
{
	kolo.setPosition(x * RozmiarPola + 65, y * RozmiarPola + 115);
}

void Pionek::Kolor(const sf::Color& kolor)
{
	kolo.setFillColor(kolor);
}

void Pionek::setOutlineColor(sf::Color kolor)
{
	kolo.setOutlineColor(kolor);
}

Pionek& Pionek::operator=(const Pionek& NowyPionek)
{
	x = NowyPionek.x;
	y = NowyPionek.y;
	return *this;
}