

class EventManager 
{
private:
    sf::Event event;
public:
    bool pollEvent(sf::RenderWindow& window) { return window.pollEvent(event); }

    bool isWindowClosed() { return event.type == sf::Event::Closed; }

    // Add more methods as needed...

    //EventManager() = default;
};
