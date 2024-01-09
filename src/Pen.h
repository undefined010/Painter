#ifndef PEN_H
#define PEN_H

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <sys/types.h>
#include <vector>

/**
 * @brief The Pen class represents a pen for a drawing application.
**/

class Pen : public sf::CircleShape
{

public:

    /**
     * @brief Constructor for initializing the pen.
     * @param rad The radius of the pen.
     * @param clr The color of the pen.
     * @param pos1 The initial position of the pen.
    **/


    Pen(unsigned rad , const sf::Color& clr , const sf::Vector2f& pos1)
    : radius(rad) , color(clr) , pos(pos1)
    {
        this->setRadius(this->radius);
        this->setFillColor(this->color);
        this->setPosition(this->pos);
    }

    Pen(unsigned rad , const sf::Vector2f& pos1)
    : radius(rad) , pos(pos1)
    {
        this->setRadius(this->radius);
        this->setPosition(this->pos);
    }

    /**
    *@brief Destructor for cleaning pen
    **/

    ~Pen();


public:

    /**
    * @brief Updating the position of the circles inside the vector
    * @param window The main window (A.K.A) the canvas
    */

    void update_pos(const sf::RenderWindow& window);

    /**
    * @brief Paint the circles on the screen
    * @param window The main window (A.K.A) the canvas
    */

    void paint_on_canvase(sf::RenderWindow& window);

    bool isClicked();

private:
    /**
    * @brief Delete all circles inside the @param circles
    **/

    void cheak_if_want_to_clear();

    /**
    * @brief Checking if there are duplicates in the vector
    * @param circles The vector of circles
    */

    void cheak_circles(std::vector<std::shared_ptr<sf::CircleShape>>& circles);

private:
    unsigned radius;
    std::vector<std::shared_ptr<sf::CircleShape>> circles;
    sf::Color color;
    sf::Vector2f pos;

};


#endif