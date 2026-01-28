#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML Window");
    
    sf::Texture texture;
    if(!texture.loadFromFile("mario.jpg")) {
        std :: cout<<"image not working" << std :: endl;
    }    
    sf::Sprite sprite(texture);



    sf::Vector2u size = window.getSize();
    float width = size.x;
    float height = size.y;



    sf::Vector2f scale(10, 10);
    sprite.setScale(scale);

    while(window.isOpen()) {
        while(auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        } 
        
        window.clear();
        window.draw(sprite);
        window.display();
    }
    
    return 0;
}
   
