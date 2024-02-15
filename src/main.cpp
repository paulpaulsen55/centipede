#include <SFML/Graphics.hpp>

#include "Player.h"

using namespace sf;

int main() {
    unsigned int windowWidth = 800;
    unsigned int windowHeight = 600;
    auto window = RenderWindow{ { windowWidth, windowHeight }, "Centipede" };
    window.setFramerateLimit(144);

    // font test
    Text text;
    Font font;
    font.loadFromFile("assets/arial.ttf");
    text.setFont(font);
    text.setString("Wer das liest ist doof!");
    text.setCharacterSize(64);

    Player player(100.f, 100.f);

    while (window.isOpen()) {
        for (auto event = Event{}; window.pollEvent(event);) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
            player.moveLeft();
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
            player.moveRight();
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
            player.moveUp();
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
            player.moveDown();
        }

        // updating
        player.update(windowWidth, windowHeight);

        window.clear();
        // drawing
        window.draw(text);
        window.draw(player.getShape());

        window.display();
    }
}