#include "menu.h"
void menu1()
{
	//CZCIONKA
	sf::Font font;		
	if (!font.loadFromFile("Fonts/font.otf"))
		Blad(2);
	
	//NAG£ÓWEK
	std::string s1 = "WYBIERZ   TRYB";
	sf::Text Naglowek(s1, font);
	Naglowek.setCharacterSize(80);
	Naglowek.setFillColor(czarny);
	sf::FloatRect textCenter1 = Naglowek.getLocalBounds();
	Naglowek.setOrigin(textCenter1.left + textCenter1.width / 2, 0);
	Naglowek.setPosition(sf::Vector2f(RozmiarMenuX / 2, 20));

	//NAPIS "DWÓCH GRACZY"
	std::string s2 = "Komputer";
	sf::Text Komp(s2, font);
	Komp.setCharacterSize(60);
	Komp.setFillColor(czarny);
	sf::FloatRect textCenter2 = Komp.getLocalBounds();
	Komp.setOrigin(textCenter2.left + textCenter2.width / 2, 0);
	Komp.setPosition(sf::Vector2f(RozmiarMenuX / 2, 140));

	//NAPIS "DWÓCH GRACZY"
	std::string s3 = "Dwóch  graczy";
	sf::Text Gracz(s3, font);
	Gracz.setCharacterSize(60);
	Gracz.setFillColor(czarny);
	sf::FloatRect textCenter3 = Gracz.getLocalBounds();
	Gracz.setOrigin(textCenter3.left + textCenter3.width / 2, 0);
	Gracz.setPosition(sf::Vector2f(RozmiarMenuX / 2, 520));

	//T£O MENU
	sf::Texture Back;
	if (!Back.loadFromFile("Images/Menu.jpg"))
		Blad(2);
	sf::Sprite Background;
	Background.setTexture(Back);

	//IKONA DLA KOMPUTERA
	sf::Texture Comp;
	if (!Comp.loadFromFile("Images/Komputer.png"))
		Blad(2);
	sf::Sprite CompIcon;
	CompIcon.setTexture(Comp);
	CompIcon.setScale(sf::Vector2f(0.55f, 0.55f));
	sf::FloatRect Center2 = CompIcon.getLocalBounds();
	CompIcon.setOrigin(Center2.left + Center2.width / 2, Center2.top + Center2.height / 2);
	CompIcon.setPosition(sf::Vector2f(RozmiarMenuX/2, RozmiarMenuY/2 - 150));

	//IKONA DLA DWÓCH GRACZY
	sf::Texture TwoPlayers;
	if (!TwoPlayers.loadFromFile("Images/TwoPlayers.png"))
		Blad(2);
	sf::Sprite TwoPlayersIcon;
	TwoPlayersIcon.setTexture(TwoPlayers);
	sf::FloatRect Center3 = TwoPlayersIcon.getLocalBounds();
	TwoPlayersIcon.setOrigin(Center3.left + Center3.width / 2, Center3.top + Center3.height / 2);
	TwoPlayersIcon.setPosition(sf::Vector2f(RozmiarMenuX/2, RozmiarMenuY/2+260));

	//OKNO MENU
	sf::RenderWindow window{ sf::VideoMode{ 700, 900 }, "Warcaby - menu", sf::Style::Close };
	window.setVerticalSyncEnabled(1);
	sf::Event event;
	window.requestFocus();

	//POCZ¥TEK PÊTLI
	while (window.isOpen())
	{
		window.clear();
		while (window.pollEvent(event))
		{
			//ZAMKNIÊCIE OKNA
			if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)))
				window.close();
			if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(sf::Mouse::getPosition(window).x > 190 && sf::Mouse::getPosition(window).x < 525 &&
					sf::Mouse::getPosition(window).y > 200 && sf::Mouse::getPosition(window).y < 420))
			{
				window.close();
				menu2(true);
			}
			if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
							 (sf::Mouse::getPosition(window).x > 190 && sf::Mouse::getPosition(window).x < 525 &&
							  sf::Mouse::getPosition(window).y > 580 && sf::Mouse::getPosition(window).y < 826))
			{
				window.close();
				menu2(false);
			}
		}

		window.draw(Background);
		window.draw(Naglowek);
		window.draw(Komp);
		window.draw(CompIcon);
		window.draw(Gracz);
		window.draw(TwoPlayersIcon);

		window.display();
	}
}

void menu2(bool Komputer)
{
	bool focus1 = true;		//FOCUS NA POLU TEKSTOWYM 1
	bool focus2 = false;	//FOCUS NA POLU TEKSTOWYM 2

	sf::Font font;			//CZCIONKA
	if (!font.loadFromFile("Fonts/font.otf"))
		Blad(2);

	std::string str1;		//STRING NAZWY GRACZA 1
	std::string str2;		//STRING NAZWY GRACZA 2
	sf::Text Gracz;			//NAZWA GRACZA
	int licznik = 0;		//DO ZMIANY KOLORU

	//POLE TEKSTOWE 1
	sf::RectangleShape prostokat1;
	prostokat1.setSize(sf::Vector2f(500, 50));
	prostokat1.setOrigin(sf::Vector2f(250, 25));
	prostokat1.setFillColor(bialy);
	prostokat1.setOutlineColor(szary);
	prostokat1.setOutlineThickness(2);
	if (Komputer == false)
		prostokat1.setPosition(RozmiarMenuX / 2, 230);
	else if (Komputer == true)
		prostokat1.setPosition(RozmiarMenuX / 2, RozmiarMenuY / 2 - 120);
	sf::FloatRect p1 = prostokat1.getGlobalBounds();

	//POLE TEKSTOWE 2
	sf::RectangleShape prostokat2;
	prostokat2.setSize(sf::Vector2f(500, 50));
	prostokat2.setOrigin(sf::Vector2f(250, 25));
	prostokat2.setFillColor(bialy);
	prostokat2.setOutlineColor(szary);
	prostokat2.setOutlineThickness(2);
	prostokat2.setPosition(RozmiarMenuX / 2, RozmiarMenuY / 2 + 95);
	sf::FloatRect p2 = prostokat2.getGlobalBounds();

	//NAZWA GRACZA 1
	sf::Text Gracz1;
	Gracz1.setFont(font);
	Gracz1.setCharacterSize(50);
	Gracz1.setFillColor(czarny);
	Gracz1.setString("Bialy");
	if (Komputer == false)
		Gracz1.setPosition(sf::Vector2f(p1.left + 15, p1.top - 8));
	else if (Komputer == true)
		Gracz1.setPosition(sf::Vector2f(p1.left + 15, p1.top - 8));

	Gracz = Gracz1; //Gra z komputerem

	//NAZWA GRACZA 2
	sf::Text Gracz2;
	Gracz2.setFont(font);
	Gracz2.setCharacterSize(50);
	Gracz2.setFillColor(czarny);
	if (Komputer == false) Gracz2.setString("Czarny");
	else if (Komputer == true) Gracz2.setString("Komputer");
	Gracz2.setPosition(sf::Vector2f(p2.left + 15,  p2.top + p2.height / 2 - 36));

	//NAG£ÓWEK
	std::string s1 = "WPISZ  NAZWE";
	sf::Text Naglowek(s1, font);
	Naglowek.setCharacterSize(100);
	Naglowek.setFillColor(czarny);
	sf::FloatRect textCenter1 = Naglowek.getLocalBounds();
	Naglowek.setOrigin(textCenter1.left + textCenter1.width / 2, 0);
	Naglowek.setPosition(sf::Vector2f(RozmiarMenuX / 2, 0));

	//NAPIS "GRACZ 1" (GRA DWUOSOBOWA) LUB "NAZWA GRACZA" (GRA Z KOMPUTEREM)
	std::string s2;
	if (Komputer == false) s2 = "GRACZ  1";
	else if (Komputer == true) s2 = "NAZWA  GRACZA";
	sf::Text G1(s2, font);
	G1.setCharacterSize(60);
	G1.setFillColor(czarny);
	sf::FloatRect textCenter2 = G1.getLocalBounds();
	G1.setOrigin(textCenter2.left + textCenter2.width / 2, 0);
	if (Komputer == false)
		G1.setPosition(sf::Vector2f(RozmiarMenuX / 2, 132.5f));
	else if (Komputer == true)
		G1.setPosition(sf::Vector2f(RozmiarMenuX / 2, RozmiarMenuY/2 - 220));

	//NAPIS "GRACZ 2"
	std::string s3 = "GRACZ  2";
	sf::Text G2(s3, font);
	G2.setCharacterSize(60);
	G2.setFillColor(czarny);
	sf::FloatRect textCenter3 = G2.getLocalBounds();
	G2.setOrigin(textCenter3.left + textCenter3.width / 2, 0);
	G2.setPosition(sf::Vector2f(RozmiarMenuX / 2, 446));

	//NAPIS "DALEJ"
	std::string s4 = "DALEJ";
	sf::Text Dalej(s4, font);
	Dalej.setCharacterSize(100);
	Dalej.setFillColor(ciemny);
	sf::FloatRect textCenter4 = Dalej.getGlobalBounds();
	Dalej.setPosition(sf::Vector2f(RozmiarMenuX - textCenter4.width - 30, RozmiarMenuY - textCenter4.height - 50));

	//T£O MENU
	sf::Texture Back;
	if (!Back.loadFromFile("Images/Menu.jpg"))
		Blad(2);
	sf::Sprite Background;
	Background.setTexture(Back);

	//BIA£Y PIONEK
	sf::Texture White;
	if (!White.loadFromFile("Images/Bialy.png"))
		Blad(2);
	sf::Sprite Bialy;
	Bialy.setTexture(White);
	sf::FloatRect Center1 = Bialy.getLocalBounds();
	if (Komputer == false)
		Bialy.setScale(sf::Vector2f(0.4f, 0.4f));
	else if (Komputer == true)
		Bialy.setScale(sf::Vector2f(0.5f, 0.5f));
	Bialy.setOrigin(Center1.left + Center1.width / 2, Center1.top + Center1.height / 2);
	if (Komputer == false)
		Bialy.setPosition(sf::Vector2f(RozmiarMenuX / 2, RozmiarMenuY / 2 - 100));
	else if (Komputer == true)
		Bialy.setPosition(sf::Vector2f(RozmiarMenuX / 2, RozmiarMenuY / 2 + 40 ));

	//CZARNY PIONEK
	sf::Texture Black;
	if (!Black.loadFromFile("Images/Czarny.png"))
		Blad(2);
	sf::Sprite Czarny;
	Czarny.setTexture(Black);
	sf::FloatRect Center2 = Czarny.getLocalBounds();
	if (Komputer == false)
		Czarny.setScale(sf::Vector2f(0.4f, 0.4f));
	else if (Komputer == true)
		Czarny.setScale(sf::Vector2f(0.5f, 0.5f));
	Czarny.setOrigin(Center2.left + Center2.width / 2, Center2.top + Center2.height / 2);
	if (Komputer == false)
		Czarny.setPosition(sf::Vector2f(RozmiarMenuX / 2, RozmiarMenuY / 2 + 220));
	else if (Komputer == true)
		Czarny.setPosition(sf::Vector2f(RozmiarMenuX / 2, RozmiarMenuY / 2 + 40));

	//STRZA£KA W LEWO
	sf::Texture Left;
	if (!Left.loadFromFile("Images/Lewo.png"))
		Blad(2);
	sf::Sprite Lewa;
	Lewa.setTexture(Left);
	sf::FloatRect Center3 = Lewa.getLocalBounds();
	Lewa.setScale(sf::Vector2f(0.4f, 0.4f));
	Lewa.setOrigin(Center3.left + Center3.width / 2, Center3.top + Center3.height / 2);
	Lewa.setPosition(sf::Vector2f((Center1.left + Center1.width) / 2, Center1.top + Center1.width + 60));
	Center3 = Lewa.getGlobalBounds();

	//STRZA£KA W PRAWO
	sf::Texture Right;
	if (!Right.loadFromFile("Images/Prawo.png"))
		Blad(2);
	sf::Sprite Prawa;
	Prawa.setTexture(Right);
	sf::FloatRect Center4 = Bialy.getLocalBounds();
	Prawa.setScale(sf::Vector2f(0.4f, 0.4f));
	Prawa.setOrigin(Center4.left + Center4.width / 2, Center4.top + Center4.height / 2);
	Prawa.setPosition(sf::Vector2f((Center1.left + Center1.width) + 80, Center1.top + Center1.width + 10 + 60));
	Center4 = Prawa.getGlobalBounds();

	//OKNO MENU
	sf::RenderWindow window{ sf::VideoMode{ 700, 900 }, "Warcaby - menu", sf::Style::Close };
	window.setVerticalSyncEnabled(1);
	sf::Event event;
	window.requestFocus();

	//POCZ¥TEK PÊTLI
	while (window.isOpen())
	{
		window.clear();
		while (window.pollEvent(event))
		{
			//ZAMYKANIE OKNA
			if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)))
				window.close();

			//DWÓCH GRACZY
			if (Komputer == false)
			{
				//WPISYWANIE NAZWY GRACZA 1
				if (focus1 == false && (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
													 (sf::Mouse::getPosition(window).x > p1.left && sf::Mouse::getPosition(window).x < p1.left + p1.width &&
													  sf::Mouse::getPosition(window).y > p1.top && sf::Mouse::getPosition(window).y < p1.top + p1.height)))
				{
					focus1 = true;
					focus2 = false;
				}
				if (focus1 == true && (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)))
					focus1 = false;
				if (focus1 == true && event.type == sf::Event::TextEntered && event.text.unicode < 128)
				{
					if (event.text.unicode != 8 && str1.length() < 13)
						str1 += static_cast<char>(event.text.unicode);
					else if (event.text.unicode == 8 && str1.length() > 0)		//BACKSPACE
						str1 = str1.erase(str1.size() - 1, str1.size());
					Gracz1.setString(str1);
				}

				//WPISYWANIE NAZWY GRACZA 2
				if (focus2 == false && (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
													 (sf::Mouse::getPosition(window).x > p2.left && sf::Mouse::getPosition(window).x < p2.left + p2.width &&
													  sf::Mouse::getPosition(window).y > p2.top && sf::Mouse::getPosition(window).y < p2.top + p2.height)))
				{
					focus1 = false;
					focus2 = true;
				}
				if (focus2 == true && (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)))
					focus2 = false;
				if (focus2 == true && event.type == sf::Event::TextEntered && event.text.unicode < 128)
				{
					if (event.text.unicode != 8 && str2.length() < 13)
						str2 += static_cast<char>(event.text.unicode);
					else if (event.text.unicode == 8 && str2.length() > 0)		//BACKSPACE
						str2 = str2.erase(str2.size() - 1, str2.size());
					Gracz2.setString(str2);
				}
			}

			//GRA Z KOMPUTEREM
			else if (Komputer == true)
			{
				//NAZWA U¯YTKOWNIKA
				if (focus1 == false && (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
													 (sf::Mouse::getPosition(window).x > p1.left && sf::Mouse::getPosition(window).x < p1.left + p1.width &&
													  sf::Mouse::getPosition(window).y > p1.top && sf::Mouse::getPosition(window).y < p1.top + p1.height)))
				{
					focus1 = true;
				}
				if (focus1 == true && (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)))
					focus1 = false;
				if (focus1 == true && event.type == sf::Event::TextEntered && event.text.unicode < 128)
				{
					if (event.text.unicode != 8 && str1.length() < 13)
						str1 += static_cast<char>(event.text.unicode);
					else if (event.text.unicode == 8 && str1.length() > 0)		//BACKSPACE
						str1 = str1.erase(str1.size() - 1, str1.size());
					Gracz.setString(str1);
					if (licznik % 2 == 0)
						Gracz1 = Gracz;
					else if (licznik % 2 == 1)
						Gracz2 = Gracz;
				}

				//ZMIANA KOLORU
				if ((event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
								 ((sf::Mouse::getPosition(window).x > Center3.left && sf::Mouse::getPosition(window).x < Center3.left + Center3.width &&
								   sf::Mouse::getPosition(window).y > Center3.top && sf::Mouse::getPosition(window).y < Center3.top + Center3.height) ||
								  (sf::Mouse::getPosition(window).x > Center4.left && sf::Mouse::getPosition(window).x < Center4.left + Center4.width &&
								   sf::Mouse::getPosition(window).y > Center4.top && sf::Mouse::getPosition(window).y < Center4.top + Center4.height))))
				{
					licznik++;
					if (licznik % 2 == 0) //BIA£Y
					{
						Gracz1 = Gracz;
						Gracz2.setString("Komputer");
					}
					else if (licznik % 2 == 1) //CZARNY
					{
						Gracz1.setString("Komputer");
						Gracz2 = Gracz;
					}
				}
			}

			//PRZEJŒCIE DO GRY - PRZYCISK "DALEJ"
			if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
							 (sf::Mouse::getPosition(window).x > RozmiarMenuX - textCenter4.width - 50 && sf::Mouse::getPosition(window).x < RozmiarMenuX
						   && sf::Mouse::getPosition(window).y > RozmiarMenuY - 2*textCenter4.height && sf::Mouse::getPosition(window).y < RozmiarMenuY))
			{
				//SPRAWDZA CZY NAZWY GRACZY SA ROWNE I CZY GRACZ NIE MA NAZWY "Komputer".
				{
					std::string gracz = Gracz.getString();
					std::string gracz1 = Gracz1.getString();
					std::string gracz2 = Gracz2.getString();
					if (gracz1 == gracz2)
						Blad(3);
					else if (gracz1 == "" || gracz2 == "")
						Blad(4);
				}
				window.close();
				Gra(Gracz1, Gracz2, Komputer);
			}
		}

		//INICJALIZACJA T£A
		window.draw(Background);
		window.draw(Naglowek);
		window.draw(Dalej);
		
		//DWÓCH GRACZY
		if (Komputer == false)
		{
			window.draw(G1);
			window.draw(G2);
			window.draw(prostokat1);
			window.draw(Gracz1);
			window.draw(Bialy);
			window.draw(prostokat2);
			window.draw(Gracz2);
			window.draw(Czarny);
		}

		//GRA Z KOMPUTEREM
		else if (Komputer == true)
		{
			window.draw(G1);
			window.draw(prostokat1);
			window.draw(Gracz);
			if (licznik % 2 == 0)
				window.draw(Bialy);
			else if (licznik % 2 == 1)
				window.draw(Czarny);
			window.draw(Lewa);
			window.draw(Prawa);
		}

		window.display();
	}
}