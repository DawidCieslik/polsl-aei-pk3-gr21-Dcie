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
	const float RozmiarMenuX = 700.f;
	const float RozmiarMenuY = 900.f;
	const float RozmiarOknaX = 900.f;
	const float RozmiarOknaY = 950.f;
	const float RozmiarPola = 100.f;
	const int RozmiarPlanszy = 8;
	const float RozmiarPionka = 25.f;
	sf::Color jasny(238, 232, 170);
	sf::Color ciemny(128, 17, 4);
}