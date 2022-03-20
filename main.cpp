#include <SFML/Graphics.hpp>
#include <iostream>

#include "b_spline.h"

//Glboal variables, functions, classes

int GetClickedPoint(std::array<sf::CircleShape, CONTROL_SIZE> rects, int len, int mouseX, int mouseY) {
    for (int i = 0; i < len; i++) {
        if (rects[i].getGlobalBounds().contains(mouseX, mouseY)) {
            return i;
        }
    }

    return -1;
}



//C++ program entry point
int main()
{
    //Creating the window
    sf::RenderWindow window(sf::VideoMode(1280, 800), "SFML Game");

    //Settign the framerate limit to 60 FPS
    window.setFramerateLimit(60);

    window.setKeyRepeatEnabled(false);

    //Event object holding all events
    sf::Event event;

    //States for button/events
    bool mouseClicked = false;
    bool mouseInsideRect = false;
    bool dragging = false;

    sf::Vector2f mouseRectOffset;

    //Variables
    int mouseX = 0;
    int mouseY = 0;
    int pointIndex = -1;

    b_spline spline;

    //Game loop
    while (event.type != sf::Event::Closed)
    {
        //EVENTS
        while (window.pollEvent(event))
        {
            //LMB Pressed
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                mouseClicked = true;

                if ((pointIndex = GetClickedPoint(spline.control_points, 7, event.mouseButton.x, event.mouseButton.y)) >= 0)
                {
                    //TODO make smaller :|
                    dragging = true;
                    mouseRectOffset.x = event.mouseButton.x - spline.control_points[pointIndex].getGlobalBounds().left - spline.control_points[pointIndex].getOrigin().x;
                    mouseRectOffset.y = event.mouseButton.y - spline.control_points[pointIndex].getGlobalBounds().top - spline.control_points[pointIndex].getOrigin().y;
                }
            }

            //LMB released
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                mouseClicked = false;
                dragging = false;
                pointIndex = -1;
            }

            //Mouse Moved in window
            if (event.type == sf::Event::MouseMoved)
            {
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;
            }
        }

        //LOGIC

        if (dragging == true)
        {
            //TODO make smaller :|
            spline.control_points[pointIndex].setPosition(mouseX - mouseRectOffset.x, mouseY - mouseRectOffset.y);
            spline.update();
        }

        //RENDERING
        window.clear();

        for (int i = 0; i < MAX_DEG; i++)
            window << spline;

        window.display();
    }
    ///////////

    //Clean up and close the window
    window.close();

    //Close the program
    return 0;
}