#include "Gra.h"
#include <iostream>

void Gra(sf::Text& Gracz1, sf::Text& Gracz2, bool& Komputer)
{
	std::string gracz1 = Gracz1.getString();	//NAZWA GRACZA 1
	std::string gracz2 = Gracz2.getString();	//NAZWA GRACZA 2

	int tura = 0;								//KTÓRA TURA Z KOLEI
	int x = -1;									//WSPÓ£RZÊDNA X
	int y = -1;									//WSPÓ£RZÊDNA Y
	int NoweX = -1;								//NOWA WSPÓ£RZÊDNA X
	int NoweY = -1;								//NOWA WSPÓ£RZÊDNA Y
	bool focus = false;							//FOCUS NA PIONKU
	Kierunek kierunek = Kierunek::BRAK;			//KIERUNEK PRZESUNIÊCIA PIONKA
	
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
			if (focus == false)
			{
				if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
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
			}

			if (focus == true)
			{
				//ODZNACZENIE PIONKA
				if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Right))
					focus = false;

				//PRZESUNIÊCIE PIONKA NA NOWE POLE
				if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (sf::Mouse::getPosition(window).x > 100 * x - 50 && sf::Mouse::getPosition(window).x < 100 * x + 50 &&
						sf::Mouse::getPosition(window).y > 100 * y && sf::Mouse::getPosition(window).y < 100 * y + 100)
						kierunek = GL;
					else if (sf::Mouse::getPosition(window).x > 100 * x + 150 && sf::Mouse::getPosition(window).x < 100 * x + 250 &&
						sf::Mouse::getPosition(window).y > 100 * y && sf::Mouse::getPosition(window).y < 100 * y + 100)
						kierunek = GP;
					else if (sf::Mouse::getPosition(window).x > 100 * x + 150 && sf::Mouse::getPosition(window).x < 100 * x + 250 &&
						sf::Mouse::getPosition(window).y > 100 * y + 200 && sf::Mouse::getPosition(window).y < 100 * y + 300)
						kierunek = DP;
					else if (sf::Mouse::getPosition(window).x > 100 * x - 50 && sf::Mouse::getPosition(window).x < 100 * x + 50 &&
						sf::Mouse::getPosition(window).y > 100 * y + 200 && sf::Mouse::getPosition(window).y < 100 * y + 300)
						kierunek = DL;
					else if (sf::Mouse::getPosition(window).x > 100 * x - 150 && sf::Mouse::getPosition(window).x < 100 * x - 50 &&
						sf::Mouse::getPosition(window).y > 100 * y - 100 && sf::Mouse::getPosition(window).y < 100 * y)
						kierunek = GL2;
					else if (sf::Mouse::getPosition(window).x > 100 * x + 150 && sf::Mouse::getPosition(window).x < 100 * x + 250 &&
						sf::Mouse::getPosition(window).y > 100 * y - 100 && sf::Mouse::getPosition(window).y < 100 * y)
						kierunek = GP2;
					else if (sf::Mouse::getPosition(window).x > 100 * x + 150 && sf::Mouse::getPosition(window).x < 100 * x + 250 &&
						sf::Mouse::getPosition(window).y > 100 * y + 300 && sf::Mouse::getPosition(window).y < 100 * y + 400)
						kierunek = DP2;
					else if (sf::Mouse::getPosition(window).x > 100 * x - 150 && sf::Mouse::getPosition(window).x < 100 * x - 50 &&
						sf::Mouse::getPosition(window).y > 100 * y + 300 && sf::Mouse::getPosition(window).y < 100 * y + 400)
						kierunek = DL2;
					std::cout << x << " " << y << std::endl;
					switch (kierunek)
					{
					case GL: std::cout << "1";
					case GP: std::cout << "2";
					case DP: std::cout << "3";
					case DL: std::cout << "4";
					case GL2: std::cout << "5";
					case GP2: std::cout << "6";
					case DP2: std::cout << "7";
					case DL2: std::cout << "8";
					default: std::cout << "9";
					}
					PrzesunPionka(plansza, tura, x, y, kierunek);
					focus = false;
				}
			}
		}
		
		if (focus == true)
			Zaznacz(x, y, plansza);

		ZmienKolorNaglowka(tura, s2, gracz1, gracz2, turaGracza, tytul);

		window.draw(background);				//RYSUJE T£O GRY
		window.draw(tytul);						//RYSUJE TYTU£ GRY
		window.draw(turaGracza);				//RYSUJE BIE¯¥C¥ TURÊ
		window.draw(white);						//RYSUJE IKONÊ GRACZA 1
		window.draw(black);						//RYSUJE IKONÊ GRACZA 2
		window.draw(Gracz1);					//RYSUJE NAZWÊ GRACZA 1
		window.draw(Gracz2);					//RYSUJE NAZWÊ GRACZA 2
		plansza.WyswietlPlansze(window);		//RYSUJE PLANSZÊ

		window.display();						//WYŒWIETLA GRÊ
	}
}