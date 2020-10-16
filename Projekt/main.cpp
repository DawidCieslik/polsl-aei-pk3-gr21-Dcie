#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Plansza.h"
#include "Pole.h"
#include "Enums.h"

using namespace std;

int main()
{
	sf::RenderWindow window{ sf::VideoMode{ RozmiarOknaX, RozmiarOknaY }, "Warcaby" };
	window.setFramerateLimit(60);
	sf::Event event;
	while (window.isOpen())
	{
		window.clear(sf::Color::Black);
		window.pollEvent(event);

		sf::Font font;
		font.loadFromFile("PressStart2P-Regular.ttf");

		string s1 = "WARCABY";
		sf::Text tytul(s1,font);
		tytul.setCharacterSize(50);
		tytul.setFillColor(sf::Color::White);
		sf::FloatRect textCenter1 = tytul.getLocalBounds();
		tytul.setOrigin(textCenter1.left + textCenter1.width/2, 0);
		tytul.setPosition(sf::Vector2f(RozmiarOknaX/2, 5));

		string s2 = "TURA:GRACZ1";
		sf::Text tura(s2, font);
		tura.setCharacterSize(30);
		tura.setFillColor(sf::Color::White);
		sf::FloatRect textCenter2 = tura.getLocalBounds();
		tura.setOrigin(textCenter2.left + textCenter2.width/2, 0);
		tura.setPosition(sf::Vector2f(RozmiarOknaX/2, 65));

		if (event.type == sf::Event::Closed || event.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			window.close();

		Plansza plansza;
		plansza.InicjalizujPlansze();
		plansza.WyswietlPlansze(window);
		window.draw(tytul);
		window.draw(tura);
		window.display();
	}
	return 0;
}