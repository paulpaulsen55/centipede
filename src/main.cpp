#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project" };
    window.setFramerateLimit(144);

    // font test
    sf::Text text;
    sf::Font font;
    font.loadFromFile("assets/arial.ttf");
    text.setFont(font);
    text.setString("Hello, World!");
    text.setCharacterSize(100);

    // triangle
    sf::VertexArray triangle(sf::Triangles, 3);
    triangle[0].position = sf::Vector2f(110.f, 310);
    triangle[1].position = sf::Vector2f(600.f, 310);
    triangle[2].position = sf::Vector2f(200.f, 600);
    triangle[0].color = sf::Color::Red;
    triangle[1].color = sf::Color::Green;
    triangle[2].color = sf::Color::Blue;

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
        window.draw(triangle);
        window.display();
    }
}