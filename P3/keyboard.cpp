#include <iostream>
#include <string>
#include <cassert>

using namespace std;


bool hasCorrectSyntax(string s);
int encodeSong(string song, string& instructions, int& badBeat);
char encodeNote(int octave, char noteLetter, char accidentalSign);
bool isPlayableSong(string s);

int main()
{
	assert(hasCorrectSyntax("D5//D/"));
	assert(!hasCorrectSyntax("D5//Z/"));
	string instrs;
	int badb;
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("D5//D/", instrs, badb) == 0 && instrs == "R H"  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("D5//Z/", instrs, badb) == 1 && instrs == "xxx"  &&  badb == -999);
	assert(encodeSong("D5//D8/", instrs, badb) == 2 && instrs == "xxx"  &&  badb == 3);
	assert(encodeSong("D5//D8////F#9/", instrs, badb) == 2 && instrs == "xxx"  &&  badb == 3);
	assert(encodeSong("D5//D3/G#4//Ab5Bb3/E#9/", instrs, badb) == 2 && instrs == "xxx"  &&  badb == 7);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("D5//D8////////L/", instrs, badb) == 1 && instrs == "xxx"  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("D5//D////F#4Bb5/", instrs, badb) == 0 && instrs == "R H   [#)]"  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("", instrs, badb) == 0 && instrs == ""  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("//", instrs, badb) == 0 && instrs == "  "  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("C/C/G/G/A/A/G/", instrs, badb) == 0 && instrs == "GGLLQQL"  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("D3/F#3/A3/D4//D3F#3A3D4/", instrs, badb) == 0 && instrs == ".8DH [.8DH]"  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("G3B3DD5//G/A/A3B/C5/B3D5//G//G//CE5//C5/D5/E5/F#5/B3G5//G//G/", instrs, badb) == 0 && instrs == "[SFHR] LQ[DW]E[FR] L L [GT] ERT*[FU] L L"  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("DADDA/", instrs, badb) == 0 && instrs == "[HQHHQ]"  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("D5//Z/", instrs, badb) == 1 && instrs == "xxx"  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("D5//D8/////////L/", instrs, badb) == 1 && instrs == "xxx"  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("DADDa/", instrs, badb) == 1 && instrs == "xxx"  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("DADDA", instrs, badb) == 1 && instrs == "xxx"  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("//////////////A/", instrs, badb) == 0 && instrs == "              Q"  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("DAZZA/", instrs, badb) == 1 && instrs == "xxx"  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("DAZZA", instrs, badb) == 1 && instrs == "xxx"  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("D/A/D/D/A/", instrs, badb) == 0 && instrs == "HQHHQ"  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("dADDA/", instrs, badb) == 1 && instrs == "xxx"  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("D5//D8/", instrs, badb) == 2 && instrs == "xxx"  &&  badb == 3);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("/F#3Ab2D0/", instrs, badb) == 2 && instrs == "xxx"  &&  badb == 2);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("F#3Ab2D4///Gb3// /", instrs, badb) == 2 && instrs == "xxx"  &&  badb == 6);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("/F#3Ab2D4///Gb3//Fb1/", instrs, badb) == 2 && instrs == "xxx"  &&  badb == 7);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("A/B/C/D/E/F/G//C#8/", instrs, badb) == 2 && instrs == "xxx"  &&  badb == 9);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("A/B1/C/D/E/F/G//C#8/", instrs, badb) == 2 && instrs == "xxx"  &&  badb == 2);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("/ABCDEFG//A#B#C#D#E#F#G#//Ab5/", instrs, badb) == 0 && instrs == " [QWGHJKL] [%E!@K#$] ("  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("Fb2G5D3/A3/Db4/", instrs, badb) == 0 && instrs == "[CU.]D!"  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("A##/", instrs, badb) == 1 && instrs == "xxx"  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("Abb/", instrs, badb) == 1 && instrs == "xxx"  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("A33/", instrs, badb) == 1 && instrs == "xxx"  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("A99/", instrs, badb) == 1 && instrs == "xxx"  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("#A3/", instrs, badb) == 1 && instrs == "xxx"  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("bA3/", instrs, badb) == 1 && instrs == "xxx"  &&  badb == -999);
	instrs = "xxx"; badb = -999; // so we can detect whether these get changed
	assert(encodeSong("3A/", instrs, badb) == 1 && instrs == "xxx"  &&  badb == -999);


	cerr << "All tests succeeded" << endl;
}

bool hasCorrectSyntax(string s)
{
	if (s.size() == 0)	//empty
		return true;
	else if (s[s.size() - 1] != '/')		//last character not a /
		return false;
	else
	{
		for (int i = 0; i < s.size(); i++)		//check each character
		{
			//		Capital letter A-G							"/" is 47 and numbers 0-9 is 48-57					#					b
			if (!((char(s[i]) >= 65 && char(s[i]) <= 71) || (char(s[i]) >= 47 && char(s[i]) <= 57) || (char(s[i]) == 35) || (char(s[i]) == 98)))
				return false;
					// a '#'				a 'b'						a number 0-9
			else if ((char(s[0]) == 35) || (char(s[0]) == 98) || ((char(s[0]) >= 48 && char(s[0]) <= 57)))
				return false;
			else //if it doesn't start with a number or accidental and has correct chars
			{
					// number 0-9
				if (char(s[i]) >= 48 && char(s[i]) <= 57)
				{
					// spot before is not a '#'				not a 'b'					not a letter A-G
					if ((char(s[i - 1]) != 35) && (char(s[i - 1]) != 98) && (!((char(s[i - 1]) >= 65) && (char(s[i - 1]) <= 71))))
						return false;
					// a '#'					a 'b'
					else if ((char(s[i - 1]) == 35) || (char(s[i - 1]) == 98))
					{
						//a letter A-G
						if (char(s[i - 2]) >= 65 && char(s[i - 2]) <= 71)
							break;
						else
							return false;
					}
				}
				if ((char(s[i]) == 35) || (char(s[i]) == 98))
				{
					if ((char(s[i - 1]) == 35) || (char(s[i - 1]) == 98))
						return false;
				}
			}
		}
		return true;
	}
	
}




char encodeNote(int octave, char noteLetter, char accidentalSign)
{
	// This check is here solely to report a common CS 31 student error.
	if (octave > 9)
	{
		cerr << "********** encodeNote was called with first argument = "
			<< octave << endl;
	}

	// Convert Cb, C, C#/Db, D, D#/Eb, ..., B, B#
	//      to -1, 0,   1,   2,   3, ...,  11, 12

	int note;
	switch (noteLetter)
	{
	case 'C':  note = 0; break;
	case 'D':  note = 2; break;
	case 'E':  note = 4; break;
	case 'F':  note = 5; break;
	case 'G':  note = 7; break;
	case 'A':  note = 9; break;
	case 'B':  note = 11; break;
	default:   return ' ';
	}
	switch (accidentalSign)
	{
	case '#':  note++; break;
	case 'b':  note--; break;
	case ' ':  break;
	default:   return ' ';
	}

	// Convert ..., A#1, B1, C2, C#2, D2, ... to
	//         ..., -2,  -1, 0,   1,  2, ...

	int sequenceNumber = 12 * (octave - 2) + note;

	string keymap = "Z1X2CV3B4N5M,6.7/A8S9D0FG!H@JK#L$Q%WE^R&TY*U(I)OP";
	if (sequenceNumber < 0 || sequenceNumber >= keymap.size())
		return ' ';
	return keymap[sequenceNumber];
}

bool isPlayableSong(string s)
{
	char noteLetter;
	int octave = 4;
	char accidentalSign = ' ';
	if (hasCorrectSyntax(s))
	{
		for (int i = 0; i < s.size(); i++) //check all characters
		{
			
			{
				if ((i == 0) && (s[i] == '/'))
					noteLetter = 'A';
				if ((char(s[i]) != 47)) //not a slash
				{
					//a letter A-G
					if (char(s[i]) >= 65 && char(s[i]) <= 71)
						//set note letter
						noteLetter = s[i];
					// a '#'					a 'b' 
					else if ((char(s[i]) == 35) || (char(s[i]) == 98))
						//set accidental
						accidentalSign = s[i];
					// if a number
					else
						//set octave
						octave = s[i] - '0';
				}
				// if char after is a /						or a note
				if ((char(s[i + 1]) == 47) || ((char(s[i + 1]) >= 65 && char(s[i + 1]) <= 71)))
				{	//test if individual note is playable
					if ((encodeNote(octave, noteLetter, accidentalSign)) == ' ')
						return false;
					else
					{
						accidentalSign = ' ';
						octave = 4;
					}
				}
			}
		}
		return true;
	}
	else
		return false;
}


int encodeSong(string song, string& instructions, int& badBeat)
{
	char noteLetter;
	int octave = 4;
	char accidentalSign = ' ';

	if (isPlayableSong(song))
	{
		instructions = "";

		if (song.size() == 0)
			instructions = "";
		if (song[0] == '/')
			instructions = " ";
		string bracketNote;
		{
			for (int i = 0; i < song.size(); i++) //check all characters
			{
				{
					// if two slashes in a row
					if (((i + 1) < song.size()) && ((char(song[i]) == 47) && (char(song[i + 1]) == 47)))
					{
						instructions += " ";
					}
					if ((char(song[i]) != 47)) //not a slash
					{
						{
							//a letter A-G
							if (char(song[i]) >= 65 && char(song[i]) <= 71)
								//set note letter
								noteLetter = song[i];
							// a '#'						a 'b' 
							else if ((char(song[i]) == 35) || (char(song[i]) == 98))
								//set accidental
								accidentalSign = song[i];
							// if a number
							else
								//set octave
								octave = song[i] - '0';
						}
						if ((i + 1) < song.size())
						{
							//if character after is a /
							if (char(song[i + 1]) == 47)
							{
								if (bracketNote == "")
								{
									instructions += encodeNote(octave, noteLetter, accidentalSign);
								}
								else
								{	//add note to inside bracket, print [bracketnote] and reset bracket note to empty
									bracketNote += encodeNote(octave, noteLetter, accidentalSign);
									instructions += "[" + bracketNote + "]";
									bracketNote = "";
								}
								octave = 4;
								accidentalSign = ' ';
							}
							//if character after is a letter A-G
							if (char(song[i + 1]) >= 65 && char(song[i + 1]) <= 71)
							{
								bracketNote += encodeNote(octave, noteLetter, accidentalSign);
								octave = 4;
								accidentalSign = ' ';
							}
						}
						
					}

				}
			}
		}
		return 0;
	}
	else if (!hasCorrectSyntax(song))
		return 1;
	else
	{
		int beat = 0;

		for (int i = 0; i < song.size(); i++) //check all characters
		{
			if ((i == 0) && (song[i] == '/'))
				beat++;
			else
			{
				if ((char(song[i]) != 47)) //not a slash
				{
					//a letter A-G
					if (char(song[i]) >= 65 && char(song[i]) <= 71)
						//set note letter
						noteLetter = song[i];
					// a '#'					a 'b' 
					else if ((char(song[i]) == 35) || (char(song[i]) == 98))
						//set accidental
						accidentalSign = song[i];
					// if a number
					else
						//set octave
						octave = song[i] - '0';
				}
				// if char after is a /						
				if ((char(song[i + 1]) == 47))
				{
					beat++;
					if ((encodeNote(octave, noteLetter, accidentalSign)) == ' ')
					{
						badBeat = beat;
						return 2;
					}
					else
					{
						octave = 4;
						accidentalSign = ' ';
					}
				}	//if char after is a note char
				if ((char(song[i + 1]) >= 65 && char(song[i + 1]) <= 71))
				{	//test if individual note is playable
					if ((encodeNote(octave, noteLetter, accidentalSign)) == ' ')	//not playable
					{
						badBeat = beat;
						return 2;
					}
					else
					{
						octave = 4;
						accidentalSign = ' ';
					}
				}
			}
		}
		return 2;
	}
}