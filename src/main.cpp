#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>


/**
* @author Ahmad Odeh
* @date 6th Jan , 2024
**/

#include "Pen.h"
#include "Menu.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(800 , 600) , "Paint" , sf::Style::Titlebar | sf::Style::Close);
    sf::Event event;    

    Pen pen(10 , sf::Vector2f(100 , 100));
    Menu menu(sf::Color::White);

    window.setFramerateLimit(400.f);

    while (window.isOpen()) {

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return 0;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
                return 0;
            }

        }


        window.clear(sf::Color::Black);

        
        pen.paint_on_canvase(window);
        pen.rainbow_color();
        pen.update_pos(window);

        window.draw(pen);
        window.draw(menu);

        window.display();


    }


}
