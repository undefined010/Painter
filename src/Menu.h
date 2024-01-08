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

class Menu : public sf::RectangleShape {

public:

    /**
    * @brief Menu class Constructor
    * @param color -> menu color
    */
    Menu(const sf::Color& color ) : m_menuColor(color) {}
    ~Menu();
    
public:
    void draw_on_canvas(sf::RenderWindow& window);
    void update_menu();

private:
    sf::Color m_menuColor;
    std::vector<sf::RectangleShape*> m_menuContent;


private:
    const sf::Vector2f m_size = {100.f,600.f};
    const sf::Vector2f m_pos = {0.f,600.f};
};



#endif