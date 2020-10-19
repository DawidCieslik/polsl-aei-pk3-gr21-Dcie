#include "Poruszanie.h"

void Zaznacz(int& x, int& y, Plansza& plansza)
{
	//RYSOWANIE MO¯LIWYCH RUCHÓW PIONKA
	if (x != -1 || y != -1)
	{
		if (field(x, y).typ != JASNE && field(x, y).typ != PUSTE)
		{
			piece(x, y).KolorKonturu(czerwony);

			//BIA£Y PIONEK
			if (field(x, y).typ == BIALY_PIONEK)
			{
				if (x != 0 && y != 0 && field(x - 1, y - 1).typ == PUSTE)
					field(x - 1, y - 1).Kolor(czerwony);				//GÓRNA LEWA PRZEK¥TNA PUSTA
				else if (x != 0 && y != 0 && (field(x - 1, y - 1).typ == CZARNY_PIONEK || field(x - 1, y - 1).typ == CZARNA_DAMKA))
					field(x - 2, y - 2).Kolor(czerwony);				//PIONEK PRZECIWNIKA NA GÓRNEJ LEWEJ PRZEKATNEJ
				if (x != 7 && y != 0 && field(x + 1, y - 1).typ == PUSTE)
					field(x + 1, y - 1).Kolor(czerwony);				//GÓRNA PRAWA PRZEK¥TNA PUSTA
				else if (x != 7 && y != 0 && (field(x + 1, y - 1).typ == CZARNY_PIONEK || field(x + 1, y - 1).typ == CZARNA_DAMKA))
					field(x + 2, y - 2).Kolor(czerwony);				//PIONEK PRZECIWNIKA NA GÓRNEJ PRAWEJ PRZEKATNEJ
			}

			//BIA£A DAMKA
			if (field(x, y).typ == BIALA_DAMKA)
			{
				if (x != 0 && y != 7 && field(x - 1, y + 1).typ == PUSTE)
					field(x - 1, y + 1).Kolor(czerwony);				//DOLNA LEWA PRZEK¥TNA PUSTA
				else if (x != 0 && y != 7 && (field(x - 1, y + 1).typ == CZARNY_PIONEK || field(x - 1, y + 1).typ == CZARNA_DAMKA))
					field(x - 2, y + 2).Kolor(czerwony);				//PIONEK PRZECIWNIKA NA DOLNEJ LEWEJ PRZEKATNEJ
				if (x != 7 && y != 7 && field(x + 1, y + 1).typ == PUSTE)
					field(x + 1, y + 1).Kolor(czerwony);				//DOLNA PRAWA PRZEK¥TNA PUSTA
				else if (x != 7 && y != 7 && (field(x + 1, y + 1).typ == CZARNY_PIONEK || field(x + 1, y + 1).typ == CZARNA_DAMKA))
					field(x + 2, y + 2).Kolor(czerwony);				//PIONEK PRZECIWNIKA NA DOLNEJ PRAWEJ PRZEKATNEJ
				if (x != 0 && y != 0 && field(x - 1, y - 1).typ == PUSTE)
					field(x - 1, y - 1).Kolor(czerwony);				//GÓRNA LEWA PRZEK¥TNA PUSTA
				else if (x != 0 && y != 0 && (field(x - 1, y - 1).typ == CZARNY_PIONEK || field(x - 1, y - 1).typ == CZARNA_DAMKA))
					field(x - 2, y - 2).Kolor(czerwony);				//PIONEK PRZECIWNIKA NA GÓRNEJ LEWEJ PRZEKATNEJ
				if (x != 7 && y != 0 && field(x + 1, y - 1).typ == PUSTE)
					field(x + 1, y - 1).Kolor(czerwony);				//GÓRNA PRAWA PRZEK¥TNA PUSTA
				else if (x != 7 && y != 0 && (field(x + 1, y - 1).typ == CZARNY_PIONEK || field(x + 1, y - 1).typ == CZARNA_DAMKA))
					field(x + 2, y - 2).Kolor(czerwony);				//PIONEK PRZECIWNIKA NA GÓRNEJ PRAWEJ PRZEKATNEJ
			}

			//CZARNY PIONEK
			if (field(x, y).typ == CZARNY_PIONEK)
			{
				if (x != 0 && y != 7 && field(x - 1, y + 1).typ == PUSTE)
					field(x - 1, y + 1).Kolor(czerwony);				//DOLNA LEWA PRZEK¥TNA PUSTA
				else if (x != 0 && y != 7 && (field(x - 1, y + 1).typ == BIALY_PIONEK || field(x - 1, y + 1).typ == BIALA_DAMKA))
					field(x - 2, y + 2).Kolor(czerwony);				//PIONEK PRZECIWNIKA NA DOLNEJ LEWEJ PRZEKATNEJ
				if (x != 7 && y != 7 && field(x + 1, y + 1).typ == PUSTE)
					field(x + 1, y + 1).Kolor(czerwony);				//DOLNA PRAWA PRZEK¥TNA PUSTA
				else if (x != 7 && y != 7 && (field(x + 1, y + 1).typ == BIALY_PIONEK || field(x + 1, y + 1).typ == BIALA_DAMKA))
					field(x + 2, y + 2).Kolor(czerwony);				//PIONEK PRZECIWNIKA NA DOLNEJ PRAWEJ PRZEKATNEJ
			}

			//CZARNA DAMKA
			if (field(x, y).typ == CZARNA_DAMKA)
			{
				if (x != 0 && y != 7 && field(x - 1, y + 1).typ == PUSTE)
					field(x - 1, y + 1).Kolor(czerwony);				//DOLNA LEWA PRZEK¥TNA PUSTA
				else if (x != 0 && y != 7 && (field(x - 1, y + 1).typ == BIALY_PIONEK || field(x - 1, y + 1).typ == BIALA_DAMKA))
					field(x - 2, y + 2).Kolor(czerwony);				//PIONEK PRZECIWNIKA NA DOLNEJ LEWEJ PRZEKATNEJ
				if (x != 7 && y != 7 && field(x + 1, y + 1).typ == PUSTE)
					field(x + 1, y + 1).Kolor(czerwony);				//DOLNA PRAWA PRZEK¥TNA PUSTA
				else if (x != 7 && y != 7 && (field(x + 1, y + 1).typ == BIALY_PIONEK || field(x + 1, y + 1).typ == BIALA_DAMKA))
					field(x + 2, y + 2).Kolor(czerwony);				//PIONEK PRZECIWNIKA NA DOLNEJ PRAWEJ PRZEKATNEJ
				if (x != 0 && y != 0 && field(x - 1, y - 1).typ == PUSTE)
					field(x - 1, y - 1).Kolor(czerwony);				//GÓRNA LEWA PRZEK¥TNA PUSTA
				else if (x != 0 && y != 0 && (field(x - 1, y - 1).typ == BIALY_PIONEK || field(x - 1, y - 1).typ == BIALA_DAMKA))
					field(x - 2, y - 2).Kolor(czerwony);				//PIONEK PRZECIWNIKA NA GÓRNEJ LEWEJ PRZEKATNEJ
				if (x != 7 && y != 0 && field(x + 1, y - 1).typ == PUSTE)
					field(x + 1, y - 1).Kolor(czerwony);				//GÓRNA PRAWA PRZEK¥TNA PUSTA
				else if (x != 7 && y != 0 && (field(x + 1, y - 1).typ == BIALY_PIONEK || field(x + 1, y - 1).typ == BIALA_DAMKA))
					field(x + 2, y - 2).Kolor(czerwony);				//PIONEK PRZECIWNIKA NA GÓRNEJ PRAWEJ PRZEKATNEJ
			}
		}
	}
}

void UsunZaznaczenie(int &x, int &y, Plansza &plansza)
{
	//ODZNACZENIE MO¯LIWYCH RUCHÓW PIONKA
	if (x != -1 || y != -1)
	{
		if (field(x, y).typ != JASNE && field(x, y).typ != PUSTE)
		{
			piece(x, y).KolorKonturu(czarny);

			//BIA£Y PIONEK
			if (field(x, y).typ == BIALY_PIONEK)
			{
				if (x != 0 && y != 0 && field(x - 1, y - 1).typ == PUSTE)
					field(x - 1, y - 1).Kolor(ciemny);				//GÓRNA LEWA PRZEK¥TNA PUSTA
				else if (x != 0 && y != 0 && (field(x - 1, y - 1).typ == CZARNY_PIONEK || field(x - 1, y - 1).typ == CZARNA_DAMKA))
					field(x - 2, y - 2).Kolor(ciemny);				//PIONEK PRZECIWNIKA NA GÓRNEJ LEWEJ PRZEKATNEJ
				if (x != 7 && y != 0 && field(x + 1, y - 1).typ == PUSTE)
					field(x + 1, y - 1).Kolor(ciemny);				//GÓRNA PRAWA PRZEK¥TNA PUSTA
				else if (x != 7 && y != 0 && (field(x + 1, y - 1).typ == CZARNY_PIONEK || field(x + 1, y - 1).typ == CZARNA_DAMKA))
					field(x + 2, y - 2).Kolor(ciemny);				//PIONEK PRZECIWNIKA NA GÓRNEJ PRAWEJ PRZEKATNEJ
			}

			//BIA£A DAMKA
			if (field(x, y).typ == BIALA_DAMKA)
			{
				if (x != 0 && y != 7 && field(x - 1, y + 1).typ == PUSTE)
					field(x - 1, y + 1).Kolor(ciemny);				//DOLNA LEWA PRZEK¥TNA PUSTA
				else if (x != 0 && y != 7 && (field(x - 1, y + 1).typ == CZARNY_PIONEK || field(x - 1, y + 1).typ == CZARNA_DAMKA))
					field(x - 2, y + 2).Kolor(ciemny);				//PIONEK PRZECIWNIKA NA DOLNEJ LEWEJ PRZEKATNEJ
				if (x != 7 && y != 7 && field(x + 1, y + 1).typ == PUSTE)
					field(x + 1, y + 1).Kolor(ciemny);				//DOLNA PRAWA PRZEK¥TNA PUSTA
				else if (x != 7 && y != 7 && (field(x + 1, y + 1).typ == CZARNY_PIONEK || field(x + 1, y + 1).typ == CZARNA_DAMKA))
					field(x + 2, y + 2).Kolor(ciemny);				//PIONEK PRZECIWNIKA NA DOLNEJ PRAWEJ PRZEKATNEJ
				if (x != 0 && y != 0 && field(x - 1, y - 1).typ == PUSTE)
					field(x - 1, y - 1).Kolor(ciemny);				//GÓRNA LEWA PRZEK¥TNA PUSTA
				else if (x != 0 && y != 0 && (field(x - 1, y - 1).typ == CZARNY_PIONEK || field(x - 1, y - 1).typ == CZARNA_DAMKA))
					field(x - 2, y - 2).Kolor(ciemny);				//PIONEK PRZECIWNIKA NA GÓRNEJ LEWEJ PRZEKATNEJ
				if (x != 7 && y != 0 && field(x + 1, y - 1).typ == PUSTE)
					field(x + 1, y - 1).Kolor(ciemny);				//GÓRNA PRAWA PRZEK¥TNA PUSTA
				else if (x != 7 && y != 0 && (field(x + 1, y - 1).typ == CZARNY_PIONEK || field(x + 1, y - 1).typ == CZARNA_DAMKA))
					field(x + 2, y - 2).Kolor(ciemny);				//PIONEK PRZECIWNIKA NA GÓRNEJ PRAWEJ PRZEKATNEJ
			}

			//CZARNY PIONEK
			if (field(x, y).typ == CZARNY_PIONEK)
			{
				if (x != 0 && y != 7 && field(x - 1, y + 1).typ == PUSTE)
					field(x - 1, y + 1).Kolor(ciemny);				//DOLNA LEWA PRZEK¥TNA PUSTA
				else if (x != 0 && y != 7 && (field(x - 1, y + 1).typ == BIALY_PIONEK || field(x - 1, y + 1).typ == BIALA_DAMKA))
					field(x - 2, y + 2).Kolor(ciemny);				//PIONEK PRZECIWNIKA NA DOLNEJ LEWEJ PRZEKATNEJ
				if (x != 7 && y != 7 && field(x + 1, y + 1).typ == PUSTE)
					field(x + 1, y + 1).Kolor(ciemny);				//DOLNA PRAWA PRZEK¥TNA PUSTA
				else if (x != 7 && y != 7 && (field(x + 1, y + 1).typ == BIALY_PIONEK || field(x + 1, y + 1).typ == BIALA_DAMKA))
					field(x + 2, y + 2).Kolor(ciemny);				//PIONEK PRZECIWNIKA NA DOLNEJ PRAWEJ PRZEKATNEJ
			}

			//CZARNA DAMKA
			if (field(x, y).typ == CZARNA_DAMKA)
			{
				if (x != 0 && y != 7 && field(x - 1, y + 1).typ == PUSTE)
					field(x - 1, y + 1).Kolor(ciemny);				//DOLNA LEWA PRZEK¥TNA PUSTA
				else if (x != 0 && y != 7 && (field(x - 1, y + 1).typ == BIALY_PIONEK || field(x - 1, y + 1).typ == BIALA_DAMKA))
					field(x - 2, y + 2).Kolor(ciemny);				//PIONEK PRZECIWNIKA NA DOLNEJ LEWEJ PRZEKATNEJ
				if (x != 7 && y != 7 && field(x + 1, y + 1).typ == PUSTE)
					field(x + 1, y + 1).Kolor(ciemny);				//DOLNA PRAWA PRZEK¥TNA PUSTA
				else if (x != 7 && y != 7 && (field(x + 1, y + 1).typ == BIALY_PIONEK || field(x + 1, y + 1).typ == BIALA_DAMKA))
					field(x + 2, y + 2).Kolor(ciemny);				//PIONEK PRZECIWNIKA NA DOLNEJ PRAWEJ PRZEKATNEJ
				if (x != 0 && y != 0 && field(x - 1, y - 1).typ == PUSTE)
					field(x - 1, y - 1).Kolor(ciemny);				//GÓRNA LEWA PRZEK¥TNA PUSTA
				else if (x != 0 && y != 0 && (field(x - 1, y - 1).typ == BIALY_PIONEK || field(x - 1, y - 1).typ == BIALA_DAMKA))
					field(x - 2, y - 2).Kolor(ciemny);				//PIONEK PRZECIWNIKA NA GÓRNEJ LEWEJ PRZEKATNEJ
				if (x != 7 && y != 0 && field(x + 1, y - 1).typ == PUSTE)
					field(x + 1, y - 1).Kolor(ciemny);				//GÓRNA PRAWA PRZEK¥TNA PUSTA
				else if (x != 7 && y != 0 && (field(x + 1, y - 1).typ == BIALY_PIONEK || field(x + 1, y - 1).typ == BIALA_DAMKA))
					field(x + 2, y - 2).Kolor(ciemny);				//PIONEK PRZECIWNIKA NA GÓRNEJ PRAWEJ PRZEKATNEJ
			}
		}
	}
}

void ZmienKolorNaglowka(int &tura, std::string &s2, std::string &gracz1, std::string &gracz2, sf::Text &turaGracza, sf::Text &tytul)
{
	//ZMIANA NAPISU TURY I TYTU£U GRY NA BIA£Y
	if (tura % 2 == 0)
	{
		s2 += gracz1;
		turaGracza.setString(s2);
		sf::FloatRect textCenter2 = turaGracza.getLocalBounds();
		turaGracza.setOrigin(textCenter2.left + textCenter2.width / 2, 0);
		turaGracza.setPosition(sf::Vector2f(RozmiarOknaX / 2, 40));
		s2.erase(6, s2.length());
		turaGracza.setFillColor(bialy);
		tytul.setFillColor(bialy);
	}

	//ZMIANA NAPISU TURY I TYTU£U GRY NA CZARNY
	else if (tura % 2 == 1)
	{
		s2 += gracz2;
		turaGracza.setString(s2);
		sf::FloatRect textCenter2 = turaGracza.getLocalBounds();
		turaGracza.setOrigin(textCenter2.left + textCenter2.width / 2, 0);
		turaGracza.setPosition(sf::Vector2f(RozmiarOknaX / 2, 40));
		s2.erase(6, s2.length());
		turaGracza.setFillColor(czarny);
		tytul.setFillColor(czarny);
	}
}

void PrzesunPionka(Plansza& plansza, int& tura, int &x, int &y, Kierunek &kierunek)
{
	switch (kierunek)
	{
	case GL:														//GÓRNA LEWA PRZEK¥TNA
	{
		if (field(x, y).typ == BIALY_PIONEK || field(x, y).typ == BIALA_DAMKA ||
			field(x, y).typ == CZARNY_PIONEK || field(x, y).typ == CZARNA_DAMKA)
		{
			if (x != 0 && y != 0 && field(x - 1, y - 1).typ == PUSTE)
			{
				UsunZaznaczenie(x, y, plansza);

				//ZMIANA TYPU POLA
				field(x, y).typ = PUSTE;
				if (field(x, y).typ == BIALY_PIONEK)
					field(x - 1, y - 1).typ = BIALY_PIONEK;
				else if (field(x, y).typ == CZARNY_PIONEK)
					field(x - 1, y - 1).typ = CZARNY_PIONEK;
				else if (field(x, y).typ == BIALA_DAMKA)
					field(x - 1, y - 1).typ = BIALA_DAMKA;
				else if (field(x, y).typ == CZARNA_DAMKA)
					field(x - 1, y - 1).typ = CZARNA_DAMKA;

				piece(x, y).UsunPionka();							//USUWA PIONKA ZE STAREJ POZYCJI
				piece(x - 1, y - 1).UstawPionka(tura);				//USTAWIA PIONKA NA NOWEJ POZYCJI
				x = -1;
				y = -1;
				tura++;
			}
		}
	}
	case GP:														//GÓRNA PRAWA PRZEK¥TNA
	{
		if (field(x, y).typ == BIALY_PIONEK || field(x, y).typ == BIALA_DAMKA ||
			field(x, y).typ == CZARNY_PIONEK || field(x, y).typ == CZARNA_DAMKA)
		{
			if (x != 7 && y != 0 && field(x + 1, y - 1).typ == PUSTE)
			{
				UsunZaznaczenie(x, y, plansza);

				//ZMIANA TYPU POLA
				field(x, y).typ = PUSTE;
				if (field(x, y).typ == BIALY_PIONEK)
					field(x + 1, y - 1).typ = BIALY_PIONEK;
				else if (field(x, y).typ == CZARNY_PIONEK)
					field(x + 1, y - 1).typ = CZARNY_PIONEK;
				else if (field(x, y).typ == BIALA_DAMKA)
					field(x + 1, y - 1).typ = BIALA_DAMKA;
				else if (field(x, y).typ == CZARNA_DAMKA)
					field(x + 1, y - 1).typ = CZARNA_DAMKA;

				piece(x, y).UsunPionka();							//USUWA PIONKA ZE STAREJ POZYCJI
				piece(x + 1, y - 1).UstawPionka(tura);				//USTAWIA PIONKA NA NOWEJ POZYCJI
				x = -1;
				y = -1;
				tura++;
			}
		}
	}
	case DP:														//DOLNA PRAWA PRZEK¥TNA
	{
		if (field(x, y).typ == BIALY_PIONEK || field(x, y).typ == BIALA_DAMKA ||
			field(x, y).typ == CZARNY_PIONEK || field(x, y).typ == CZARNA_DAMKA)
		{
			if (x != 7 && y != 7 && field(x + 1, y + 1).typ == PUSTE)
			{
				UsunZaznaczenie(x, y, plansza);

				//ZMIANA TYPU POLA
				field(x, y).typ = PUSTE;
				if (field(x, y).typ == BIALY_PIONEK)
					field(x + 1, y + 1).typ = BIALY_PIONEK;
				else if (field(x, y).typ == CZARNY_PIONEK)
					field(x + 1, y + 1).typ = CZARNY_PIONEK;
				else if (field(x, y).typ == BIALA_DAMKA)
					field(x + 1, y + 1).typ = BIALA_DAMKA;
				else if (field(x, y).typ == CZARNA_DAMKA)
					field(x + 1, y + 1).typ = CZARNA_DAMKA;

				piece(x, y).UsunPionka();							//USUWA PIONKA ZE STAREJ POZYCJI
				piece(x + 1, y + 1).UstawPionka(tura);				//USTAWIA PIONKA NA NOWEJ POZYCJI
				x = -1;
				y = -1;
				tura++;
			}
		}
	}
	case DL:														//DOLNA LEWA PRZEK¥TNA
	{
		if (field(x, y).typ == BIALY_PIONEK || field(x, y).typ == BIALA_DAMKA ||
			field(x, y).typ == CZARNY_PIONEK || field(x, y).typ == CZARNA_DAMKA)
		{
			if (x != 0 && y != 7 && field(x - 1, y + 1).typ == PUSTE)
			{
				UsunZaznaczenie(x, y, plansza);

				//ZMIANA TYPU POLA
				field(x, y).typ = PUSTE;
				if (field(x, y).typ == BIALY_PIONEK)
					field(x - 1, y + 1).typ = BIALY_PIONEK;
				else if (field(x, y).typ == CZARNY_PIONEK)
					field(x - 1, y + 1).typ = CZARNY_PIONEK;
				else if (field(x, y).typ == BIALA_DAMKA)
					field(x - 1, y + 1).typ = BIALA_DAMKA;
				else if (field(x, y).typ == CZARNA_DAMKA)
					field(x - 1, y + 1).typ = CZARNA_DAMKA;

				piece(x, y).UsunPionka();							//USUWA PIONKA ZE STAREJ POZYCJI
				piece(x - 1, y + 1).UstawPionka(tura);				//USTAWIA PIONKA NA NOWEJ POZYCJI
				x = -1;
				y = -1;
				tura++;
			}
		}
	}
	case GL2:														//PIONEK PRZECIWNIKA NA GÓRNEJ LEWEJ PRZEK¥TNEJ
	{
		if (field(x, y).typ == BIALY_PIONEK || field(x, y).typ == BIALA_DAMKA ||
			field(x, y).typ == CZARNY_PIONEK || field(x, y).typ == CZARNA_DAMKA)
		{
			if (x >= 2 && y >= 2 && field(x - 2, y - 2).typ == PUSTE)
			{
				UsunZaznaczenie(x, y, plansza);

				//ZMIANA TYPU POLA
				field(x, y).typ = PUSTE;
				if (field(x, y).typ == BIALY_PIONEK)
					field(x - 2, y - 2).typ = BIALY_PIONEK;
				else if (field(x, y).typ == CZARNY_PIONEK)
					field(x - 2, y - 2).typ = CZARNY_PIONEK;
				else if (field(x, y).typ == BIALA_DAMKA)
					field(x - 2, y - 2).typ = BIALA_DAMKA;
				else if (field(x, y).typ == CZARNA_DAMKA)
					field(x - 2, y - 2).typ = CZARNA_DAMKA;

				piece(x, y).UsunPionka();							//USUWA PIONKA ZE STAREJ POZYCJI
				piece(x - 2, y - 2).UstawPionka(tura);				//USTAWIA PIONKA NA NOWEJ POZYCJI
				x = -1;
				y = -1;
				tura++;
			}
		}
	}
	case GP2:														//PIONEK PRZECIWNIKA NA GÓRNEJ PRAWEJ PRZEK¥TNEJ
	{
		if (field(x, y).typ == BIALY_PIONEK || field(x, y).typ == BIALA_DAMKA ||
			field(x, y).typ == CZARNY_PIONEK || field(x, y).typ == CZARNA_DAMKA)
		{
			if (x <= 5 && y >= 2 && field(x + 2, y - 2).typ == PUSTE)
			{
				UsunZaznaczenie(x, y, plansza);

				//ZMIANA TYPU POLA
				field(x, y).typ = PUSTE;
				if (field(x, y).typ == BIALY_PIONEK)
					field(x + 2, y - 2).typ = BIALY_PIONEK;
				else if (field(x, y).typ == CZARNY_PIONEK)
					field(x + 2, y - 2).typ = CZARNY_PIONEK;
				else if (field(x, y).typ == BIALA_DAMKA)
					field(x + 2, y - 2).typ = BIALA_DAMKA;
				else if (field(x, y).typ == CZARNA_DAMKA)
					field(x + 2, y - 2).typ = CZARNA_DAMKA;

				piece(x, y).UsunPionka();							//USUWA PIONKA ZE STAREJ POZYCJI
				piece(x + 2, y - 2).UstawPionka(tura);				//USTAWIA PIONKA NA NOWEJ POZYCJI
				x = -1;
				y = -1;
				tura++;
			}
		}
	}
	case DP2:														//PIONEK PRZECIWNIKA NA DOLNEJ PRAWEJ PRZEK¥TNEJ
	{
		if (field(x, y).typ == BIALY_PIONEK || field(x, y).typ == BIALA_DAMKA ||
			field(x, y).typ == CZARNY_PIONEK || field(x, y).typ == CZARNA_DAMKA)
		{
			if (x <= 5 && y <= 5 && field(x + 2, y + 2).typ == PUSTE)
			{
				UsunZaznaczenie(x, y, plansza);

				//ZMIANA TYPU POLA
				field(x, y).typ = PUSTE;
				if (field(x, y).typ == BIALY_PIONEK)
					field(x + 2, y + 2).typ = BIALY_PIONEK;
				else if (field(x, y).typ == CZARNY_PIONEK)
					field(x + 2, y + 2).typ = CZARNY_PIONEK;
				else if (field(x, y).typ == BIALA_DAMKA)
					field(x + 2, y + 2).typ = BIALA_DAMKA;
				else if (field(x, y).typ == CZARNA_DAMKA)
					field(x + 2, y + 2).typ = CZARNA_DAMKA;

				piece(x, y).UsunPionka();							//USUWA PIONKA ZE STAREJ POZYCJI
				piece(x + 2, y + 2).UstawPionka(tura);				//USTAWIA PIONKA NA NOWEJ POZYCJI
				x = -1;
				y = -1;
				tura++;
			}
		}
	}
	case DL2:														//PIONEK PRZECIWNIKA NA DOLNEJ LEWEJ PRZEK¥TNEJ
	{
		if (field(x, y).typ == BIALY_PIONEK || field(x, y).typ == BIALA_DAMKA ||
			field(x, y).typ == CZARNY_PIONEK || field(x, y).typ == CZARNA_DAMKA)
		{
			if (x >= 2 && y <= 5 && field(x - 2, y + 2).typ == PUSTE)
			{
				UsunZaznaczenie(x, y, plansza);

				//ZMIANA TYPU POLA
				field(x, y).typ = PUSTE;
				if (field(x, y).typ == BIALY_PIONEK)
					field(x - 2, y + 2).typ = BIALY_PIONEK;
				else if (field(x, y).typ == CZARNY_PIONEK)
					field(x - 2, y + 2).typ = CZARNY_PIONEK;
				else if (field(x, y).typ == BIALA_DAMKA)
					field(x - 2, y + 2).typ = BIALA_DAMKA;
				else if (field(x, y).typ == CZARNA_DAMKA)
					field(x - 2, y + 2).typ = CZARNA_DAMKA;

				piece(x, y).UsunPionka();							//USUWA PIONKA ZE STAREJ POZYCJI
				piece(x - 2, y + 2).UstawPionka(tura);				//USTAWIA PIONKA NA NOWEJ POZYCJI
				x = -1;
				y = -1;
				tura++;
			}
		}
	}
	}
}
