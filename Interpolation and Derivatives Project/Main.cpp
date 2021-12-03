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

	// Interpolation data
	sf::Vector2f begin = ballPosition;
	sf::Vector2f end = ballPosition;
	sf::Vector2f change = end - begin;
	float duration = 1.0f;
	float time = 0.0f;

	// Game clock
	sf::Clock gameClock;

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

		// Mouse press
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			// left click...
			begin = ballPosition;
			end = sf::Vector2f(sf::Mouse::getPosition(window));
			change = end - begin;

			time = 0;
		}


		// ---------------------------------------------------
		// Update
		// ---------------------------------------------------

		// Get time passed this frame
		sf::Time frameTime = gameClock.restart();
		float deltaTime = frameTime.asSeconds();

		// Interpolate over time
		if (time < duration)
		{
			// Linear Interpolation
			//sf::Vector2f k1 = change / duration;
			//sf::Vector2f k2 = begin;
			//ballPosition = k1 * time + k2;

			// Quad Ease In
			sf::Vector2f k1 = change / (duration * duration);
			sf::Vector2f k2 = sf::Vector2f(0.0f, 0.0f);
			sf::Vector2f k3 = begin;
			ballPosition = k1 * time * time + k2 * time + k3;

			time += deltaTime;
		}
		else
		{
			// We finished the duration, move us instantly.
			// Instant movement
			ballPosition = end;

		}

		// Update sprite to correct position
		ballSprite.setPosition(ballPosition);

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