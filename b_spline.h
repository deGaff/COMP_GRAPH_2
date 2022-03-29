//
// Created by d3Gaff on 20.03.2022.
//

#ifndef COMP_GRAPHICS_2_B_SPLINE_H
#define COMP_GRAPHICS_2_B_SPLINE_H
#include <SFML/Graphics.hpp>
#include "profile.h"
#include <vector>
#include <array>
#include <ctime>



class b_spline {
public:
    struct NumberText {
        sf::Text text;
        sf::Font font;
        NumberText(int deg) {
            font.loadFromFile("Font.ttf");
            text.setString("Degree: " + std::to_string(deg));
            text.setFillColor(sf::Color::Red);
            text.setCharacterSize(16);
            text.setFont(font);
        }
        NumberText& operator = (int deg) {
            text.setString("Degree: " + std::to_string(deg));
            return *this;
        }
    };

    using POINT = sf::Vertex;

    b_spline(unsigned control_size, unsigned max_degree,
             unsigned offset) : cur_degree(1), control_size(control_size),
                                max_degree(max_degree), offset(offset),
                                points(control_size * offset),
                                control_points(control_size), all_knots(max_degree),
                                coefs(max_degree),
                                textbox(cur_degree)
    {
        gen_control_points();
        gen_knots();
        gen_coefs();
        initialize();
    };


    void gen_control_points(unsigned seed = time(nullptr));
    int GetClickedPoint(int mouseX, int mouseY);
    friend void operator<<(sf::RenderWindow& window, const b_spline& spline);

    b_spline& operator ++() {
        cur_degree = (cur_degree % max_degree) + 1;
        textbox = cur_degree;
        initialize();
        return *this;
    }

    sf::CircleShape& GetControlPoint(size_t i) {
        return control_points[i];
    }

    void initialize();
    void smart_update(unsigned , float, float);
    void update(int);

private:
    unsigned cur_degree;
    const unsigned control_size, max_degree, offset;
    std::vector<POINT> points;
    std::vector<std::vector<unsigned>> all_knots;
    std::vector<sf::CircleShape> control_points;
    std::vector<std::vector<std::vector<float>>> coefs;
    NumberText textbox;
    void gen_knots();
    void gen_coefs();
    float gen_N(int degree, int control, std::vector<unsigned>& knots, float t);
};

class b_spline_builder {
private:
    unsigned control_size, max_degree, offset;
public:
    b_spline_builder& setControlSize(unsigned control_size) {
        this->control_size = control_size;
        return *this;
    }
    b_spline_builder& setMaxDegree(unsigned max_degree) {
        this->max_degree = max_degree;
        return *this;
    }
    b_spline_builder& setOffset(unsigned offset) {
        this->offset = offset;
        return *this;
    }
    b_spline Build() {
        return {control_size, max_degree, offset};
    }
};


#endif //COMP_GRAPHICS_2_B_SPLINE_H
