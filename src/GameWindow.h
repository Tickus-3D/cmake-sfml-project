#include <SFML/Graphics.hpp>

class GameWindow
{
private:
	sf::RenderWindow window;

public:
	GameWindow(int width, int height, const std::string& title) : window(sf::VideoMode(width, height), title) {}

	bool isOpen() { return window.isOpen(); };

	void clear() { window.clear(); }

	void close() { window.close(); }

	void display() { window.display(); }

	void draw(sf::Drawable& drawable) { window.draw(drawable); }

	sf::RenderWindow& getRenderWindow() { return window; }

};