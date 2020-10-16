#include "Pole.h"

Pole::Pole()
{
	x = 0;
	y = 0;
	CzyZajete = false;
	shape.setSize(sf::Vector2f(RozmiarPola, RozmiarPola));
	shape.setOutlineThickness(1);
}

Pole::Pole(const Pole& NowePole)
{
	x = NowePole.x;
	y = NowePole.y;
	CzyZajete = NowePole.CzyZajete;
}

Pole::Pole(int x, int y)
{
	this->x = x;
	this->y = y;
	CzyZajete = false;
	shape.setSize(sf::Vector2f(RozmiarPola, RozmiarPola));
	shape.setOutlineThickness(1);
}

void Pole::UstawX(int x)
{
	this->x = x;
}

void Pole::UstawY(int y)
{
	this->y = y;
}

float Pole::PodajX()
{
	return x;
}

float Pole::PodajY()
{
	return y;
}

sf::RectangleShape Pole::Ksztalt()
{
	return shape;
}

void Pole::Pozycja(int x, int y)
{
	shape.setPosition(x, y);
}

void Pole::Kolor(sf::Color Kolor)
{
	shape.setFillColor(Kolor);
}

Pole& Pole::operator=(const Pole& NowePole)
{
	x = NowePole.x;
	y = NowePole.y;
	CzyZajete = NowePole.CzyZajete;
	return *this;
}