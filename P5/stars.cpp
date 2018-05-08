#define _CRT_SECURE_NO_DEPRECATE
#include "utilities.h"
#include <iostream>
#include<cstring>
#include<cctype>

using namespace std;

const char WORDFILENAME[] = "C:/Users/augus/OneDrive - personalmicrosoftsoftware.ucla.edu/UCLA/CS31/CS31 Assignment 5/P5/P5.txt";
const int MAXWORDS = 9000;
const int MINACCESS = 0;
const int MAXPROBELENGTH = 100;

/******************************************
Function Declarations
*******************************************/

int runOneRound(const char words[][7], int nWords, int wordnum);
bool probeHasCorrectSyntax(const char probe[]);
int stars(const char probe[], const char secretWord[]);
int planets(const char probe[], const char secretWord[]);
bool probeWordInArray(const char wordList[][7], const char probe[], int nWords);

int main()
{
	char wordList[MAXWORDS][MAXWORDLEN + 1];
	const int nWords = getWords(wordList, 9000, WORDFILENAME);
	const int MAXACCESS = (nWords - 1);
	int desiredRounds;
	int numtries = 0;
	int min;
	int max;
	int runningTotal = 0;

	if (nWords < 1)						//error when the text file supplied has no words in it
	{
		cout << "No words were loaded, so I can't play the game.";
		return 0;
	}

	cout << "How many rounds do you want to play? "; 
	cin >> desiredRounds;				
	cin.ignore(10000, '\n');							//remove empty space after number since I will be asking for a c string right after in my runOneRound function

	if (desiredRounds < 0)					//error when user inputs a negative round number
	{
		cout << "The number of rounds must be positive.";
		return 0;
	}

	for (int i = 1; i < (desiredRounds + 1); i++)    //run a loop for the number of desired rounds
	{
		cout << endl << "Round " << i << endl;
		int wordNum = randInt(MINACCESS, MAXACCESS);
		cerr << wordList[wordNum];
		int WORDLENGTH = strlen(*(wordList + wordNum));
		cout << "The secret word is " << WORDLENGTH << " letters long." << endl;	//output the round number header and length of the secret word each round
		numtries = runOneRound(wordList, nWords, wordNum);
		if (numtries == -1)						//error when runOneRound function is passed bad arguments
		{
			cout << "bad call of runOneRound function";
			return 0;
		}
		if (i == 1)				//on first round, set min and max to 1
		{
			min = numtries;
			max = numtries;
		}
		if (numtries < min)		 //if a new min record is set, reset min variable
			min = numtries;
		if (numtries > max)		 //if a new max record is set, reset max variable
			max = numtries;
		runningTotal += numtries; //append number of tries in current round to the running total
		double avg = static_cast<double>(runningTotal) / i; //set average to a double specified version of running total over the current round
		cout.setf(ios::fixed);								//make sure average is displayed with 2 decimal places
		cout.precision(2);
		if (numtries != 1)									//when multiple tries, say "tries"
		{
			cout << "You got it in " << numtries << " tries." << endl
				<< "Average: " << avg << ", minimum: " << min << ", maximum: " << max << endl;
		}
		else											//when single try, say "try"
			cout << "You got it in " << numtries << " try." << endl
			<< "Average: " << avg << ", minimum: " << min << ", maximum: " << max << endl;
	}
}

bool probeHasCorrectSyntax(const char probe[]) //checks the probe word for correct syntax
{
	if (strlen(probe) < MINWORDLEN || strlen(probe) > MAXWORDLEN) //if it's too short or too long, false
		return false;
	for (int i = 0; i < strlen(probe); i++)			//if any characters are not lowercase, false
	{
		if (islower(probe[i]) == 0)
			return false;
	}
	return true;			//if all checks are passed, true
}

int stars(const char probe[], const char secretWord[]) //returns the number of stars
{
	int stars = 0;
	for (int a = 0; a < strlen(probe) && a < strlen(secretWord); a++) //go through each letter until the end of the shortest word 
	{
		if (probe[a] == secretWord[a])  //if anything matches, add to stars
			stars++;
	}
	return stars;
}

int planets(const char probe[], const char secretWord[]) //returns the number of planets
{
	int alreadyUsedProbe[MAXPROBELENGTH];		//an array of zeros. any time a letter is used as a match from the probe word, it's position will be flagged as "used" 
	int alreadyUsedSecretWord[MAXWORDLEN + 1];	//an array of zeros. any time a letter is used as a match from the secret word, it's position will be flagged as "used"
	for (int x = 0; x < MAXPROBELENGTH; x++)
		alreadyUsedProbe[x] = 0;
	for (int x = 0; x < MAXWORDLEN + 1; x++)
		alreadyUsedSecretWord[x] = 0;
	int planets = 0;
	for (int b = 0; b < strlen(secretWord); b++) //go through each letter of the secret word
	{
		if (secretWord[b] != probe[b])    //as long as the position doesn't correspond with a star
		{
			for (int c = 0; c < strlen(probe); c++) //go through each letter of the probe to check matches with current letter of the secret word
			{
				if (secretWord[b] == probe[c]) //if something matches,
				{
					if (strlen(probe) <= strlen(secretWord))  //to catch to make sure we don't access the array past it's length in the next line (this check is to make sure the matching letter of the probe is not a star, so we don't need to check the excess letters since they can't make a star anyway)
					{
						if (probe[c] == secretWord[c])  //if it corresponds to a star
						{
							alreadyUsedProbe[c] = 1;      //mark both positions as already used
							alreadyUsedSecretWord[c] = 1;
							continue;						  //skip to the next letter in the probe word
						}
					}
					if (alreadyUsedSecretWord[b] == 1) //if the letter in the secret word has already been used, move to the next letter in secret word
						break;
					if (alreadyUsedProbe[c] == 1)		//if the letter in the probe word has already been used, move to the next letter in the probe word
						continue;	
					else								//if neither have been used yet,
						{
							planets++;					//add to planets and mark both as used
							alreadyUsedProbe[c] = 1;
							alreadyUsedSecretWord[b] = 1;
						}
				}
			}
		}
		else			//if they make a star
		{
			alreadyUsedProbe[b] = 1;      //mark both positions as already used
			alreadyUsedSecretWord[b] = 1;
		}
	}
	for (int x = 0; x < MAXPROBELENGTH; x++)
		alreadyUsedProbe[x] = 0;
	for (int x = 0; x < MAXWORDLEN + 1; x++)
		alreadyUsedSecretWord[x] = 0;
	return planets;
}


bool probeWordInArray(const char wordList[][7], const char probe[], int nWords)  //function for "i don't know that word" error
{
	for (int j = 0; j < nWords; j++) //go through every word in the array
	{
		if (strcmp(wordList[j], probe) == 0) //if it matches any word along the way, true
			return true;
	}
	return false;			//if it gets through w/o matching up, false
}

int runOneRound(const char words[][7], int nWords, int wordnum) //runs one round starting at the probe word prompt and ending when the user guesses right
{
	int numtries = 0;
	if (nWords < 0 || wordnum < 0 || wordnum >= nWords) //error for when the function is passed bad arguments
		return -1;
	for(;;)		//loop until they guess right
	{	
		cout << "Probe word: ";				//ask for the probe word and get it
		char probeWord[100];
		cin.getline(probeWord, 100);
		if (!probeHasCorrectSyntax(probeWord)) //bad syntax ==> error
			cout << "Your probe word must be a word of 4 to 6 lower case letters." << endl;
		else if (!probeWordInArray(words, probeWord, nWords))  //unknown word ==> error
		{
			cout << "I don't know that word." << endl;
		}
		else
		{
			if (stars(probeWord, words[wordnum]) == strlen(words[wordnum]) && strlen(words[wordnum]) == strlen(probeWord)) //when they guess right (every character is a star)
			{
				numtries++; //count that as a guess and end the loop
				break;
			}
			else //if probe was wrong,
			{
				numtries++;
				cout << "Stars: " << stars(probeWord, words[wordnum]) << ", Planets: " << planets(probeWord, words[wordnum]) << endl; //add a guess and output number of stars and planets
			}
		}
	}
	return numtries; //return how many guesses they made to get it right
}