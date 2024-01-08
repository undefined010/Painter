
/**
* @author Ahmad Odeh
* @date 8th Jan , 2024 
**/

#include "Menu.h"
#include <SFML/Graphics/RectangleShape.hpp>

Menu::~Menu() {

    if (this->m_menuContent.size() == 0) return;

    for (sf::RectangleShape*& i : this->m_menuContent)
        delete i;

    this->m_menuContent.clear();

}

