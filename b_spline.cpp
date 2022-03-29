#include "b_spline.h"
#include <iostream>
#include <algorithm>

#define EPS 0.00001f
using namespace std;

static TotalDuration updDur("TOTAL UPDATE");
static TotalDuration coefDur("TOTAL COEFS");
static TotalDuration initDur("TOTAL INIT");

void b_spline::gen_control_points(unsigned seed) {
    srand(seed);
    for (int i = 0; i < control_size; i++) {
        control_points[i].setRadius(2);
        control_points[i].setPosition(rand() % 1280, rand() % 800);
        control_points[i].setFillColor(sf::Color::Blue);
        control_points[i].setOutlineThickness(1.f);
        control_points[i].setOutlineColor(sf::Color::Blue);
    }
}

void b_spline::gen_knots() {
    for(size_t deg = 1; deg <= max_degree; ++deg) {
        all_knots[deg-1].resize(deg + control_size + 1);
        unsigned i = 0,
                k = deg + control_size;
        for (; i < deg; ++i) all_knots[deg-1][i] = 1;
        for (; i < control_size; ++i) all_knots[deg-1][i] = i - deg + 1;
        for (; i <= k; ++i) all_knots[deg-1][i] = control_size - deg + 1;
    }
}

void b_spline::gen_coefs() {
    ADD_DURATION(coefDur);
    size_t size = control_size;
    for(size_t deg = 1; deg <= max_degree; ++deg) {
        coefs[deg-1].resize((size--) * offset, std::vector<float>(control_size));
        for (unsigned t = all_knots[deg-1][0] * offset; t < all_knots[deg-1][deg + control_size] * offset; ++t) {
            for (int control = 0; control < control_size; ++control) {
                coefs[deg-1][t][control] = gen_N(deg, control, all_knots[deg-1], t * 1.f / offset);
            }
        }
        std::cout << deg << '\n';
    }
}

float b_spline::gen_N(int degree, int control, std::vector<unsigned>& knots, float t) {
    if (degree == 0) {
        if ((knots[control] <= t) && (t <= knots[control + 1])) return 1.f;
        return 0.f;
    }

    float memb1 = 0.f, memb2 = 0.f;
    if (knots[degree + control] == knots[control])
        memb1 = 0.f;
    else {
        memb1 = ((t - knots[control]) / (knots[degree + control] - knots[control])) * gen_N(degree - 1, control, knots, t);
    }

    if (knots[degree + control + 1] == knots[control + 1])
        memb2 = 0.f;
    else
        memb2 = ((knots[degree + control + 1] - t) / (knots[degree + control + 1] - knots[control + 1])) * gen_N(degree - 1, control + 1, knots, t);
    return (memb1 + memb2 == 2.f) ? 1.f : memb1 + memb2;
}


void b_spline::initialize() {
    ADD_DURATION(initDur);
    points.clear();
    points.resize((control_size - cur_degree + 1) * offset);
    for (unsigned t = all_knots[cur_degree-1][0] * offset; t < all_knots[cur_degree-1][cur_degree + control_size] * offset; ++t) {
        points[t].position.x = 0.f;
        points[t].position.y = 0.f;
        points[t].color = sf::Color::Green;
        for (int control = 0; control < control_size; ++control) {
            points[t].position.x += control_points[control].getPosition().x *
                                               coefs[cur_degree-1][t][control];
            points[t].position.y += control_points[control].getPosition().y *
                                               coefs[cur_degree-1][t][control];
        }
    }
}

void b_spline::smart_update(unsigned controlPoint, float x, float y) {
    ADD_DURATION(updDur);
    for (unsigned t = all_knots[cur_degree-1][std::max((int)(controlPoint-cur_degree), 0)] * offset;
        t < all_knots[cur_degree-1][std::min(cur_degree + controlPoint + 1, control_size + cur_degree)] * offset;
        ++t) {
        points[t].position.x += (x - control_points[controlPoint].getPosition().x)
                * coefs[cur_degree-1][t][controlPoint];
        points[t].position.y += (y - control_points[controlPoint].getPosition().y)
                * coefs[cur_degree-1][t][controlPoint];
    }
    control_points[controlPoint].setPosition(x, y);
}

void b_spline::update(int controlPoint) {
    for (unsigned t = all_knots[cur_degree-1][0] * offset; t < all_knots[cur_degree-1][cur_degree + control_size] * offset; ++t){
        if (coefs[cur_degree-1][t][controlPoint] >= EPS){
            points[t].position.x = 0.f;
            points[t].position.y = 0.f;
            for (int control = 0; control < control_size; ++control){
                points[t].position.x += control_points[control].getPosition().x
                        * coefs[cur_degree-1][t][control];
                points[t].position.y += control_points[control].getPosition().y
                        * coefs[cur_degree-1][t][control];
            }
        }
    }
}

void operator<<(sf::RenderWindow& window, const b_spline& spline) {
    window.draw(spline.textbox.text);
    for(const auto& circ : spline.control_points) {
        window.draw(circ);
    }
    for(const auto& point : spline.points) {
        window.draw(&point, 1, sf::Points);
    }
}

int b_spline::GetClickedPoint(int mouseX, int mouseY) {
    for (int i = 0; i < control_points.size(); i++) {
        if (control_points[i].getGlobalBounds().contains(mouseX, mouseY)) {
            return i;
        }
    }
    return -1;
}
