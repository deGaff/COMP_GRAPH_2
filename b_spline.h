//
// Created by d3Gaff on 20.03.2022.
//

#ifndef COMP_GRAPHICS_2_B_SPLINE_H
#define COMP_GRAPHICS_2_B_SPLINE_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <array>
#include <ctime>

#define CONTROL_SIZE 7
#define MAX_DEG 6
#define T_SIZE 1000
#define KNOT_SIZE CONTROL_SIZE+MAX_DEG
#define EPS 0.00001f

class b_spline {
public:
    using POINT = sf::Vertex;

    b_spline();
    void gen_control_points(unsigned seed = time(nullptr));
    friend void operator<<(sf::RenderWindow& window, const b_spline& spline);

    std::array<sf::CircleShape, CONTROL_SIZE> control_points;
    void update();
private:
    std::array<std::array<float, KNOT_SIZE>, MAX_DEG> knots;
    std::array<std::array<std::array<float, T_SIZE>, CONTROL_SIZE>, MAX_DEG> coefs;
    std::array<std::array<POINT, T_SIZE>, MAX_DEG> points;

    const std::array<sf::Color,MAX_DEG> colors = {
            sf::Color::Cyan,
            sf::Color::Red,
            sf::Color::Blue,
            sf::Color::White,
            sf::Color::Green,
            sf::Color::Magenta,
    };

    void gen_points();
    void gen_knots();
    void gen_coefs();
    float gen_coef(unsigned deg, unsigned control, float t);
};


#endif //COMP_GRAPHICS_2_B_SPLINE_H
