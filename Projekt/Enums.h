#pragma once

#define piece plansza.DajPionek
#define field plansza.DajPole

#define bialy sf::Color::White
#define czarny sf::Color::Black

#define JASNE TypPola::INVALID
#define PUSTE TypPola::EMPTY
#define BIALY_PIONEK TypPola::WHITE
#define CZARNY_PIONEK TypPola::BLACK
#define BIALA_DAMKA TypPola::WHITE_KING
#define CZARNA_DAMKA TypPola::BLACK_KING

enum class TypPola
{
	INVALID,
	EMPTY,
	WHITE,
	BLACK,
	WHITE_KING,
	BLACK_KING
};

namespace
{
	const int RozmiarPlanszy = 8;
	const int RozmiarMenuX = 700;
	const int RozmiarMenuY = 900;
	const int RozmiarOknaX = 900;
	const int RozmiarOknaY = 950;
	const int RozmiarPola = 100;
	const int RozmiarPionka = 35;
	sf::Color jasny(238, 232, 170);
	sf::Color ciemny(92, 17, 9);
	sf::Color szary(127, 127, 127);
}