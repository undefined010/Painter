
/**
* @author Ahmad Odeh
* @date 7th Jan , 2024 
**/


#include <SFML/Window/Keyboard.hpp>
#define DEBUG_PEN false

#include "Pen.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Mouse.hpp>

#if DEBUG_PEN
#include <iostream>
#endif

#include <vector>
#include <algorithm>


Pen::~Pen()
{
    if (this->circles.size() == 0)
        return;

    for (auto& i : this->circles)
    {
        #if DEBUG_PEN
            std::cerr << "deleted : " << this->circles.size() << '\n';
        #endif
        
        delete i;

    }

    this->circles.clear();
}

void Pen::eliminated(std::vector<sf::CircleShape*>& circles , unsigned index) {
    if (circles.size() == 0) return;

    delete circles.at(index);

    circles.erase(circles.begin() + index);
    
}

void Pen::cheak_circles(std::vector<sf::CircleShape*>& vec) {

    // time : O(n)

    if (vec.size() == 0) return;
    
    auto last = std::unique(vec.begin() , vec.end() ,[](sf::CircleShape* a , sf::CircleShape* b) -> bool {
        return (*a).getPosition().x == (*b).getPosition().x && (*a).getPosition().y == (*b).getPosition().y;
    } );

    vec.erase(last , vec.end());

}

void Pen::update_pos(const sf::RenderWindow& window) {
    if (window.isOpen() == false) return;
    
    this->pos.x = sf::Mouse::getPosition(window).x - this->radius;
    this->pos.y = sf::Mouse::getPosition(window).y - this->radius;

    this->setPosition(this->pos);
}

void Pen::rainbow_color() {
    
    this->setFillColor(sf::Color(rand() % 255 , rand() % 255, rand() % 255 , 255));

}

void Pen::clear_all() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
        for (auto& i : this->circles) {
            
            #if DEBUG_PEN
                std::cerr << "deleted : " << this->circles.size() << '\n';
            #endif
        
            delete i;

        }

        this->circles.clear();
    }

    else return;
}

void Pen::paint_on_canvase(sf::RenderWindow& window) {
    
    bool mouseInsideWindowX = sf::Mouse::getPosition(window).x < window.getSize().x - this->getRadius() && sf::Mouse::getPosition(window).x >= 100;  
    bool mouseInsideWindowY = sf::Mouse::getPosition(window).y < window.getSize().y - this->getRadius() && sf::Mouse::getPosition(window).y >= 0;  


    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseInsideWindowX && mouseInsideWindowY ) {
        #if DEBUG_PEN
            std::cerr << "pressed\n";
        #endif

        sf::CircleShape* temp = new sf::CircleShape();

        temp->setRadius(this->getRadius());
        temp->setFillColor(this->getFillColor());
        temp->setPosition(this->getPosition());

        this->circles.push_back(temp);
        
    }

    this->cheak_circles(this->circles);


    for ( auto& c : this->circles )
        window.draw(*c);

    this->clear_all();


}