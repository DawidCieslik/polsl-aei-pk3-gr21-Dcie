#pragma once

enum class TypPionka
{
	PUSTE = 0,
	CZARNY = 1,
	BIALY = 2,
	CZARNY_DAMKA = 3,
	BIALY_DAMKA = 4,
	INVALID = -1,
};

namespace
{
	const int RozmiarOknaX = 900;
	const int RozmiarOknaY = 950;
	const int RozmiarPola = 100;
	const int RozmiarPlanszy = 8;
	const int RozmiarPionka = 25;
	sf::Color jasny(238, 232, 170);
	sf::Color ciemny(128, 17, 4);
}