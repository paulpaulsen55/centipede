#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project" };
    window.setFramerateLimit(144);
    sf::Text text;
    sf::Font font;
    font.loadFromFile("assets/arial.ttf");
    text.setFont(font);
    text.setString("Hello, World!");
    text.setCharacterSize(100);



    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.draw(text);
        window.display();
    }
}