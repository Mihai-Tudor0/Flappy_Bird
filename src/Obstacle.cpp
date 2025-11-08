#include "Obstacle.hpp"
#include <random>

Obstacle::Obstacle(float startX) 
    : x_pos(startX)
    , passed(false) {
    // Generare aleatoare a poziției gap-ului
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> gap_dist(150.0f, 450.0f);
    gap_y = gap_dist(gen);
    gap_height = GAP_SIZE;
}

void Obstacle::moveLeft() {
    x_pos -= MOVEMENT_SPEED;
}

bool Obstacle::isColliding(const Bird& bird) const {
    // Verifică dacă pasărea se află în dreptul obstacolului
    if (bird.getX() < x_pos - PIPE_WIDTH/2 || bird.getX() > x_pos + PIPE_WIDTH/2) {
        return false;
    }
    
    // Verifică dacă pasărea se află în interiorul gap-ului
    if (bird.getY() > gap_y && bird.getY() < gap_y + gap_height) {
        return false;
    }
    
    return true;
}

std::ostream& operator<<(std::ostream& out, const Obstacle& obstacle) {
    out << "Obstacle[x=" << obstacle.x_pos 
        << ", gap_y=" << obstacle.gap_y 
        << ", " << (obstacle.passed ? "passed" : "not passed") << "]";
    return out;
}