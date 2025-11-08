#ifndef FLAPPY_BIRD_GAME_HPP
#define FLAPPY_BIRD_GAME_HPP

#include <vector>
#include "Bird.hpp"
#include "Obstacle.hpp"
#include "Score.hpp"

class Game {
private:
    Bird bird;
    std::vector<Obstacle> obstacles;
    Score score;
    bool game_over;
    
    static constexpr float OBSTACLE_SPAWN_X = 800.0f;
    static constexpr float OBSTACLE_SPACING = 300.0f;

public:
    Game();
    
    void update();
    void handleInput(char input);
    bool isGameOver() const { return game_over; }
    
    void generateObstacles();
    void checkCollisions();
    
    friend std::ostream& operator<<(std::ostream& out, const Game& game);
};

#endif //FLAPPY_BIRD_GAME_HPP