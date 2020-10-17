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

Pole::Pole(float x, float y)
{
	this->x = x;
	this->y = y;
	CzyZajete = false;
	shape.setSize(sf::Vector2f(RozmiarPola, RozmiarPola));
	shape.setOutlineThickness(1);
}

void Pole::UstawX(float x)
{
	this->x = x;
}

void Pole::UstawY(float y)
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

void Pole::Pozycja(float x, float y)
{
	shape.setPosition(x * 100.f, y * 100.f);
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