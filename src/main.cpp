#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameWindow.h"
#include "EventManager.h"
#include "TestClass.h"

void HandleText(float& timer, float& delay, int &number, float deltaTime, sf::Text &text);

int main()
{
    // Create the main window
    GameWindow window(800, 600, "SystemX");

    EventManager eventManager{};

    sf::Clock clock;

    sf::Font font;
    if (!font.loadFromFile("C:/Users/Kyle/Documents/GitHub/cmake-sfml-project/Content/Sixtyfour/Sixtyfour-Regular-VariableFont_BLED,SCAN.ttf"))
    {
        std::cout << "failed to load font !!!!!!\n";
        return EXIT_FAILURE;
    }

    float timer = 0.0f;
    float delay = 1.0f;

    int number = 0;
    std::string numberStr = std::to_string(number);

    sf::Text text("Hello SFML " + numberStr, font, 24);
    text.setPosition(sf::Vector2f(100, 50));
    text.setFillColor(sf::Color::Green);

    // Start the game loop
    while (window.isOpen())
    {
        sf::Time dt = clock.restart(); 
        float deltaTime = dt.asSeconds();

        // Process events
        sf::Event event;
        while (eventManager.pollEvent(window.getRenderWindow()))
        {
            if (eventManager.isWindowClosed())
            {
                window.close();
            }
        }


        window.clear();
        
        HandleText(timer, delay, number, deltaTime, text);

        window.draw(text);


        window.display();
    }

    return EXIT_SUCCESS;
}

void HandleText(float& timer, float& delay, int& number, float deltaTime, sf::Text& text)
{
    timer += deltaTime;
    if (timer >= delay)
    {
        timer = 0.0f;

        number++;
        if (number >= 50)
        {
            number = 0;
        }
        std::string numberStr = std::to_string(static_cast<int>(number));
        text.setString("Hello SFML " + numberStr);
    }

}
