#include "Pole.h"
#include "Error.h"

Pole::Pole()
{
	x = 0.f;
	y = 0.f;
	CzyZajete = false;
	tekstura = nullptr;
	kwadrat.setSize(sf::Vector2f(RozmiarPola, RozmiarPola));
	kwadrat.setOutlineThickness(5);
	kwadrat.setOutlineColor(sf::Color::Black);
}

Pole::Pole(const Pole& NowePole)
{
	x = NowePole.x;
	y = NowePole.y;
	tekstura = NowePole.tekstura;
	CzyZajete = NowePole.CzyZajete;
}

Pole::Pole(float x, float y)
{
	this->x = x;
	this->y = y;
	CzyZajete = false;
	tekstura = nullptr;
	kwadrat.setSize(sf::Vector2f(RozmiarPola, RozmiarPola));
	kwadrat.setOutlineThickness(5);
	kwadrat.setOutlineColor(sf::Color::Black);
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
	return kwadrat;
}

void Pole::Pozycja(float x, float y)
{
	kwadrat.setPosition(x * RozmiarPola, y * RozmiarPola);
}

void Pole::Tekstura(const sf::Texture *tekstura)
{
	this->tekstura = tekstura;
}

void Pole::Kolor(const sf::Color &kolor)
{
	kwadrat.setFillColor(kolor);
}

Pole& Pole::operator=(const Pole& NowePole)
{
	x = NowePole.x;
	y = NowePole.y;
	CzyZajete = NowePole.CzyZajete;
	return *this;
}