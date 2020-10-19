#include "Gra.h"
#include <iostream>

void Gra(sf::Text& Gracz1, sf::Text& Gracz2, bool& Komputer)
{
	std::string gracz1 = Gracz1.getString();	//NAZWA GRACZA 1
	std::string gracz2 = Gracz2.getString();	//NAZWA GRACZA 2

	int tura = 0;								//KTÓRA TURA Z KOLEI
	int x = -1;								//WSPÓ£RZÊDNA X
	int y = -1;								//WSPÓ£RZÊDNA Y
	bool focus = false;							//FOCUS NA PIONKU
	
	//TEKSTURA T£A - ¯Ó£TE
	sf::Texture Yellow;
	if (!Yellow.loadFromFile("Images/Background1.png"))
		Blad(2);

	//TEKSTURA T£A - TURKUSOWE
	sf::Texture Teal;
	if (!Teal.loadFromFile("Images/Background2.png"))
		Blad(2);

	//TEKSTURA T£A - CZERWONE
	sf::Texture Red;
	if (!Red.loadFromFile("Images/Background3.png"))
		Blad(2);

	//TEKSTURA T£A - ZIELONE
	sf::Texture Green;
	if (!Green.loadFromFile("Images/Background4.png"))
		Blad(2);

	//TEKSTURA T£A - NIEBIESKIE
	sf::Texture Blue;
	if (!Blue.loadFromFile("Images/Background5.png"))
		Blad(2);

	//CZCIONKA
	sf::Font font;
	if (!font.loadFromFile("Fonts/font.otf"))
		Blad(2);

	//IKONA GRACZA 1
	sf::CircleShape white;
	white.setRadius(20);
	white.setOutlineThickness(2);
	white.setOutlineColor(czarny);
	white.setFillColor(bialy);
	white.setPosition(sf::Vector2f(RozmiarOknaX / 2 - 178, 7));
	sf::FloatRect b = white.getGlobalBounds();

	//IKONA GRACZA 2
	sf::CircleShape black;
	black.setRadius(20);
	black.setOutlineThickness(2);
	black.setOutlineColor(czarny);
	black.setFillColor(czarny);
	black.setPosition(sf::Vector2f(RozmiarOknaX / 2 + 135, 7));
	sf::FloatRect c = black.getGlobalBounds();

	//NAPIS "WARCABY"
	std::string s1 = "WARCABY";
	sf::Text tytul(s1, font);
	tytul.setCharacterSize(64);
	sf::FloatRect textCenter1 = tytul.getLocalBounds();
	tytul.setOrigin(textCenter1.left + textCenter1.width / 2, 0);
	tytul.setPosition(sf::Vector2f(RozmiarOknaX / 2, -17));

	//NAPIS "TURA :"
	std::string s2 = "TURA:  ";
	sf::Text turaGracza(s2, font);
	turaGracza.setCharacterSize(50);

	//NAZWA GRACZA 1
	if (gracz1.length() >= 5 && gracz1.length() < 7)
		Gracz1.setCharacterSize(48);
	else if(gracz1.length() >= 7 && gracz1.length() <= 9)
		Gracz1.setCharacterSize(42);
	else if (gracz1.length() > 9 && gracz1.length() <= 11)
		Gracz1.setCharacterSize(36);
	else if (gracz1.length() > 11 && gracz1.length() <= 13)
		Gracz1.setCharacterSize(28);
	Gracz1.setFillColor(bialy);
	sf::FloatRect textCenter3 = Gracz1.getLocalBounds();
	Gracz1.setOrigin(textCenter3.left + textCenter3.width / 2, textCenter3.top + textCenter3.height / 2);
	Gracz1.setPosition(sf::Vector2f(b.left/2, b.top + b.height / 2));

	//NAZWA GRACZA 2
	if (gracz2.length() >= 5 && gracz2.length() < 7)
		Gracz2.setCharacterSize(48);
	else if (gracz2.length() >= 7 && gracz2.length() <= 9)
		Gracz2.setCharacterSize(42);
	else if (gracz2.length() > 9 && gracz2.length() <= 11)
		Gracz2.setCharacterSize(36);
	else if (gracz2.length() > 11 && gracz2.length() <= 13)
		Gracz2.setCharacterSize(28);
	sf::FloatRect textCenter4 = Gracz2.getLocalBounds();
	Gracz2.setOrigin(0, textCenter4.top + textCenter4.height / 2);
	Gracz2.setPosition(sf::Vector2f(b.left + b.width + (c.left + c.width)/2 + 36, c.top + c.height / 2));

	//T£O GRY
	sf::Sprite background;
	background.setTexture(Yellow);
	
	//OKNO GRY
	sf::RenderWindow window{ sf::VideoMode{ 900, 950 }, "Warcaby", sf::Style::Close };
	window.setVerticalSyncEnabled(1);
	sf::Event event;
	window.requestFocus();

	//TWORZENIE PLANSZY
	Plansza plansza;
	plansza.InicjalizujPlansze();

	//POCZ¥TEK PÊTLI
	while (window.isOpen())
	{
		window.clear();

		while (window.pollEvent(event))
		{
			//ZAMKNIÊCIE OKNA GRY
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				window.close();

			//ZMIANA KOLORU T£A - LEWY GÓRNY
			if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
							  sf::Mouse::getPosition(window).x > 0 && sf::Mouse::getPosition(window).x < 50 &&
							  sf::Mouse::getPosition(window).y > 50 && sf::Mouse::getPosition(window).y < 100)
			{
				if (background.getTexture() == &Yellow)
					background.setTexture(Teal);
				else if (background.getTexture() == &Teal)
					background.setTexture(Red);
				else if (background.getTexture() == &Red)
					background.setTexture(Green);
				else if (background.getTexture() == &Green)
					background.setTexture(Blue);
				else if (background.getTexture() == &Blue)
					background.setTexture(Yellow);
			}

			//ZMIANA KOLORU T£A - PRAWY GÓRNY
			if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
							  sf::Mouse::getPosition(window).x > 850 && sf::Mouse::getPosition(window).x < 900 &&
							  sf::Mouse::getPosition(window).y > 50 && sf::Mouse::getPosition(window).y < 100)
			{
				if (background.getTexture() == &Yellow)
					background.setTexture(Red);
				else if (background.getTexture() == &Teal)
					background.setTexture(Green);
				else if (background.getTexture() == &Red)
					background.setTexture(Blue);
				else if (background.getTexture() == &Green)
					background.setTexture(Yellow);
				else if (background.getTexture() == &Blue)
					background.setTexture(Teal);
			}

			//ZMIANA KOLORU T£A - PRAWY DOLNY
			if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
							  sf::Mouse::getPosition(window).x > 850 && sf::Mouse::getPosition(window).x < 900 &&
							  sf::Mouse::getPosition(window).y > 900 && sf::Mouse::getPosition(window).y < 950)
			{
				if (background.getTexture() == &Yellow)
					background.setTexture(Green);
				else if (background.getTexture() == &Teal)
					background.setTexture(Blue);
				else if (background.getTexture() == &Red)
					background.setTexture(Yellow);
				else if (background.getTexture() == &Green)
					background.setTexture(Teal);
				else if (background.getTexture() == &Blue)
					background.setTexture(Red);
			}

			//ZMIANA KOLORU T£A - LEWY DOLNY
			if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
							  sf::Mouse::getPosition(window).x > 0 && sf::Mouse::getPosition(window).x < 50 &&
							  sf::Mouse::getPosition(window).y > 900 && sf::Mouse::getPosition(window).y < 950)
			{
				if (background.getTexture() == &Yellow)
					background.setTexture(Blue);
				else if (background.getTexture() == &Teal)
					background.setTexture(Yellow);
				else if (background.getTexture() == &Red)
					background.setTexture(Teal);
				else if (background.getTexture() == &Green)
					background.setTexture(Red);
				else if (background.getTexture() == &Blue)
					background.setTexture(Green);
			}

			//ODCZYTYWANIE WSPÓ£RZÊDNYCH ZAZNACZONEGO PIONKA
			if (focus == false && event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
												sf::Mouse::getPosition(window).x > 50 && sf::Mouse::getPosition(window).x < 850 &&
												sf::Mouse::getPosition(window).y > 100 && sf::Mouse::getPosition(window).y < 900 )
			{
				//USTAWIA WSPÓ£RZÊDNE X I Y W MIEJSCU ZAZNACZONEGO PIONKA
				x = (sf::Mouse::getPosition(window).x - 50) / RozmiarPola;
				y = (sf::Mouse::getPosition(window).y - 100) / RozmiarPola;

				//USTAWIA FOCUS NA KLIKNIÊTYM PIONKU
				if (tura % 2 == 0)												//TURA GRACZA BIA£EGO
				{
					if (field(x, y).typ == BIALY_PIONEK || field(x, y).typ == BIALA_DAMKA)
						focus = true;
				}
				else if (tura % 2 == 1)											//TURA GRACZA CZARNEGO
				{
					if (field(x, y).typ == CZARNY_PIONEK || field(x, y).typ == CZARNA_DAMKA)
						focus = true;
				}
			}

			//ODZNACZENIE PIONKA
			if (focus == true && event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Right))
				focus = false;

			//PRZESUNIÊCIE PIONKA NA NOWE POLE
			if (focus == true)
			{
				if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
								  sf::Mouse::getPosition(window).x > (100 * x) - 50 && sf::Mouse::getPosition(window).x < (100 * x) + 50 &&
								  sf::Mouse::getPosition(window).y > 100 * y && sf::Mouse::getPosition(window).y < (100 * y) + 100)
				{
					if (field(x, y).typ == BIALY_PIONEK || field(x, y).typ == BIALA_DAMKA ||
						field(x, y).typ == CZARNY_PIONEK || field(x, y).typ == CZARNA_DAMKA)
					{
						//GÓRNA LEWA PRZEK¥TNA
						if (x != 0 && y != 0 && field(x - 1, y - 1).typ == PUSTE)
						{
							//piece(x, y).setOutlineColor(czarny);

							if (x != 0 && y != 0 && field(x - 1, y - 1).typ == PUSTE)
								field(x - 1, y - 1).Kolor(ciemny);				//GÓRNA LEWA PRZEK¥TNA PUSTA
							else if (x != 0 && y != 0 && (field(x - 1, y - 1).typ == CZARNY_PIONEK || field(x - 1, y - 1).typ == CZARNA_DAMKA))
								field(x - 2, y - 2).Kolor(ciemny);				//PIONEK PRZECIWNIKA NA GÓRNEJ LEWEJ PRZEKATNEJ
							if (x != 7 && y != 0 && field(x + 1, y - 1).typ == PUSTE)
								field(x + 1, y - 1).Kolor(ciemny);				//GÓRNA PRAWA PRZEK¥TNA PUSTA
							else if (x != 7 && y != 0 && (field(x + 1, y - 1).typ == CZARNY_PIONEK || field(x + 1, y - 1).typ == CZARNA_DAMKA))
								field(x + 2, y - 2).Kolor(ciemny);				//PIONEK PRZECIWNIKA NA GÓRNEJ PRAWEJ PRZEKATNEJ

							//ZMIANA TYPU POLA
							if (field(x, y).typ == BIALY_PIONEK)
								field(x - 1, y - 1).typ = BIALY_PIONEK;
							else if (field(x, y).typ == BIALA_DAMKA)
								field(x - 1, y - 1).typ = BIALA_DAMKA;
							else if (field(x, y).typ == CZARNA_DAMKA)
								field(x - 1, y - 1).typ = CZARNA_DAMKA;

							piece(x, y).Pozycja(x - 0.5f, y);
							std::cout << x - 1 << " " << piece(x, y).PodajX() << std::endl;
							piece(x, y).UstawX(x - 1);
							std::cout << x - 1 << " " << piece(x, y).PodajX() << std::endl;
							piece(x, y).UstawY(y - 1);
							std::cout << y - 1 << " " << piece(x, y).PodajY() << std::endl;
							//tura++;
							focus = false;
							x = -1;
							y = -1;
						}
					}
				}
			}
		}

		//RYSOWANIE MO¯LIWYCH RUCHÓW PIONKA
		if (focus == true && (x != -1 || y != -1))
		{
			if (field(x, y).typ != JASNE && field(x, y).typ != PUSTE)
			{
				//piece(x, y).setOutlineColor(sf::Color::Red);

				//BIA£Y PIONEK
				if (field(x, y).typ == BIALY_PIONEK)
				{
					if (x != 0 && y != 0 && field(x - 1, y - 1).typ == PUSTE)
						field(x - 1, y - 1).Kolor(sf::Color::Red);				//GÓRNA LEWA PRZEK¥TNA PUSTA
					else if (x != 0 && y != 0 && (field(x - 1, y - 1).typ == CZARNY_PIONEK || field(x - 1, y - 1).typ == CZARNA_DAMKA))
						field(x - 2, y - 2).Kolor(sf::Color::Red);				//PIONEK PRZECIWNIKA NA GÓRNEJ LEWEJ PRZEKATNEJ
					if (x != 7 && y != 0 && field(x + 1, y - 1).typ == PUSTE)
						field(x + 1, y - 1).Kolor(sf::Color::Red);				//GÓRNA PRAWA PRZEK¥TNA PUSTA
					else if (x != 7 && y != 0 && (field(x + 1, y - 1).typ == CZARNY_PIONEK || field(x + 1, y - 1).typ == CZARNA_DAMKA))
						field(x + 2, y - 2).Kolor(sf::Color::Red);				//PIONEK PRZECIWNIKA NA GÓRNEJ PRAWEJ PRZEKATNEJ
				}

				//BIA£A DAMKA
				if (field(x, y).typ == BIALA_DAMKA)
				{
					if (x != 0 && y != 7 && field(x - 1, y + 1).typ == PUSTE)
						field(x - 1, y + 1).Kolor(sf::Color::Red);				//DOLNA LEWA PRZEK¥TNA PUSTA
					else if (x != 0 && y != 7 && (field(x - 1, y + 1).typ == CZARNY_PIONEK || field(x - 1, y + 1).typ == CZARNA_DAMKA))
						field(x - 2, y + 2).Kolor(sf::Color::Red);				//PIONEK PRZECIWNIKA NA DOLNEJ LEWEJ PRZEKATNEJ
					if (x != 7 && y != 7 && field(x + 1, y + 1).typ == PUSTE)
						field(x + 1, y + 1).Kolor(sf::Color::Red);				//DOLNA PRAWA PRZEK¥TNA PUSTA
					else if (x != 7 && y != 7 && (field(x + 1, y + 1).typ == CZARNY_PIONEK || field(x + 1, y + 1).typ == CZARNA_DAMKA))
						field(x + 2, y + 2).Kolor(sf::Color::Red);				//PIONEK PRZECIWNIKA NA DOLNEJ PRAWEJ PRZEKATNEJ
					if (x != 0 && y != 0 && field(x - 1, y - 1).typ == PUSTE)
						field(x - 1, y - 1).Kolor(sf::Color::Red);				//GÓRNA LEWA PRZEK¥TNA PUSTA
					else if (x != 0 && y != 0 && (field(x - 1, y - 1).typ == CZARNY_PIONEK || field(x - 1, y - 1).typ == CZARNA_DAMKA))
						field(x - 2, y - 2).Kolor(sf::Color::Red);				//PIONEK PRZECIWNIKA NA GÓRNEJ LEWEJ PRZEKATNEJ
					if (x != 7 && y != 0 && field(x + 1, y - 1).typ == PUSTE)
						field(x + 1, y - 1).Kolor(sf::Color::Red);				//GÓRNA PRAWA PRZEK¥TNA PUSTA
					else if (x != 7 && y != 0 && (field(x + 1, y - 1).typ == CZARNY_PIONEK || field(x + 1, y - 1).typ == CZARNA_DAMKA))
						field(x + 2, y - 2).Kolor(sf::Color::Red);				//PIONEK PRZECIWNIKA NA GÓRNEJ PRAWEJ PRZEKATNEJ
				}

				//CZARNY PIONEK
				if (field(x, y).typ == CZARNY_PIONEK)
				{
					if (x != 0 && y != 7 && field(x - 1, y + 1).typ == PUSTE)
						field(x - 1, y + 1).Kolor(sf::Color::Red);				//DOLNA LEWA PRZEK¥TNA PUSTA
					else if (x != 0 && y != 7 && (field(x - 1, y + 1).typ == BIALY_PIONEK || field(x - 1, y + 1).typ == BIALA_DAMKA))
						field(x - 2, y + 2).Kolor(sf::Color::Red);				//PIONEK PRZECIWNIKA NA DOLNEJ LEWEJ PRZEKATNEJ
					if (x != 7 && y != 7 && field(x + 1, y + 1).typ == PUSTE)
						field(x + 1, y + 1).Kolor(sf::Color::Red);				//DOLNA PRAWA PRZEK¥TNA PUSTA
					else if (x != 7 && y != 7 && (field(x + 1, y + 1).typ == BIALY_PIONEK || field(x + 1, y + 1).typ == BIALA_DAMKA))
						field(x + 2, y + 2).Kolor(sf::Color::Red);				//PIONEK PRZECIWNIKA NA DOLNEJ PRAWEJ PRZEKATNEJ
				}

				//CZARNA DAMKA
				if (field(x, y).typ == CZARNA_DAMKA)
				{
					if (x != 0 && y != 7 && field(x - 1, y + 1).typ == PUSTE)
						field(x - 1, y + 1).Kolor(sf::Color::Red);				//DOLNA LEWA PRZEK¥TNA PUSTA
					else if (x != 0 && y != 7 && (field(x - 1, y + 1).typ == BIALY_PIONEK || field(x - 1, y + 1).typ == BIALA_DAMKA))
						field(x - 2, y + 2).Kolor(sf::Color::Red);				//PIONEK PRZECIWNIKA NA DOLNEJ LEWEJ PRZEKATNEJ
					if (x != 7 && y != 7 && field(x + 1, y + 1).typ == PUSTE)
						field(x + 1, y + 1).Kolor(sf::Color::Red);				//DOLNA PRAWA PRZEK¥TNA PUSTA
					else if (x != 7 && y != 7 && (field(x + 1, y + 1).typ == BIALY_PIONEK || field(x + 1, y + 1).typ == BIALA_DAMKA))
						field(x + 2, y + 2).Kolor(sf::Color::Red);				//PIONEK PRZECIWNIKA NA DOLNEJ PRAWEJ PRZEKATNEJ
					if (x != 0 && y != 0 && field(x - 1, y - 1).typ == PUSTE)
						field(x - 1, y - 1).Kolor(sf::Color::Red);				//GÓRNA LEWA PRZEK¥TNA PUSTA
					else if (x != 0 && y != 0 && (field(x - 1, y - 1).typ == BIALY_PIONEK || field(x - 1, y - 1).typ == BIALA_DAMKA))
						field(x - 2, y - 2).Kolor(sf::Color::Red);				//PIONEK PRZECIWNIKA NA GÓRNEJ LEWEJ PRZEKATNEJ
					if (x != 7 && y != 0 && field(x + 1, y - 1).typ == PUSTE)
						field(x + 1, y - 1).Kolor(sf::Color::Red);				//GÓRNA PRAWA PRZEK¥TNA PUSTA
					else if (x != 7 && y != 0 && (field(x + 1, y - 1).typ == BIALY_PIONEK || field(x + 1, y - 1).typ == BIALA_DAMKA))
						field(x + 2, y - 2).Kolor(sf::Color::Red);				//PIONEK PRZECIWNIKA NA GÓRNEJ PRAWEJ PRZEKATNEJ
				}
			}
		}

		//ODZNACZENIE MO¯LIWYCH RUCHÓW PIONKA
		if (focus == false && (x != -1 || y != -1))
		{
			if (field(x, y).typ != JASNE && field(x, y).typ != PUSTE)
			{
				//piece(x, y).setOutlineColor(czarny);

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

		window.draw(background);				//RYSUJE T£O GRY
		window.draw(tytul);						//RYSUJE TYTU£ GRY
		window.draw(turaGracza);				//RYSUJE BIE¯¥C¥ TURÊ
		window.draw(white);						//RYSUJE IKONÊ GRACZA 1
		window.draw(black);						//RYSUJE IKONÊ GRACZA 2
		window.draw(Gracz1);					//RYSUJE NAZWÊ GRACZA 1
		window.draw(Gracz2);					//RYSUJE NAZWÊ GRACZA 2
		plansza.WyswietlPlansze(window);		//RYSUJE PLANSZÊ
		plansza.RysujPionki(window);			//RYSUJE PIONKI

		window.display();						//WYŒWIETLA GRÊ
	}
}