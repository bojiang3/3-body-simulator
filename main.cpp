#include <iostream>
#include <cmath>

using namespace std;

const double G = 6.674e-11; // gravitational constant

struct Body {
    double mass;
    double x, y;
    double vx, vy;
};

double distance(Body b1, Body b2) {
    double dx = b2.x - b1.x;
    double dy = b2.y - b1.y;
    return sqrt(dx*dx + dy*dy);
}

void update_velocity(Body& b1, Body b2, double dt) {
    double dist = distance(b1, b2);
    double force = G * b1.mass * b2.mass / (dist * dist);
    double fx = force * (b2.x - b1.x) / dist;
    double fy = force * (b2.y - b1.y) / dist;
    b1.vx += fx / b1.mass * dt;
    b1.vy += fy / b1.mass * dt;
}

void update_position(Body& b, double dt) {
    b.x += b.vx * dt;
    b.y += b.vy * dt;
}

int main() {
    Body b1 = {1.0, 0.0, 0.0, 0.0, 0.0};
    Body b2 = {1.0, 1.0, 0.0, 0.0, 10.0};
    Body b3 = {1.0, 0.0, 1.0, 10.0, 0.0};
    double dt = 0.01;
    for (int i = 0; i < 10000; i++) {
        update_velocity(b1, b2, dt);
        update_velocity(b1, b3, dt);
        update_velocity(b2, b3, dt);
        update_position(b1, dt);
        update_position(b2, dt);
        update_position(b3, dt);
        cout << b1.x << " " << b1.y << " " << b2.x << " " << b2.y << " " << b3.x << " " << b3.y << endl;
    }
    return 0;
}
