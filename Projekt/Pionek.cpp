#include "Pionek.h"

Pionek::Pionek()
{
	x = 0.f;
	y = 0.f;
	typ = TypPionka::PUSTE;
	tekstura = nullptr;
	kolo.setRadius(RozmiarPionka);
}

Pionek::Pionek(const Pionek& NowyPionek)
{
	x = NowyPionek.x;
	y = NowyPionek.y;
	typ = NowyPionek.typ;
	tekstura = NowyPionek.tekstura;
}

Pionek::Pionek(float x, float y, TypPionka typ)
{
	this->x = x;
	this->y = y;
	this->typ = typ;
	tekstura = nullptr;
	kolo.setRadius(RozmiarPionka);
}

void Pionek::UstawX(float x)
{
	Pole::UstawX(x);
}

void Pionek::UstawY(float y)
{
	Pole::UstawY(y);
}

float Pionek::PodajX()
{
	return Pole::PodajX();
}

float Pionek::PodajY()
{
	return Pole::PodajY();
}

sf::CircleShape Pionek::Ksztalt()
{
	return kolo;
}

void Pionek::Pozycja(float x, float y)
{
	kolo.setPosition(x * RozmiarPola + 15.f, y * RozmiarPola + 15.f);
}

void Pionek::Tekstura(const sf::Texture* tekstura)
{
	this->tekstura = tekstura;
}

void Pionek::Kolor(const sf::Color& kolor)
{
	kolo.setFillColor(kolor);
}

void Pionek::UstawTyp(TypPionka typ)
{
	this->typ = typ;
}

Pionek& Pionek::operator=(const Pionek& NowyPionek)
{
	x = NowyPionek.x;
	y = NowyPionek.y;
	typ = NowyPionek.typ;
	return *this;
}