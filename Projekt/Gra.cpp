#include "Gra.h"

void Gra(std::string &Gracz1, std::string &Gracz2, bool &gracz)
{
	sf::Texture texture;
	if (!texture.loadFromFile("Images/Background.jpg"))
		Blad(2);
	sf::Sprite sprite;
	sprite.setTexture(texture);

	sf::Font font;
	if (!font.loadFromFile("Fonts/PressStart2P-Regular.ttf"))
		Blad(2);

	std::string s1 = "WARCABY";
	sf::Text tytul(s1, font);
	tytul.setCharacterSize(50);
	tytul.setFillColor(sf::Color::Black);
	sf::FloatRect textCenter1 = tytul.getLocalBounds();
	tytul.setOrigin(textCenter1.left + textCenter1.width / 2.f, 0.f);
	tytul.setPosition(sf::Vector2f(RozmiarOknaX / 2.f, 5.f));

	std::string s2 = "TURA: ";
	sf::Text tura(s2, font);
	tura.setCharacterSize(30);
	tura.setFillColor(sf::Color::Black);
	sf::FloatRect textCenter2 = tura.getLocalBounds();
	tura.setOrigin(textCenter2.left + textCenter2.width / 2.f, 0.f);
	tura.setPosition(sf::Vector2f(RozmiarOknaX / 2.f, 65.f));

	sf::RenderWindow window{ sf::VideoMode{ 900, 950 }, "Warcaby", sf::Style::Close };
	window.setVerticalSyncEnabled(1);
	sf::Event event;
	Plansza plansza;

	while (window.isOpen())
	{
		window.clear();
		window.pollEvent(event);

		if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			window.close();

		plansza.InicjalizujPlansze();
		window.draw(sprite);
		plansza.WyswietlPlansze(window);
		window.draw(tytul);
		window.draw(tura);
		window.display();
	}
}