#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Enums.h"
#include "Plansza.h"

void Zaznacz(int& x, int& y, Plansza& plansza);
void UsunZaznaczenie(int &x, int &y, Plansza& plansza);
void ZmienKolorNaglowka(int& tura, std::string& s2, std::string& gracz1, std::string& gracz2, sf::Text& turaGracza, sf::Text& tytul);
void PrzesunPionka(Plansza& plansza, int& tura, int& x, int& y, Kierunek& kierunek);