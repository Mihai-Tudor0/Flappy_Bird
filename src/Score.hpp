#ifndef FLAPPY_BIRD_SCORE_HPP
#define FLAPPY_BIRD_SCORE_HPP

#include <iostream>

class Score {
private:
    int current_score;
    int high_score;

public:
    Score() : current_score(0), high_score(0) {}
    
    void incrementScore() {
        current_score++;
        if (current_score > high_score) {
            high_score = current_score;
        }
    }
    
    void resetScore() { current_score = 0; }
    int getCurrentScore() const { return current_score; }
    int getHighScore() const { return high_score; }
    
    friend std::ostream& operator<<(std::ostream& out, const Score& score);
};

inline std::ostream& operator<<(std::ostream& out, const Score& score) {
    out << "Score[current=" << score.getCurrentScore()
        << ", high=" << score.getHighScore() << "]";
    return out;
}

#endif //FLAPPY_BIRD_SCORE_HPP