#include "Game.hpp"

Game::Game() : bird(), obstacles(), score(), game_over(false) {
    // Inițializăm jocul cu câteva obstacole
    generateObstacles();
}

void Game::update() {
    if (game_over) return;
    
    // Actualizăm poziția pasării
    bird.updatePosition();
    
    // Actualizăm obstacolele
    for (auto& obstacle : obstacles) {
        obstacle.moveLeft();
        
        // Verificăm dacă pasărea a trecut de obstacol
        if (!obstacle.isPassed() && bird.getX() > obstacle.getX()) {
            obstacle.markAsPassed();
            score.incrementScore();
        }
    }
    
    // Eliminăm obstacolele care au ieșit din ecran
    obstacles.erase(
        std::remove_if(
            obstacles.begin(), 
            obstacles.end(),
            [](const Obstacle& o) { return o.isOffscreen(); }
        ),
        obstacles.end()
    );
    
    // Generăm noi obstacole dacă este necesar
    if (obstacles.empty() || 
        OBSTACLE_SPAWN_X - obstacles.back().getX() >= OBSTACLE_SPACING) {
        obstacles.emplace_back(OBSTACLE_SPAWN_X);
    }
    
    // Verificăm coliziuni
    checkCollisions();
}

void Game::handleInput(char input) {
    if (input == 'w') {  // w pentru salt
        bird.flap();
    }
}

void Game::generateObstacles() {
    // Generăm primele obstacole la distanțe egale
    for (float x = OBSTACLE_SPAWN_X; x > 300.0f; x -= OBSTACLE_SPACING) {
        obstacles.emplace_back(x);
    }
}

void Game::checkCollisions() {
    // Verificăm coliziunile cu toate obstacolele
    for (const auto& obstacle : obstacles) {
        if (obstacle.isColliding(bird)) {
            bird.die();
            game_over = true;
            return;
        }
    }
    
    // Verificăm dacă pasărea mai este în viață (poate să fi lovit pământul)
    if (!bird.isAlive()) {
        game_over = true;
    }
}

std::ostream& operator<<(std::ostream& out, const Game& game) {
    out << "Game[\n  " << game.bird << ",\n  "
        << game.score << ",\n  Obstacles: ";
    for (const auto& obstacle : game.obstacles) {
        out << "\n    " << obstacle;
    }
    out << "\n]";
    return out;
}