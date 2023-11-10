#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

class NumberGuessingGame {
private:
    int targetNumber;
    int maxAttempts;
    int attemptsLeft;
    int wins;
    int losses;
    std::vector<std::string> winMessages;
    std::vector<std::string> loseMessages;
    std::vector<std::string> playAgainMessages;

public:
    NumberGuessingGame() {
        maxAttempts = 20;
        attemptsLeft = maxAttempts;
        wins = 0;
        losses = 0;
        srand(static_cast<unsigned>(time(nullptr)));

        // Define messages for winning, losing, and playing again.
        winMessages = {
            "Congratulations! You're a winner!",
            "You guessed it right! You win!",
            "You're a master of guessing! You win!",
            "Wow, you got it! You win!",
            "You're on fire! You win!"
        };

        loseMessages = {
            "Sorry, you've lost. Better luck next time!",
            "You didn't guess it this time. Try again!",
            "You were close, but not close enough. You lose!",
            "Out of attempts! You lose this one.",
            "Better luck next time. You lose!"
        };

        playAgainMessages = {
            "Do you want to play again? (Y/N): ",
            "Ready for another round? (Y/N): ",
            "Want to test your luck again? (Y/N): ",
            "Play another game? (Y/N): ",
            "Feeling lucky? Play again? (Y/N): "
        };
    }

    void StartGame() {
        targetNumber = rand() % 101; // Generate a random number between 0 and 100
        attemptsLeft = maxAttempts;
        int guess;

        std::cout << "Welcome to the Number Guessing Game!" << std::endl;
        std::cout << "I'm thinking of a number between 0 and 100." << std::endl;
        std::cout << "You have " << attemptsLeft << " attempts to guess it." << std::endl;

        do {
            std::cout << "Enter your guess: ";
            std::cin >> guess;

            if (guess < targetNumber) {
                std::cout << "Try a higher number." << std::endl;
            }
            else if (guess > targetNumber) {
                std::cout << "Try a lower number." << std::endl;
            }
            else {
                // Select a random win message and display it
                std::cout << SelectRandomMessage(winMessages) << std::endl;
                wins++;
                break;
            }

            attemptsLeft--;

            if (attemptsLeft == 0) {
                // Select a random lose message and display it
                std::cout << SelectRandomMessage(loseMessages) << std::endl;
                losses++;
                break;
            }

            std::cout << "Attempts left: " << attemptsLeft << std::endl;

        } while (true);
    }

    // Select and return a random message from the given message vector
    std::string SelectRandomMessage(const std::vector<std::string>& messages) {
        int index = rand() % messages.size();
        return messages[index];
    }

    // Ask if the user wants to play again and return their choice
    char AskToPlayAgain() {
        std::cout << SelectRandomMessage(playAgainMessages);
        char playAgainChoice;
        std::cin >> playAgainChoice;
        return playAgainChoice;
    }

    void PlayGameLoop() {
        char playAgain;

        do {
            StartGame();
            playAgain = AskToPlayAgain();

            switch (playAgain) {
            case 'Y':
            case 'y':
                break;
            case 'N':
            case 'n':
                std::cout << "Thanks for playing. Total Wins: " << wins << " Total Losses: " << losses << std::endl;
                return;
            default:
                std::cout << "Invalid choice. Exiting." << std::endl;
                return;
            }
        } while (true);
    }
};

int main() {
    NumberGuessingGame game;
    game.PlayGameLoop();

    return 0;
}
