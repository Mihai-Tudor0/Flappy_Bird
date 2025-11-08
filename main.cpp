#include <iostream>
#include "Game.hpp"

int main() {
    Game game;
    char input;

    std::cout << "--- Flappy Wing (Console Edition) ---\n";
    std::cout << "Apasati 'w' pentru a sari.\n";
    std::cout << "Apasati orice alta tasta (+ Enter) pentru a avansa un frame.\n";
    std::cout << "Apasati 'q' (+ Enter) pentru a iesi.\n\n";

    // Afișează starea inițială
    std::cout << game << std::endl;

    // Bucla principală rulează cât timp utilizatorul nu apasă 'q'
    while (std::cin >> input && input != 'q') {

        if (game.isGameOver()) {
            // Dacă jocul s-a terminat, așteptăm 'r' pentru restart
            if (input == 'r') {
                game.reset(); // Aici apelăm funcția de reset
                std::cout << "\n--- JOC NOU ---\n";
            } else {
                // Dacă e game over și nu se apasă 'r', ignorăm inputul
                // (așteptăm 'r' sau 'q')
                continue;
            }
        } else {
            // Dacă jocul este activ, procesăm inputul normal
            game.handleInput(input);
            game.update();
        }

        // Afișăm starea jocului după fiecare acțiune
        std::cout << "---------------------\n";
        std::cout << game << std::endl;

        // Dacă tocmai am intrat în starea de Game Over, afișăm scorul final
        if (game.isGameOver()) {
            std::cout << "\n!!!!!!!!!! GAME OVER !!!!!!!!!!\n";
            // Aici folosim getter-ii din Score pentru afișare
            std::cout << "Scor final: " << game.getScore().getCurrentScore() << "\n";
            std::cout << "High Score: " << game.getScore().getHighScore() << "\n";
            std::cout << "\nApasati 'r' pentru a reincepe sau 'q' pentru a iesi.\n";
        }
    }

    std::cout << "\nJocul s-a terminat. Scor final: " << game.getScore().getCurrentScore() << "\n";
    return 0;
}