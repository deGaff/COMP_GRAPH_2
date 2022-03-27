//
// Created by d3Gaff on 20.03.2022.
//
#include "b_spline.h"

using namespace std;

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
        for (; i < deg; ++i) all_knots[deg-1][i] = 1.f;
        for (; i < control_size; ++i) all_knots[deg-1][i] = i - deg + 1;
        for (; i <= k; ++i) all_knots[deg-1][i] = control_size - deg + 1;
    }
}


float b_spline::gen_N(int degree, int control, std::vector<float>& knots, float t) {
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
    return memb1 + memb2;
}


void b_spline::update() {
    float rev_offset = 1.f/offset;
    points.clear();
    points.resize((control_size - cur_degree + 1) * offset);
    for (float t = all_knots[cur_degree-1][0]; t < all_knots[cur_degree-1][cur_degree + control_size]; t += rev_offset) {
        points[(t * offset)].position.x = 0.f;
        points[(t * offset)].position.y = 0.f;
        points[(t * offset)].color = sf::Color::Green;
        for (int control = 0; control < control_size; ++control) {
            float temp = gen_N(cur_degree, control, all_knots[cur_degree-1], t);
            points[(t * offset)].position.x += control_points[control].getPosition().x * temp;
            points[(t * offset)].position.y += control_points[control].getPosition().y * temp;
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