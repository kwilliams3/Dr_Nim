#include <iostream>
#include <string>

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
}

int main() {
    using namespace std;
    int numberOfMarbles = 15;
    int* numberOfMarblesPtr = &numberOfMarbles;
    cout << endl
         << "------------------------------------------------------------------------" << endl
         << "Instructions:" << endl
         << endl
         << "This game is a test of your wit! You'll be going head to head - mind to" << endl
         << "mind, against the famous Dr. Nim! The rules are simple. There are 15" << endl
         << "marbles at the beginning of each game, and Dr. Nim is always courteous" << endl
         << "enough to let you go first. Each turn you may choose to take 1, 2, or" << endl
         << "even 3 marbles. Once you make your choice, it's Dr. Nim's turn. He too" << endl
         << "is limited to taking only 1, 2, or 3 marbles each turn. You're goal is" << endl
         << "to be the one who takes the very last marble. In doing so, you will" << endl
         << "render yourself victorious against Dr. Nim - proving once and for all" << endl
         << "that you are the true mastermind! Good luck!" << endl
         << "------------------------------------------------------------------------" << endl;
    while (numberOfMarbles != 0) {
        playersTurn(numberOfMarblesPtr);
        drNimsTurn(numberOfMarblesPtr);
    }
    std::cout << "Alas! Dr. Nim has claimed victory!";
    return 0;
}