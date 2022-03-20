//
// Created by d3Gaff on 20.03.2022.
//
#include "b_spline.h"

using namespace std;

b_spline::b_spline() {
    gen_control_points();
    gen_knots();
    gen_coefs();
    update();
}



void b_spline::gen_points() {
    for(size_t i = 0; i < MAX_DEG; ++i) {
        for(auto& point : points[i]) {
            point.color = colors[i];
        }
    }
}

void b_spline::update() {
    for(size_t degree = 0; degree < MAX_DEG; ++degree) {
        for(size_t t = 0; t < T_SIZE; ++t) {
            points[degree][t].position = {0, 0};
            for(size_t control = 0; control < CONTROL_SIZE; ++control) {
                points[degree][t].position.x += control_points[control].getOrigin().x * coefs[degree][control][t];
                points[degree][t].position.y += control_points[control].getOrigin().y * coefs[degree][control][t];
            }
        }
    }
}

void b_spline::gen_control_points(unsigned seed) {
    srand(seed);
    for (int i = 0; i < CONTROL_SIZE; ++i) {
        control_points[i].setRadius(2);
        control_points[i].setPosition(rand() % 100 + 100 * i, rand() % 800);
        control_points[i].setFillColor(sf::Color::Blue);
        control_points[i].setOutlineThickness(1.f);
        control_points[i].setOutlineColor(sf::Color::Blue);
    }
}

void b_spline::gen_knots() {
    for(size_t degree = 0; degree < MAX_DEG; ++degree) {
        unsigned i = 0,
                k = degree + CONTROL_SIZE;
        for(;i < degree; ++i) knots[degree][i] = 0;
        for(;i < CONTROL_SIZE; ++i) knots[degree][i] = i-degree+1;
        for(;i <= k; ++i) knots[degree][i] = CONTROL_SIZE-degree+1;
    }
}

void b_spline::gen_coefs() {
    for(size_t degree = 0; degree < MAX_DEG; ++degree) {
        for(size_t control = 0; control < CONTROL_SIZE; ++control) {
            for(size_t t = 0; t < T_SIZE; ++t) {
                coefs[degree][control][t] = gen_coef(degree, control, t*0.1);
            }
        }
    }
}

float b_spline::gen_coef(unsigned deg, unsigned control, float t) {
    if(deg == 0) {
        if((knots[deg][control] <= t) && (t <= knots[deg][control+1]))
            return 1;
        return 0;
    }
    float memb1 = 0, memb2 = 0;
    if(knots[deg][control + deg] == knots[deg][control])
        memb1 = 0;
    else
        memb1 = ((t-knots[deg][control]) / (knots[deg][control + deg] - knots[deg][control])) * coefs[deg-1][control][t*10];
    if(knots[deg][control + deg + 1] == knots[deg][control + 1])
        memb2 = 0;
    else
        memb2 = ((knots[deg][control + deg + 1] - t) / (knots[deg][control + deg + 1] - knots[deg][control + 1])) * coefs[deg-1][control+1][t*10];
    return memb1+memb2;
}

void operator<<(sf::RenderWindow& window, const b_spline& spline) {
    for(auto& control : spline.control_points) {
        window.draw(control);
    }
    for(auto& degree : spline.points) {
        for(auto& point : degree){
            window.draw(&point, 1, sf::Points);
        }
    }
}
