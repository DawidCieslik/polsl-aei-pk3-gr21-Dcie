#include "Pionek.h"

Pionek::Pionek()
{
	x = 0;
	y = 0;
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
}

void Pionek::UstawPunktZaczepienia()
{
	kolo.setOrigin(0,-50);
}

void Pionek::Promien()
{
	kolo.setRadius(RozmiarPionka);
}

void Pionek::UsunPionka()
{
	kolo.setRadius(0);
	kolo.setOutlineThickness(0);
}

void Pionek::UstawPionka(int &tura)
{
	kolo.setRadius(RozmiarPionka);
	kolo.setOutlineThickness(4);
	kolo.setOutlineColor(czarny);
	if (tura % 2 == 0)
		kolo.setFillColor(bialy);
	else if (tura % 2 == 1)
		kolo.setFillColor(czarny);
	kolo.setPosition(this->x * RozmiarPola + 65, this->y * RozmiarPola + 115);
}

sf::Vector2f Pionek::DajPunktZaczepienia()
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

void Pionek::Kontur()
{
	kolo.setOutlineThickness(4);
}

void Pionek::KolorKonturu(const sf::Color kolor)
{
	kolo.setOutlineColor(kolor);
}

Pionek& Pionek::operator=(const Pionek& NowyPionek)
{
	x = NowyPionek.x;
	y = NowyPionek.y;
	return *this;
}