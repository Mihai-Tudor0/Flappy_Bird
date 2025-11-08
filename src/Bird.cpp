#include "Bird.hpp"

Bird::Bird(float startX, float startY)
    : x_pos(startX)
    , y_pos(startY)
    , velocity(0.0f)
    , alive(true) {
}

Bird::Bird(const Bird& other)
    : x_pos(other.x_pos)
    , y_pos(other.y_pos)
    , velocity(other.velocity)
    , alive(other.alive) {
}

Bird& Bird::operator=(const Bird& other) {
    if (this != &other) {
        x_pos = other.x_pos;
        y_pos = other.y_pos;
        velocity = other.velocity;
        alive = other.alive;
    }
    return *this;
}

Bird::~Bird() {
    // Deocamdată nu am resurse de eliberat
}

void Bird::flap() {
    if (!alive) return;
    velocity = FLAP_FORCE;
}

void Bird::updatePosition() {
    if (!alive) return;

    velocity += GRAVITY;
    if (velocity > MAX_VELOCITY) {
        velocity = MAX_VELOCITY;
    }

    y_pos += velocity;

    // Verificare coliziune cu pământul (presupunem că pământul este la y=600)
    if (y_pos > 600) {
        y_pos = 600;
        die();
    }
    // Verificare coliziune cu plafonul
    if (y_pos < 0) {
        y_pos = 0;
        velocity = 0;
    }
}

std::ostream& operator<<(std::ostream& out, const Bird& bird) {
    out << "Bird[pos=(" << bird.x_pos << "," << bird.y_pos
        << "), velocity=" << bird.velocity
        << ", " << (bird.alive ? "alive" : "dead") << "]";
    return out;
}