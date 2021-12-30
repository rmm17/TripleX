#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty) {
    std::cout << "You are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room.\nYou need to enter the correct codes to continue...\n\n";
}

void PrintNextLevel(int Difficulty) {
    std::cout << "You have decoded the server room correctly! You are now at level " << Difficulty << " secure server room.\nYou need to enter the correct codes to continue...\n\n";
}

void RetryLevel(int Difficulty) {
    std::cout << "You have failed to decode the server room! You are at level " << Difficulty << ".\nPlease retry...\n\n";
}

bool PlayGame(int Difficulty, bool PreviousLevelComplete) {
    //Declare and initialize Triple X codes
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    //Declare and initialize the sum and product of the codes
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print starting story text

    if (!PreviousLevelComplete) {
        RetryLevel(Difficulty);
    }
    else if (Difficulty == 1) {
        PrintIntroduction(Difficulty);
    }
    else {
        PrintNextLevel(Difficulty);
    }
    
    //Print sum and product
    std::cout << "+ There are three numbers in the code.\n";
    std::cout << "+ The codes add up to: " << CodeSum << "\n";
    std::cout << "+ The codes multiply to give: " << CodeProduct << "\n\n";

    //Store player guess
    int GuessA, GuessB, GuessC;
    std::cout << "Take your guess: ";
    std::cin >> GuessA >> GuessB >> GuessC; 

    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    //Check if the player's guess is correct
    bool bReturn = CodeSum == GuessSum && CodeProduct == GuessProduct;
    if (bReturn) {
        std::cout << "\nYou win!\n\n";
    } else {
        std::cout << "\nYou lose.\n\n";
    }

    return bReturn;
}

//Initializes TripleX Game. Prints initial story text to terminal and initializes game mechanics.
int main() {         
    const int MaxDifficulty = 5;
    int LevelDifficulty = 1;
    bool bLevelComplete = true;

    srand(time(NULL));

    while(LevelDifficulty <= MaxDifficulty) { // Loop game until all levels completed
        bLevelComplete = PlayGame(LevelDifficulty, bLevelComplete);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if(bLevelComplete) {
            ++LevelDifficulty;
        }    
    }

    std::cout << "\n\nCongratulations! You have completed the game!\n\n";

    return 0;
}