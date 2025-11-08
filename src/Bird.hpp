#ifndef FLAPPY_BIRD_BIRD_HPP
#define FLAPPY_BIRD_BIRD_HPP

#include <iostream>

class Bird {
private:
    float x_pos;
    float y_pos;
    float velocity;
    bool alive;
    
    static constexpr float GRAVITY = 0.8f;
    static constexpr float FLAP_FORCE = -10.0f;
    static constexpr float MAX_VELOCITY = 15.0f;

public:
    // Constructor de inițializare
    explicit Bird(float startX = 100.0f, float startY = 300.0f);
    
    // Regula celor trei
    Bird(const Bird& other);
    Bird& operator=(const Bird& other);
    ~Bird();

    // Funcții membre publice
    void flap();
    void updatePosition();
    bool isAlive() const { return alive; }
    void die() { alive = false; }
    
    // Getteri pentru poziție
    float getX() const { return x_pos; }
    float getY() const { return y_pos; }
    
    // Operatorul de afișare
    friend std::ostream& operator<<(std::ostream& out, const Bird& bird);
};

#endif //FLAPPY_BIRD_BIRD_HPP