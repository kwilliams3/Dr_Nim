#include <iostream>
#include <string>
#include <thread>
#include <chrono>

void playersTurn(int* numberOfMarbles) {

    // Ask the user how many marbles they'd like to take
    bool legalChoice = false;
    int marblesToTake;
    do {
        std::cout << "How many marbles would you like to take (" << *numberOfMarbles << " left): ";
        std::string userChoice;
        std::getline(std::cin, userChoice);
        if (userChoice != "1" && userChoice != "2" && userChoice != "3") {
            std::cout << "Please enter 1, 2, or 3." << std::endl;
        } else {
            legalChoice = true;
            marblesToTake = std::stoi(userChoice);
        }
    } while (!legalChoice);

    // Decrement the number of marbles the user took from the number of marbles available
    *numberOfMarbles -= marblesToTake;
    std::cout << "You have taken " << marblesToTake << " marble(s) - leaving Dr. Nim with "
              << *numberOfMarbles << " marble(s)." << std::endl << std::endl;
}

void drNimsTurn(int* numberOfMarbles) {
    std::cout << "Dr. Nim is thinking about his move . . ." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // Decrement the appropriate number of marbles
    int marblesToTake = *numberOfMarbles % 4;
    *numberOfMarbles -= marblesToTake;
    std::cout << "Dr. Nim has decided to take " << marblesToTake << " marble(s) - leaving you with "
              << *numberOfMarbles << " marble(s)." << std::endl << std::endl;
}

int main() {
    int numberOfMarbles = 12;
    int* numberOfMarblesPtr = &numberOfMarbles;
    std::cout << "\n"
         << "------------------------------------------------------------------------\n"
         << "Instructions:\n"
         << "\n"
         << "This game is a test of your wit! You'll be going head to head - mind to\n"
         << "mind, against the famous Dr. Nim! The rules are simple. There are 12\n"
         << "marbles at the beginning of each game, and Dr. Nim is always courteous\n"
         << "enough to let you go first. Each turn you may choose to take 1, 2, or\n"
         << "even 3 marbles. Once you make your choice, it's Dr. Nim's turn. He too\n"
         << "is limited to taking only 1, 2, or 3 marbles each turn. You're goal is\n"
         << "to be the one who takes the very last marble. In doing so, you will\n"
         << "render yourself victorious against Dr. Nim - proving once and for all\n"
         << "that you are the true mastermind! Good luck!\n"
         << "------------------------------------------------------------------------\n\n";
    while (numberOfMarbles != 0) {
        playersTurn(numberOfMarblesPtr);
        drNimsTurn(numberOfMarblesPtr);
    }
    std::cout << "Alas! Dr. Nim has claimed victory!" << std::endl;
    return 0;
}