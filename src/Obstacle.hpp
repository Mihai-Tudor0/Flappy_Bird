#ifndef FLAPPY_BIRD_OBSTACLE_HPP
#define FLAPPY_BIRD_OBSTACLE_HPP

#include <iostream>
#include "Bird.hpp"

class Obstacle {
private:
    float x_pos;
    float gap_height;
    float gap_y;
    bool passed;
    
    static constexpr float MOVEMENT_SPEED = 3.0f;
    static constexpr float PIPE_WIDTH = 50.0f;
    static constexpr float GAP_SIZE = 150.0f;

public:
    explicit Obstacle(float startX = 800.0f);
    
    void moveLeft();
    bool isColliding(const Bird& bird) const;
    bool isPassed() const { return passed; }
    void markAsPassed() { passed = true; }
    
    float getX() const { return x_pos; }
    bool isOffscreen() const { return x_pos + PIPE_WIDTH < 0; }
    
    friend std::ostream& operator<<(std::ostream& out, const Obstacle& obstacle);
};

#endif //FLAPPY_BIRD_OBSTACLE_HPP