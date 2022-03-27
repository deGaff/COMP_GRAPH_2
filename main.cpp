#include <SFML/Graphics.hpp>
#include <iostream>

#include "b_spline.h"



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

    b_spline spline = b_spline_builder().setControlSize(15).setMaxDegree(12)
            .setOffset(10000).Build();

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

                if ((pointIndex = spline.GetClickedPoint(event.mouseButton.x, event.mouseButton.y)) >= 0)
                {
                    //TODO make smaller :|
                    auto& circ = spline.GetControlPoint(pointIndex);
                    dragging = true;
                    mouseRectOffset.x = event.mouseButton.x - circ.getGlobalBounds().left - circ.getOrigin().x;
                    mouseRectOffset.y = event.mouseButton.y - circ.getGlobalBounds().top - circ.getOrigin().y;
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

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                ++spline;
            }
        }

        //LOGIC

        if (dragging)
        {
            auto& circ = spline.GetControlPoint(pointIndex);
            float x = mouseX - mouseRectOffset.x;
            float y = mouseY - mouseRectOffset.y;
            if(x > 0 && x < 1280 && y > 0 && y < 800) {
                circ.setPosition(x, y);
                spline.update();
            }
        }

        //RENDERING
        window.clear();

        window << spline;

        window.display();
    }
    ///////////

    //Clean up and close the window
    window.close();

    //Close the program
    return 0;
}