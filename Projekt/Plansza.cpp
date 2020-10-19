#include "Plansza.h"

Plansza::Plansza()
{
	this->pHead = nullptr;
	this->pPionek = nullptr;
}

Plansza::~Plansza()
{
	while (pHead)
	{
		ListaPol* temp = pHead->pNext;
		delete pHead;
		pHead = temp;
	}
	while (pPionek)
	{
		ListaPionkow* temp = pPionek->pNext;
		delete pPionek;
		pPionek = temp;
	}
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
			{
				NowePole->pole.Kolor(jasny);
				NowePole->pole.typ = JASNE;
			}
			else if ((x + y) % 2 == 1)
			{
				NowePole->pole.Kolor(ciemny);
				if (y >= 0 && y <= 2)
					NowePole->pole.typ = CZARNY_PIONEK;
				else if (y >= 5 && y < RozmiarPlanszy)
					NowePole->pole.typ = BIALY_PIONEK;
			}
			NowePole->pole.Pozycja(x, y);
			(*this) += NowePole;
		}
	}
	RozstawPionki();
}

void Plansza::RozstawPionki()
{
	//USTAWIANIE CZARNYCH PIONKÓW
	for (int y = 0; y <= 2; y++)
	{
		for (int x = 0; x < RozmiarPlanszy; x++)
		{
			if ((x + y) % 2 != 0)
			{
				ListaPionkow* NowyPionek = new ListaPionkow;
				NowyPionek->pionek.UstawX(x);
				NowyPionek->pionek.UstawY(y);
				NowyPionek->pionek.Kolor(sf::Color::Black);
				NowyPionek->pionek.Pozycja(x, y);
				(*this) += NowyPionek;
			}
		}
	}

	//USTAWIANIE BIA£YCH PIONKÓW
	for (int y = 5; y < RozmiarPlanszy; y++)
	{
		for (int x = 0; x < RozmiarPlanszy; x++)
		{
			if ((x + y) % 2 != 0)
			{
				ListaPionkow* NowyPionek = new ListaPionkow;
				NowyPionek->pionek.UstawX(x);
				NowyPionek->pionek.UstawY(y);
				NowyPionek->pionek.Kolor(sf::Color::White);
				NowyPionek->pionek.Pozycja(x, y);
				(*this) += NowyPionek;
			}
		}
	}
}

void Plansza::WyswietlPlansze(sf::RenderWindow &window)
{
	for (int y = 0; y < RozmiarPlanszy; y++)
	{
		for (int x = 0; x < RozmiarPlanszy; x++)
		{
			window.draw(DajPole(x, y).Ksztalt());
		}
	}
}

Pionek& Plansza::DajPionek(int i, int j)
{
	ListaPionkow* temp = pPionek;
	while (temp)
	{
		if (temp->pionek.PodajX() == i && temp->pionek.PodajY() == j)
			return temp->pionek;
		temp = temp->pNext;
	}
	Blad(1);
}

Pole& Plansza::DajPole(int i, int j)
{
	ListaPol* temp = pHead;
	while (temp)
	{
		if (temp->pole.PodajX() == i && temp->pole.PodajY() == j)
			return temp->pole;
		temp = temp->pNext;
	}
	Blad(1);
}

void Plansza::RysujPionki(sf::RenderWindow &window)
{
	ListaPionkow* temp = pPionek;
	while (temp)
	{
		window.draw(temp->pionek.Ksztalt());
		temp = temp->pNext;
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

Plansza& Plansza::operator+=(ListaPionkow* NowyPionek)
{
	if (pPionek == nullptr)
		pPionek = NowyPionek;
	else
	{
		ListaPionkow* temp = pPionek;
		if (temp->pNext)
			while (temp->pNext)
			{
				temp = temp->pNext;
			}
		temp->pNext = NowyPionek;
		NowyPionek->pNext = nullptr;
	}
	return *this;
}