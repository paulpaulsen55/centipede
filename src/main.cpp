#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    auto window = RenderWindow{ { 1920u, 1080u }, "CMake SFML Project" };
    window.setFramerateLimit(144);

    // font test
    Text text;
    Font font;
    font.loadFromFile("assets/arial.ttf");
    text.setFont(font);
    text.setString("Hello, World!");
    text.setCharacterSize(100);

    // triangle
    VertexArray triangle(Triangles, 3);
    triangle[0].position = Vector2f(110.f, 310);
    triangle[1].position = Vector2f(600.f, 310);
    triangle[2].position = Vector2f(200.f, 600);
    triangle[0].color = Color::Red;
    triangle[1].color = Color::Green;
    triangle[2].color = Color::Blue;

    while (window.isOpen())
    {
        for (auto event = Event{}; window.pollEvent(event);)
        {
            if (event.type == Event::Closed)
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