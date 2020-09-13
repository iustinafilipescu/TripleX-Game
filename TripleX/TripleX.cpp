#include<iostream>
#include<ctime>
using namespace std;

void PrintIntroduction(int Difficulty)
{


	cout << "  _______    _____     _____    _____     _         ______       __   __ \n";
	cout << " |__   __|  |  __ \   |_   _|  |  __ \   | |       |  ____|      \ \ / / \n";
	cout << "    | |     | |__) |    | |    | |__) |  | |       | |__          \ V /  \n";
	cout << "    | |     |  _  /     | |    |  ___/   | |       |  __|          > <   \n";
	cout << "    | |     | | \ \    _| |_   | |       | |____   | |____        / . \  \n";
	cout << "    |_|     |_|  \_\  |_____|  |_|       |______|  |______|      /_/ \_\ \n";







	//Print welcome messages to the terminal
	cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
	cout<<" secure server room...\n";
	cout << "Enter the correct code to continue...\n\n";
}
bool PlayGame(int Difficulty)
{
	
	PrintIntroduction(Difficulty);
	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	// Print sum and prod to the terminal
	cout << "+There are 3 numbers in the code\n";
	cout << "+The codes add-up to: " << CodeSum;
	cout << "\n+The codes multiply to give: " << CodeProduct << endl;

	//Store player guess
	int GuessA, GuessB, GuessC;
	cin >> GuessA >> GuessB >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;


	//Check if the player guess is correct
	if (GuessSum = CodeSum && GuessProduct == CodeProduct)
	{
		cout << "\n*** Well done agent! You have extracted a file! Keep going! ***\n";
		return true;
	}
	else
	{
		cout << "\n*** You entered the wrong code! Careful agent! Try again! ***\n";
		return false;
	}
}
int main()
{
	srand(time(NULL)); //create new random sequence based on time of day
	int LevelDifficulty = 1;
	const int MaxLevel = 5;
	while (LevelDifficulty <= MaxLevel) //Loop game until all levels completed
	{
		bool bLevelComplete=PlayGame(LevelDifficulty);
		cin.clear(); // Clears any errors
		cin.ignore(); // Discards the buffer

		if (bLevelComplete)
		{
			LevelDifficulty++;
		}
	}
	
	cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";
	
	return 0;
}


