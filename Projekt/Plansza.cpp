#include "Plansza.h"
#include <iostream>

Plansza::Plansza()
{
	this->pHead = nullptr;
}

Plansza::~Plansza()
{
	while (pHead)
	{
		ListaPol* temp = pHead->pNext;
		delete pHead;
		pHead = temp;
	}
}

sf::RectangleShape Plansza::PodajKsztalt(int i, int j)
{
	ListaPol* temp = pHead;
	while (temp)
	{
		if (temp->pole.PodajX() == i && temp->pole.PodajY() == j)
			return temp->pole.Ksztalt();
		temp = temp->pNext;
	}
	std::string exception = "nie ma takiego pola";
	throw exception;
}

void Plansza::InicjalizujPlansze()
{
	for (int y = 0; y < RozmiarPlanszy; y++)
	{
		for (int x = 0; x < RozmiarPlanszy; x++)
		{
			ListaPol* NowePole = new ListaPol;
			NowePole->pole.UstawX(x);
			NowePole->pole.UstawY(y);
			if ((x + y) % 2 == 0)
				NowePole->pole.Kolor(jasny);
			else
				NowePole->pole.Kolor(ciemny);
			NowePole->pole.Pozycja(100*x+50, 100*y+100);
			(*this) += NowePole;
		}
	}
}

void Plansza::WyswietlPlansze(sf::RenderWindow &window)
{
	for (int y = 0; y < RozmiarPlanszy; y++)
	{
		for (int x = 0; x < RozmiarPlanszy; x++)
		{
			window.draw(PodajKsztalt(x, y));
		}
	}
}

Plansza& Plansza::operator+=(ListaPol* NowePole)
{
	if (pHead == nullptr)
		pHead = NowePole;
	else
	{
		ListaPol* temp = pHead;
		if(temp->pNext)
			while (temp->pNext)
			{
				temp = temp->pNext;
			}
		temp->pNext = NowePole;
		NowePole->pNext = nullptr;
	}
	return *this;
}