#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Plansza.h"

using namespace std;

int main()
{
	sf::RenderWindow window{ sf::VideoMode{900,950}, "Warcaby" };
	window.setFramerateLimit(60);
	sf::Event event;
	while (true)
	{
		window.clear(sf::Color::White);
		window.pollEvent(event);

		if (event.type == sf::Event::Closed)
		{
			window.close();
			break;
		}

		window.display();
	}
	return 0;
}