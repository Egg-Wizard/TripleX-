#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty, int MaxDiff)
{
 // This is our context/story for the game
    std::cout << "\n\nYou are a disgraced thief looking to reclaim your honor by stealing the Royal Diamond from within the King's chest.\n"; 
    std::cout << "Having snuck your way inside floor " << Difficulty << 
    " of the castle and made your way to one of the " << MaxDiff << " chests, you find that it is locked by a secret 3-digit code.\n";
    std::cout << "Upon further inspection, barring the lock, there is a magical trap affixed to this chest. Failure to properly enter the code will alert the castle guards.\n";
    std::cout << "You have but one chance. With your honor on the line and any failure undoubtedly leading you to the gallows, you begin to enter the three digit code...\n";
    std::cout << R"(
        
            .-""-.
           / .--. \
          / /    \ \
          | |    | |
          | |.-""-.|
         ///`.::::.`\
        ||| ::/  \:: ;
        ||; ::\__/:: ;
         \\\ '::::' /
          `=':-..-'`
    )" << '\n';
}


bool PlayGame(int Difficulty, int MaxDiff)
{
    PrintIntroduction(Difficulty, MaxDiff);
    // These are our declared variables
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print CodeSum and CodeProduct to player
    std::cout << "\n- There are 3 numbers in the code\n";
    std::cout << "- The codes add-up to: " << CodeSum;
    std::cout << "\n- The codes multiply to give: " << CodeProduct << "\n\n";
    std::cout << "  What code do you enter? \n"; 
    
    //Assign player input to Guess variables
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "\n";

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Print player input calculation results
    std::cout << "  The codes you entered add up to: " << GuessSum << std::endl; 
    std::cout << "  The codes you entered multiplied to give: " << GuessProduct << std::endl << std::endl;

    //Determine whether the player's GuessSum and GuessProduct match the CodeSum and CodeProduct.
    //Return custom message depending on degree of correctness
    if(GuessSum == CodeSum && GuessProduct == CodeProduct && Difficulty != 5)
        {
            std::cout << "Your sum and product were both correct! You didn't find the diamond, but you did find some loot. Keep looking!\n";
            return true;
        }
    if(GuessSum == CodeSum && GuessProduct == CodeProduct && Difficulty == 5)
    {
        std::cout << "After searching through many chests, you finally found the diamond!\n";
        return true;
    }
    else
    {
        if(GuessSum == CodeSum && GuessProduct != CodeProduct)
            {
                std::cout << "Your sum is correct!...But your product was not. The gallows await you...\n";
            }

        if(GuessProduct == CodeProduct && GuessSum != CodeSum)
            {
                std::cout << "Your product is correct!...But your sum was not. The gallows await you...\n";
            }

        if(GuessSum != CodeSum && GuessProduct != CodeProduct)
            {
                std::cout << "Your inept ability to calculate both the product and the sum has cost you your life. The gallows await you...\n"; 
            }
        return false;
    }
}
int main()
{
    srand(time(NULL)); //Seeding based on time of day
    int LevelDifficulty = 1;
    const int MaxLevelDifficulty= 5; 
    while(LevelDifficulty <= MaxLevelDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty, MaxLevelDifficulty);
        std::cin.clear(); //clears errors?? wtf is this
        std::cin.ignore(); // clears buffer?? wtf is this

        if (bLevelComplete)
        {
            ++LevelDifficulty;
            system("pause");
        }
        else
        {
            LevelDifficulty = 1;
            system("pause");
        }
        
        
    }
    std::cout << "\n\nYou have reached the pinnacle of thieving mastery, attaining all treasures and asscending to the greatest of heights!\n";
    std::cout << "Your honor is restored, and you bring back quite the treasure as well!";
    std::cout << "\nThanks for playing!\n\n";
    system("pause");
}