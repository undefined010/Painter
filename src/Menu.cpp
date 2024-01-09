
/**
* @author Ahmad Odeh
* @date 8th Jan , 2024 
**/

#include "Menu.h"
#include "Pen.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>


Menu::~Menu() {

}


void Menu::create_menu_content(std::shared_ptr<sf::RectangleShape> shape) {
    if (shape == nullptr) return;

    this->m_menuContent.push_back(shape);

}

void Menu::draw_on_canvas(sf::RenderWindow& window) {

    
    this->init();

    for (auto& elem : this->m_menuContent) {
        //std::cerr << (*elem).getSize().x;
        window.draw(*elem);
    }

}

void Menu::pen_click(Pen& pen) {

    //bool mousex = sf::Mouse::getPosition(window).x > 0 && sf::Mouse::getPosition(window).x < elem->getSize().x;
    //bool mousey = sf::Mouse::getPosition(window).y > elem->getPosition().y && sf::Mouse::getPosition(window).y <= elem->getPosition().y + elem->getSize().y ;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
        pen.setFillColor(sf::Color::Red);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
        pen.setFillColor(sf::Color::Blue);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        pen.setFillColor(sf::Color::White);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
        pen.setFillColor(sf::Color::Cyan);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
        pen.setFillColor(sf::Color::Green);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
        pen.setFillColor(sf::Color::Yellow);
    }

}

void Menu::init() {

    const sf::Vector2f rec_size = {50 , 50};
    sf::Color clrs [3][2] = {{sf::Color::Red , sf::Color::Blue} , {sf::Color::White , sf::Color::Cyan} , {sf::Color::Green , sf::Color::Yellow} };

    int ii = 0 ; int jj = 0;
    //    std::shared_ptr<sf::RectangleShape> temp = std::make_unique<sf::RectangleShape>();
    // 
    for (int i = 0 ; i < 3 ; ++i) {
        //std::cerr << ii << ' ' << jj << '\n';
        for (int j = 0 ; j < 100 ; j+=50) {
            std::shared_ptr<sf::RectangleShape> temp = std::make_unique<sf::RectangleShape>();
            
            temp->setFillColor(clrs[ii][jj]);
            temp->setSize(rec_size);
            temp->setPosition(sf::Vector2f(j , i * rec_size.y));

            this->m_menuContent.push_back(temp);

            ++jj;
        }
        jj = 0;
        ++ii;
    }

}

