#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(640, 320), "SFML works!", sf::Style::None, settings);
	window.setPosition(
		sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - window.getSize().x / 2,
		sf::VideoMode::getDesktopMode().height / 2 - window.getSize().y / 2));
	sf::CircleShape shape(100.f);
	shape.setPosition(window.getSize().x / 2 - 100, window.getSize().y / 2 - 100);
	shape.setFillColor(sf::Color(239, 51, 64));
	sf::SoundBuffer sb;
	if(!sb.loadFromFile("marsh.ogg")) return -1;
	sf::Sound sound;
	sound.setBuffer(sb);
	sound.play();
	while (window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			// if(event.type == sf::Event::Resized) window.setView(
			// 	sf::View(
			// 		sf::Vector2f((float)event.size.width / 2.0, (float)event.size.height / 2.0),
			// 		sf::Vector2f((float)event.size.width, (float)event.size.height)
			// 	)
			// );
			if(event.type == sf::Event::Closed) window.close();
		}
		window.clear(sf::Color(255, 255, 255));
		window.draw(shape);
		window.display();
	}
	return 0;
}
