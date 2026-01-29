#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>



void UserInput(std::optional<sf::Event>& event, sf::Sprite& sprite) {
    if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->scancode == sf::Keyboard::Scancode::D) {
            sprite.move(sf::Vector2f(5.0f, 0.0f));
        }
        if (keyPressed->scancode == sf::Keyboard::Scancode::A) {
            sprite.move(sf::Vector2f(-5.0f, 0.0f));
        }
        if (keyPressed->scancode == sf::Keyboard::Scancode::W) {
            sprite.move(sf::Vector2f(0.0f, -5.0f));
        }
        if (keyPressed->scancode == sf::Keyboard::Scancode::S) {
            sprite.move(sf::Vector2f(0.0f, 5.0f));
        }
    }
}


void UserGravity(sf::Sprite& sprite) {
    sf::Vector2f position = sprite.getPosition();
    if (position.y != 250) {
        sprite.move(sf::Vector2(0.0f , 0.5f));
    }
}


int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Super video game.com");
    sf::Texture texture;
    if (!texture.loadFromFile("images/mushroom2.jpg")) {
        std::cout << "image not working" << std::endl;
    }
    sf::Sprite sprite(texture);
    sprite.setScale(sf::Vector2f(0.1, 0.1));
    sprite.setPosition(sf::Vector2f(120, 120));
    
    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
            
            UserInput(event, sprite);
        }
        
        UserGravity(sprite);
        window.clear();
        window.draw(sprite);
        window.display();
    }
    
    return 0;
}
//make the gravity which moves the sprite to ground