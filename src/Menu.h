#ifndef MENU_H_
#define MENU_H_


/**
* @author Ahmad Odeh
* @date 8th Jan , 2024 
* @note create a menu Manager
**/

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <cstdio>

class Menu : public sf::RectangleShape {

public:

    /**
    * @brief Menu class Constructor
    * @param color -> menu color
    */

    Menu(const sf::Color& color ) : m_menuColor(color) {
        this->setFillColor(this->m_menuColor);
        this->setPosition(this->m_pos);
        this->setSize(this->m_size);
        fprintf(stderr , "Created\n");

    }

    /**
    * @brief Menu class Destructor
    */

    ~Menu();

public:
    void draw_on_canvas(sf::RenderWindow& window);

private:
    void create_menu_content(sf::Shape* shape);

private:
    sf::Color m_menuColor;
    std::vector<sf::RectangleShape*> m_menuContent;


private:
    const sf::Vector2f m_size = {100.f,600.f};
    const sf::Vector2f m_pos = {0.f,0.f};
};



#endif