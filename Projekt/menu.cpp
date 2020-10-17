#include "menu.h"

void menu()
{
	std::string Gracz1 = "Bia³y";
	std::string Gracz2 = "Czarny";
	bool Komputer=0;

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

	sf::RenderWindow window{ sf::VideoMode{ 700, 900 }, "Warcaby - menu" };
	window.setVerticalSyncEnabled(1);
	sf::Event event;

	while (window.isOpen())
	{
		window.clear(sf::Color::White);
		window.pollEvent(event);

		if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			window.close();

		window.draw(Background);
		window.draw(Naglowek);
		window.draw(Komp);
		window.draw(CompIcon);
		window.draw(Gracz);
		window.draw(TwoPlayersIcon);

		window.display();
	}
}