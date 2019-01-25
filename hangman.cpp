#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
const int MAX_TRIES = 5;
int letterFill(char, string, string&);

	string name;
	char letter;
	int num_of_wrong_guesses = 0;
	string word;
	
void instruct(){
		cout << "\n\nEach letter is represented by an asterisk.";
		cout << "\n\nYou have to type only one letter in one try.";
		cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the country.";
		cout << "\n---------------------------------";
}

int letterFill(char guess, string secretword, string &guessword)
{	int i;
	int matches = 0;
	int len = secretword.length();
	for (i = 0; i< len; i++)
	{   // Did we already match this letter in a previous guess?
		if (guess == guessword[i])
			return 0;
			
		// Is the guess in the secret word?
		if (guess == secretword[i])
		{   guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}

int main()
{   srand(time(NULL));   // ONLY NEED THIS ONCE!

	// welcome the user
	cout << "\n\nWelcome to hangman!! Guess a country that comes into your mind.";
	// Ask user for for Easy, Average, Hard
	int level;
	
	while(level!=4){
	cout<< "\n1 - for Easy level";
	cout<< "\n2 - for Average level";
	cout<< "\n3 - for Hard level";
	cout<< "\n4 - To exit"<<endl<<endl;
	cout<< "Choose a level" << endl<<endl; 
	
	cin >> level;
	// compare level 
	
	switch(level){
	case 1:
	{   int num_of_wrong_guesses = 0;
		//put all the string inside the array here
		string easy[] = { "india", "japan", "nepal", "china", "bhutan", "canada", "mexico", "cuba", "france", "fiji", "italy", "oman" };
		string word;

		int n = rand() % 12;
		word = easy[n];

		//call the function here for guessing game
		// Initialize the secret word with the * character.
		string unknown(word.length(), '*');
		
		instruct();
		
		// Loop until the guesses are used up
		while (num_of_wrong_guesses < MAX_TRIES){
		    cout << "\n\n" << unknown;
			cout << "\n\nGuess a letter: ";
			cin >> letter;
			// Fill secret word with letter if the guess is correct,
			// otherwise increment the number of wrong guesses.
			if (letterFill(letter, word, unknown) == 0)
			{   cout << endl << "Whoops! That letter isn't in here!" << endl;
				num_of_wrong_guesses++;
			}
			else
			{	cout << endl << "You found a letter! Isn't that exciting?" << endl;
			}
			// Tell user how many guesses has left.
			cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
			cout << " guesses left." << endl;
			// Check if user guessed the word.
			if (word == unknown)
			{	cout << word << endl;
				cout << "Yeah! You got it!" << endl;
				cout<< "press enter"<<endl;
				break;
			}
		}
		if (num_of_wrong_guesses == MAX_TRIES)
		{   cout << "\nSorry, you lose...you've been hanged." << endl;
			cout << "The word was : " << word << endl;
		} 
		
		cin.ignore();
		cin.get();
		cout<< "Choose a level to play further or press 4 to exit" << endl;
		break;
	}

	case 2:
	{   int num_of_wrong_guesses = 0;
		//put all the string inside the array here
		string average[] = { "madagascar", "azerbaijan", "kyrgyzstan", "afghanistan", "philippines", "romania", "switzerland", "thailand", "ukraine", "vietnam", "yemen", "zimbabwe" };

		int n = rand() % 12;
		word = average[n];

		//call the function here for guessing game
		// Initialize the secret word with the * character.
		string unknown(word.length(), '*');
		 instruct();
		// Loop until the guesses are used up
		while (num_of_wrong_guesses < MAX_TRIES)
		{	cout << "\n\n" << unknown;
			cout << "\n\nGuess a letter: ";
			cin >> letter;
			// Fill secret word with letter if the guess is correct,
			// otherwise increment the number of wrong guesses.
			if (letterFill(letter, word, unknown) == 0)
			{	cout << endl << "Whoops! That letter isn't in there!" << endl;
				num_of_wrong_guesses++;
			}
			else
			{	cout << endl << "You found a letter! Isn't that exciting?" << endl;
			}
			// Tell user how many guesses has left.
			cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
			cout << " guesses left." << endl;
			// Check if user guessed the word.
			if (word == unknown)
			{	cout << word << endl;
				cout << "Yeah! You got it!"<<endl;
				cout << "Press Enter" << endl;
				break;
			}
		}
		if (num_of_wrong_guesses == MAX_TRIES)
		{	cout << "\nSorry, you lose...you've been hanged." << endl;
			cout << "The word was : " << word << endl;
		}
		cin.ignore();
		cin.get();
		cout<< "Choose a level to play further or press 4 to exit" << endl;
		break;
	}

	case 3:
	{    	int num_of_wrong_guesses = 0;
		//put all the string inside the array here
		string hard[] = { "turkmenistan", "french guiana", "new caledonia", "american samoa", "botswana", "burundi", "comoros", "djibouti", "gibraltar", "kiribati", "lesotho", "mauritania" };
		int n = rand() % 12;
		word = hard[n];
		//call the function here for guessing game
		// Initialize the secret word with the * character.
		string unknown(word.length(), '*');
		 instruct(); 
		// Loop until the guesses are used up
		while (num_of_wrong_guesses < MAX_TRIES)
		{	cout << "\n\n" << unknown;
			cout << "\n\nGuess a letter: ";
			cin >> letter;
			// Fill secret word with letter if the guess is correct,
			// otherwise increment the number of wrong guesses.
			if (letterFill(letter, word, unknown) == 0)
			{	cout << endl << "Whoops! That letter isn't in there!" << endl;
				num_of_wrong_guesses++;
			}
			else
			{	cout << endl << "You found a letter! Isn't that exciting?" << endl;
			}
			// Tell user how many guesses has left.
			cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
			cout << " guesses left." << endl;
			// Check if user guessed the word.
			if (word == unknown)
			{	cout << word << endl;
				cout << "Yeah! You got it!"<<endl;
				cout << "Press Enter" << endl;
				break;
			}
		}
		if (num_of_wrong_guesses == MAX_TRIES)
		{	cout << "\nSorry, you lose...you've been hanged." << endl;
			cout << "The word was : " << word << endl;
		}
		cin.ignore();
		cin.get();
		//return 0;
		cout<< "Choose a level to play further or press 4 to exit" << endl;
		break;
	} } } } 
