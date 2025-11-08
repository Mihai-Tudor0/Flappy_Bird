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


    // Așteaptă input de la tastatura.txt sau utilizator
    // Citește caractere până la 'q' sau până la Game Over
    while (std::cin >> input && input != 'q' && !game.isGameOver()) {

        // Trimite inputul la joc (doar spatiul contează)
        game.handleInput(input);

        // Actualizează starea jocului
        game.update();

        // Afișează noua stare a jocului
        std::cout << "---------------------\n";
        std::cout << game << std::endl;

        if (game.isGameOver()) {
            std::cout << "\n!!!!!!!!!! GAME OVER !!!!!!!!!!\n";
        }
    }

    std::cout << "\nJocul s-a terminat.\n";
    return 0;
}