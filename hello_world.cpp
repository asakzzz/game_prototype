#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

void UserInput(sf::Sprite &sprite, sf::Vector2f &velocity) {

  velocity.x = 0;

  float moveSpeed = 300.0f;
  float jumpSpeed = 300.0f;
  

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) {
    velocity.x = moveSpeed;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) {
    velocity.x = -moveSpeed;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space)) {
    velocity.y = -jumpSpeed;
  }
}

void UserGravity(sf::Sprite &sprite, sf::Vector2f &velocity, float dt) {
  const float gravity = 500.0f;
  const float Ground = 240;

  velocity.y += gravity * dt;
  sprite.move(velocity * dt);

  if (sprite.getPosition().y >= Ground) {
    velocity.y = 0;
    sprite.setPosition(sf::Vector2f(sprite.getPosition().x, Ground));
  }
}

int main() {
  sf::RenderWindow window(sf::VideoMode({800, 600}), "Super videogame.com");
  sf::Texture texture;
  if (!texture.loadFromFile("images/mushroom2.jpg")) {
    std::cout << "image not working" << std::endl;
  }

  sf::Clock clock;

  sf::Sprite sprite(texture);
  sprite.setScale(sf::Vector2f(0.1, 0.1));
  sprite.setPosition(sf::Vector2f(110, 150));
  sf::Vector2f velocity(0, 0);

  while (window.isOpen()) {
    sf::Time dt = clock.restart();
    float deltaTime = dt.asSeconds();

    while (auto event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>())
        window.close();

      
    }
    UserInput(sprite, velocity);
    UserGravity(sprite, velocity, deltaTime);
    std::cout << velocity.x << std::endl;
    window.clear();
    window.draw(sprite);
    window.display();
  }

  return 0;
}
