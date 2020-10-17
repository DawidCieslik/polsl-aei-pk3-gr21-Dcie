#include "menu.h"
#include <iostream>
void menu1()
{
	sf::Font font;
	if (!font.loadFromFile("Fonts/PressStart2P-Regular.ttf"))
		Blad(2);
	
	std::string s1 = "WYBIERZ TRYB";
	sf::Text Naglowek(s1, font);
	Naglowek.setCharacterSize(50);
	Naglowek.setFillColor(sf::Color::Black);
	sf::FloatRect textCenter1 = Naglowek.getLocalBounds();
	Naglowek.setOrigin(textCenter1.left + textCenter1.width / 2.f, 0.f);
	Naglowek.setPosition(sf::Vector2f(RozmiarMenuX / 2.f, 20.f));

	std::string s2 = "Komputer";
	sf::Text Komp(s2, font);
	Komp.setCharacterSize(50);
	Komp.setFillColor(sf::Color::Black);
	sf::FloatRect textCenter2 = Komp.getLocalBounds();
	Komp.setOrigin(textCenter2.left + textCenter2.width / 2.f, 0.f);
	Komp.setPosition(sf::Vector2f(RozmiarMenuX / 2.f, 140.f));

	std::string s3 = "Dwóch graczy";
	sf::Text Gracz(s3, font);
	Gracz.setCharacterSize(50);
	Gracz.setFillColor(sf::Color::Black);
	sf::FloatRect textCenter3 = Gracz.getLocalBounds();
	Gracz.setOrigin(textCenter3.left + textCenter3.width / 2.f, 0.f);
	Gracz.setPosition(sf::Vector2f(RozmiarMenuX / 2.f, 520.f));

	sf::Texture Back;
	if (!Back.loadFromFile("Images/Menu.jpg"))
		Blad(2);
	sf::Sprite Background;
	Background.setTexture(Back);

	sf::Texture Comp;
	if (!Comp.loadFromFile("Images/Computer.png"))
		Blad(2);
	sf::Sprite CompIcon;
	CompIcon.setTexture(Comp);
	sf::FloatRect Center2 = CompIcon.getLocalBounds();
	CompIcon.setOrigin(Center2.left + Center2.width / 2.f, Center2.top + Center2.height / 2.f);
	CompIcon.setPosition(sf::Vector2f(RozmiarMenuX/2, RozmiarMenuY/2-160));

	sf::Texture TwoPlayers;
	if (!TwoPlayers.loadFromFile("Images/TwoPlayers.png"))
		Blad(2);
	sf::Sprite TwoPlayersIcon;
	TwoPlayersIcon.setTexture(TwoPlayers);
	sf::FloatRect Center3 = TwoPlayersIcon.getLocalBounds();
	TwoPlayersIcon.setOrigin(Center3.left + Center3.width / 2.f, Center3.top + Center3.height / 2.f);
	TwoPlayersIcon.setPosition(sf::Vector2f(RozmiarMenuX/2, RozmiarMenuY/2+260));

	sf::RenderWindow window{ sf::VideoMode{ 700, 900 }, "Warcaby - menu", sf::Style::Close };
	window.setVerticalSyncEnabled(1);
	sf::Event event;

	while (window.isOpen())
	{
		window.clear();
		while (window.pollEvent(event))
		{
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
	bool focus1 = false;
	bool focus2 = false;

	sf::RectangleShape prostokat1;
	prostokat1.setSize(sf::Vector2f(500.f, 50.f));
	prostokat1.setOrigin(sf::Vector2f(250.f, 25.f));
	prostokat1.setFillColor(sf::Color::White);
	prostokat1.setOutlineColor(szary);
	prostokat1.setOutlineThickness(2);
	prostokat1.setPosition(RozmiarMenuX / 2.f, 270.f);
	sf::FloatRect p1 = prostokat1.getGlobalBounds();

	sf::RectangleShape prostokat2;
	prostokat2.setSize(sf::Vector2f(500.f, 50.f));
	prostokat2.setOrigin(sf::Vector2f(250.f, 25.f));
	prostokat2.setFillColor(sf::Color::White);
	prostokat2.setOutlineColor(szary);
	prostokat2.setOutlineThickness(2);
	prostokat2.setPosition(RozmiarMenuX / 2.f, 650.f);
	sf::FloatRect p2 = prostokat2.getGlobalBounds();

	sf::Font font;
	if (!font.loadFromFile("Fonts/PressStart2P-Regular.ttf"))
		Blad(2);

	std::string str1;
	std::string str2;

	sf::Text Gracz1;
	Gracz1.setFont(font);
	Gracz1.setCharacterSize(30);
	Gracz1.setFillColor(sf::Color::Black);
	Gracz1.setString("Bialy");
	Gracz1.setPosition(sf::Vector2f(p1.left + 15.f, 255.f));

	sf::Text Gracz2;
	Gracz2.setFont(font);
	Gracz2.setCharacterSize(30);
	Gracz2.setFillColor(sf::Color::Black);
	Gracz2.setString("Czarny");
	Gracz2.setPosition(sf::Vector2f(p2.left + 15.f, 635.f));

	std::string s1 = "WYBIERZ NAZWE";
	sf::Text Naglowek(s1, font);
	Naglowek.setCharacterSize(50);
	Naglowek.setFillColor(sf::Color::Black);
	sf::FloatRect textCenter1 = Naglowek.getLocalBounds();
	Naglowek.setOrigin(textCenter1.left + textCenter1.width / 2.f, 0.f);
	Naglowek.setPosition(sf::Vector2f(RozmiarMenuX / 2.f, 20.f));

	std::string s2 = "GRACZ 1";
	sf::Text G1(s2, font);
	G1.setCharacterSize(50);
	G1.setFillColor(sf::Color::Black);
	sf::FloatRect textCenter2 = G1.getLocalBounds();
	G1.setOrigin(textCenter2.left + textCenter2.width / 2.f, 0.f);
	G1.setPosition(sf::Vector2f(RozmiarMenuX / 2.f, 140.f));

	std::string s3 = "GRACZ 2";
	sf::Text G2(s3, font);
	G2.setCharacterSize(50);
	G2.setFillColor(sf::Color::Black);
	sf::FloatRect textCenter3 = G2.getLocalBounds();
	G2.setOrigin(textCenter3.left + textCenter3.width / 2.f, 0.f);
	G2.setPosition(sf::Vector2f(RozmiarMenuX / 2.f, 520.f));

	sf::Texture Back;
	if (!Back.loadFromFile("Images/Menu.jpg"))
		Blad(2);
	sf::Sprite Background;
	Background.setTexture(Back);

	sf::Texture White;
	if (!White.loadFromFile("Images/Bialy.png"))
		Blad(2);
	sf::Sprite Bialy;
	Bialy.setTexture(White);
	sf::FloatRect Center1 = Bialy.getLocalBounds();
	Bialy.setScale(sf::Vector2f(0.4f, 0.4f));
	Bialy.setOrigin(Center1.left + Center1.width / 2.f, Center1.top + Center1.height / 2.f);
	Bialy.setPosition(sf::Vector2f(RozmiarMenuX / 2.f, RozmiarMenuY / 2.f - 60.f));

	sf::Texture Black;
	if (!Black.loadFromFile("Images/Czarny.png"))
		Blad(2);
	sf::Sprite Czarny;
	Czarny.setTexture(Black);
	sf::FloatRect Center2 = Czarny.getLocalBounds();
	Czarny.setScale(sf::Vector2f(0.4f, 0.4f));
	Czarny.setOrigin(Center2.left + Center2.width / 2.f, Center2.top + Center2.height / 2.f);
	Czarny.setPosition(sf::Vector2f(RozmiarMenuX / 2.f, RozmiarMenuY / 2.f + 340.f));

	sf::RenderWindow window{ sf::VideoMode{ 700, 900 }, "Warcaby - menu", sf::Style::Close };
	window.setVerticalSyncEnabled(1);
	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)))
				window.close();
			if (focus1 == false && (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
								   (sf::Mouse::getPosition(window).x > p1.left && sf::Mouse::getPosition(window).x < p1.left + p1.width &&
									sf::Mouse::getPosition(window).y > p1.top && sf::Mouse::getPosition(window).y < p1.top + p1.height)))
			{
				std::cout << "1";
				focus1 = true;
			}
			if (focus1 == true && (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) ||
								  (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
								  (sf::Mouse::getPosition(window).x < p1.left && sf::Mouse::getPosition(window).x > p1.left + p1.width &&
					               sf::Mouse::getPosition(window).y < p1.top && sf::Mouse::getPosition(window).y > p1.top + p1.height))))
			{
				std::cout<<"2";
				focus1 = false;
			}
			if (focus1 == true)
			{
				if (event.type == sf::Event::TextEntered && event.text.unicode < 128)
				{
					if (event.text.unicode != 8)
						str1 += static_cast<char>(event.text.unicode);
					else if (event.text.unicode == 8 && str1.length() > 0)
						str1 = str1.erase(str1.size() - 1, str1.size());
					Gracz1.setString(str1);
				}
			}
			if (focus2 == false && (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
								   (sf::Mouse::getPosition(window).x > p2.left && sf::Mouse::getPosition(window).x < p2.left + p2.width &&
									sf::Mouse::getPosition(window).y > p2.top && sf::Mouse::getPosition(window).y < p2.top + p2.height)))
			{
				std::cout << "3";
				focus2 = true;
			}
			if (focus2 == true && (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) ||
								  (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
								  (sf::Mouse::getPosition(window).x < p2.left && sf::Mouse::getPosition(window).x > p2.left + p2.width &&
								   sf::Mouse::getPosition(window).y < p2.top && sf::Mouse::getPosition(window).y > p2.top + p2.height))))
			{
				std::cout << "4";
				focus2 = false;
			}
			if (focus2 == true)
			{
				if (event.type == sf::Event::TextEntered && event.text.unicode < 128)
				{
					if (event.text.unicode != 8)
						str2 += static_cast<char>(event.text.unicode);
					else if (event.text.unicode == 8 && str2.length() > 0)
						str2 = str2.erase(str2.size() - 1, str2.size());
					Gracz2.setString(str2);
				}
			}
		}

		window.clear();
		window.draw(Background);
		window.draw(Naglowek);
		window.draw(G1);
		window.draw(G2);
		window.draw(prostokat1);
		window.draw(Gracz1);
		window.draw(Bialy);
		window.draw(prostokat2);
		window.draw(Gracz2);
		window.draw(Czarny);

		window.display();
	}
}