#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameWindow.h"
#include "EventManager.h"
#include "World.h"
#include "TestClass.h"

void updateFunc(float deltaTime, float& timer, float& delay, sf::Text& text, sf::RectangleShape& backGround, World& world);
void  FixedUpdate(float& timer, float& delay, float deltaTime, sf::Text& text, sf::RectangleShape& backGround, World& world);


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

    VertexArray gridWorld;
    World world;

    gridWorld = world.DrawWorldGrid(window.getRenderWindow(), 64, 64);

    float timer = 0.0f;
    float delay = 1.0f;

    sf::Text text(world.GetFormatedWorldTime(), font, 14);
    text.setPosition(sf::Vector2f(8, 12));
    text.setFillColor(sf::Color::Green);

    sf::RectangleShape worldTextBackGround(sf::Vector2f(window.getRenderWindow().getView().getSize().x, 32));
    worldTextBackGround.setPosition(sf::Vector2f(0, 0));
    worldTextBackGround.setFillColor(sf::Color::Black);

    // Start the game loop
    while (window.isOpen())
    {
        sf::Time dt = clock.restart(); 
        float deltaTime = dt.asSeconds();

        // Process events
        while (eventManager.pollEvent(window.getRenderWindow()))
        {
            if (eventManager.isWindowClosed())
            {
                window.close();
            }
        }


        window.clear();

        updateFunc(deltaTime, timer, delay, text, worldTextBackGround, world);
        
        window.draw(gridWorld);
        window.draw(worldTextBackGround);
        window.draw(text);

        window.display();
    }

    return EXIT_SUCCESS;
}

void updateFunc(float deltaTime, float& timer, float& delay, sf::Text& text, sf::RectangleShape& backGround, World& world)
{

    // FixedUpdates() -> Updates PerSecond changing delay changes the frequency of the update
    FixedUpdate(timer, delay, deltaTime, text, backGround, world); 
}

void FixedUpdate(float& timer, float& delay, float deltaTime, sf::Text& text, sf::RectangleShape& backGround, World& world)
{
    timer += deltaTime;
    if (timer >= delay)
    {

        timer = 0.0f;
 
        world.UpdateWorldTime();
        text.setString(world.GetFormatedWorldTime());
    }

}


