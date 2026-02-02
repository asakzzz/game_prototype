#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

void UserInput(std::optional<sf::Event> &event, sf::Sprite &sprite, sf::Vector2f &velocity) {

  float moveSpeed = 5.0f;
  float jumpSpeed = 30.0f;
    std::cout << sprite.getPosition().x << "" << sprite.getPosition().y
  << std::endl;

  if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>()) {
    if (keyPressed->scancode == sf::Keyboard::Scancode::D) {
      velocity.x = moveSpeed;
    }
    if (keyPressed->scancode == sf::Keyboard::Scancode::A) {
      velocity.x = -moveSpeed;
    }
    if (keyPressed->scancode == sf::Keyboard::Scancode::W) {
      velocity.y = -jumpSpeed;
    }
  }

  if (const auto *keyReleased = event->getIf<sf::Event::KeyReleased>()) {
    if (keyReleased->scancode == sf::Keyboard::Scancode::D ||
        keyReleased->scancode == sf::Keyboard::Scancode::A) {
      velocity.x = 0;
    }
  }
}

void UserGravity(sf::Sprite &sprite, sf::Vector2f &velocity) {
  const float gravity = 5;
  const float Ground = 250;

  if (sprite.getPosition().y < Ground) {
    velocity.y += gravity;
  } else {
    velocity.y = 0;
  }
  sprite.move(velocity);
}

int main() {
  sf::RenderWindow window(sf::VideoMode({800, 600}), "Super videogame.com");
  sf::Texture texture;
  if (!texture.loadFromFile("images/mushroom2.jpg")) {
    std::cout << "image not working" << std::endl;
  }
  sf::Sprite sprite(texture);
  sprite.setScale(sf::Vector2f(0.1, 0.1));
  sprite.setPosition(sf::Vector2f(120, 120));
  sf::Vector2f velocity(0, 0);

  while (window.isOpen()) {
    while (auto event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>())
        window.close();

      UserInput(event, sprite, velocity);
    }

    UserGravity(sprite, velocity);
    sprite.move(velocity);
    window.clear();
    window.draw(sprite);
    window.display();
  }

  return 0;
}

// find a way to update user gravity automatically, bc now it is tagged
// undeclared
