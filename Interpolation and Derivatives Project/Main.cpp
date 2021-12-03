#include <SFML/Graphics.hpp>

int main()
{

	// Window Setup
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Interpolation Example", sf::Style::Titlebar);

	// Load texture
	sf::Texture ballTexture;
	ballTexture.loadFromFile("Assets/Graphics/ball_bowling.png");

	// Setup Sprite
	sf::Sprite ballSprite;
	ballSprite.setTexture(ballTexture);
	sf::Vector2f ballPosition = sf::Vector2f(0.0f, 0.0f);
	ballSprite.setPosition(ballPosition);
	ballSprite.setOrigin(ballTexture.getSize().x / 2, ballTexture.getSize().y / 2);

	// ---------------------------------------------------
	// Game Loop
	// ---------------------------------------------------
	while (window.isOpen())
	{
		// ---------------------------------------------------
		// Input
		// ---------------------------------------------------
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			// Is the event a key press event
			if (event.type == sf::Event::KeyPressed)
			{
				// Is the event specifically related to the escape key
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
			}
		}


		// ---------------------------------------------------
		// Update
		// ---------------------------------------------------


		// ---------------------------------------------------
		// Draw
		// ---------------------------------------------------
		sf::Color clearColor(200,200,200);
		window.clear(clearColor);

		window.draw(ballSprite);

		window.display();
	}


	return 0;
}