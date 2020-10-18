#include "Gra.h"

void Gra(sf::Text& Gracz1, sf::Text& Gracz2, bool& Komputer)
{
	std::string gracz1 = Gracz1.getString();	//Nazwa Gracza 1
	std::string gracz2 = Gracz2.getString();	//Nazwa Gracza 2
	
	//TEKSTURA JASNEGO POLA
	sf::Texture jasne;
	if (!jasne.loadFromFile("Images/JasnePole.png"))
		Blad(2);

	//TEKSTURA CIEMNEGO POLA
	sf::Texture ciemne;
	if (!ciemne.loadFromFile("Images/CiemnePole.png"))
		Blad(2);

	//TEKSTURA BIA£EGO PIONKA
	sf::Texture biale;
	if (!biale.loadFromFile("Images/Bialy.png"))
		Blad(2);

	//TEKSTURA CZARNEGO PIONKA
	sf::Texture czarne;
	if (!czarne.loadFromFile("Images/Czarny.png"))
		Blad(2);
	
	//TEKSTURA T£A
	sf::Texture TeksturaTla;
	if (!TeksturaTla.loadFromFile("Images/Background.jpg"))
		Blad(2);
	sf::Sprite Background;
	Background.setTexture(TeksturaTla);

	//CZCIONKA
	sf::Font font;
	if (!font.loadFromFile("Fonts/font.otf"))
		Blad(2);

	//IKONA GRACZA 1
	sf::CircleShape bialy;
	bialy.setRadius(24.f);
	bialy.setOutlineThickness(1);
	bialy.setOutlineColor(sf::Color::Black);
	bialy.setFillColor(sf::Color::White);
	bialy.setPosition(sf::Vector2f(RozmiarOknaX / 2.f - 205.f, 3.f));
	sf::FloatRect b = bialy.getGlobalBounds();

	//IKONA GRACZA 2
	sf::CircleShape czarny;
	czarny.setRadius(24.f);
	czarny.setOutlineThickness(1);
	czarny.setOutlineColor(sf::Color::White);
	czarny.setFillColor(sf::Color::Black);
	czarny.setPosition(sf::Vector2f(RozmiarOknaX / 2.f + 155.f, 3.f));
	sf::FloatRect c = czarny.getGlobalBounds();

	//NAPIS "WARCABY"
	std::string s1 = "WARCABY";
	sf::Text tytul(s1, font);
	tytul.setCharacterSize(70);
	tytul.setFillColor(sf::Color::Black);
	sf::FloatRect textCenter1 = tytul.getLocalBounds();
	tytul.setOrigin(textCenter1.left + textCenter1.width / 2.f, 0.f);
	tytul.setPosition(sf::Vector2f(RozmiarOknaX / 2.f, -20.f));

	//NAPIS "TURA :"
	std::string s2 = "TURA:  ";
	s2 += gracz1;
	sf::Text tura(s2, font);
	tura.setCharacterSize(50);
	tura.setFillColor(sf::Color::Red);
	sf::FloatRect textCenter2 = tura.getLocalBounds();
	tura.setOrigin(textCenter2.left + textCenter2.width / 2.f, 0.f);
	tura.setPosition(sf::Vector2f(RozmiarOknaX / 2.f, 40.f));

	//NAZWA GRACZA 1
	if (gracz1.length() >= 5 && gracz1.length() < 7)
		Gracz1.setCharacterSize(48.f);
	else if(gracz1.length() >= 7 && gracz1.length() <= 9)
		Gracz1.setCharacterSize(40.f);
	else if (gracz1.length() > 9 && gracz1.length() <= 11)
		Gracz1.setCharacterSize(32.f);
	else if (gracz1.length() > 11 && gracz1.length() <= 13)
		Gracz1.setCharacterSize(24.f);
	Gracz1.setFillColor(sf::Color::Red);
	sf::FloatRect textCenter3 = Gracz1.getLocalBounds();
	Gracz1.setOrigin(textCenter3.left + textCenter3.width / 2.f, textCenter3.top + textCenter3.height / 2.f);
	Gracz1.setPosition(sf::Vector2f(b.left/2.f, b.top + b.height / 2.f));

	//NAZWA GRACZA 2
	if (gracz2.length() >= 5 && gracz2.length() < 7)
		Gracz2.setCharacterSize(48.f);
	else if (gracz2.length() >= 7 && gracz2.length() <= 9)
		Gracz2.setCharacterSize(40.f);
	else if (gracz2.length() > 9 && gracz2.length() <= 11)
		Gracz2.setCharacterSize(32.f);
	else if (gracz2.length() > 11 && gracz2.length() <= 13)
		Gracz2.setCharacterSize(24.f);
	sf::FloatRect textCenter4 = Gracz2.getLocalBounds();
	Gracz2.setOrigin(textCenter4.left + textCenter4.width / 2.f, textCenter4.top + textCenter4.height / 2.f);
	Gracz2.setPosition(sf::Vector2f(778.f, c.top + c.height / 2.f));
	
	//OKNO GRY
	sf::RenderWindow window{ sf::VideoMode{ 900, 950 }, "Warcaby", sf::Style::Close };
	window.setVerticalSyncEnabled(1);
	sf::Event event;
	window.requestFocus();

	//TWORZENIE PLANSZY
	Plansza plansza;
	plansza.InicjalizujPlansze();

	//USTAWIANIE TEKSTUR
	for (int y = 0; y < RozmiarPlanszy; y++)
	{
		for (int x = 0; x < RozmiarPlanszy; x++)
		{
			if ((x + y) % 2 == 0)
				plansza.DajPole(x, y).Tekstura(&jasne);
			else if ((x + y) % 2 != 0)
			{
				plansza.DajPole(x, y).Tekstura(&ciemne);
				if (y >= 0 && y <= 2)
					plansza.DajPionek(x, y).Tekstura(&biale);
				else if (y >= 5 && y<=RozmiarPlanszy)
					plansza.DajPionek(x, y).Tekstura(&czarne);
			}	
		}
	}

	//POCZ¥TEK PÊTLI
	while (window.isOpen())
	{
		window.clear();
		while (window.pollEvent(event))
		{
			//ZAMKNIÊCIE OKNA GRY
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				window.close();
		}
		
		window.draw(Background);				//RYSUJE T£O
		window.draw(tytul);						//RYSUJE TYTU£ GRY
		window.draw(tura);						//RYSUJE BIE¯¥C¥ TURÊ
		window.draw(bialy);						//RYSUJE IKONÊ GRACZA 1
		window.draw(czarny);					//RYSUJE IKONÊ GRACZA 2
		window.draw(Gracz1);					//RYSUJE NAZWÊ GRACZA 1
		window.draw(Gracz2);					//RYSUJE NAZWÊ GRACZA 2
		plansza.WyswietlPlansze(window);		//RYSUJE PLANSZÊ
		window.display();						//WYŒWIETLA GRÊ
	}
}