// CS50_Scrabble.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>


using namespace std;

string GetString(string String);
char GetChar(string String);
bool PlayAgain();
string ToUpper(string word);


int ScoreWord(string word);

int main()
{
    
    string p1Word;
    string p2Word;
    int p1Score;
    int p2Score;

    int p1W = 0;
    int p2W = 0;

    printf("Scrabble\n");

    
    do
    {
        //get players word
        p1Word = GetString("Player 1's word: ");
        p1Word = ToUpper(p1Word);

        p2Word = GetString("Player 2's word: ");
        p2Word = ToUpper(p2Word);

        printf("Player 1: %s", p1Word.c_str());
        p1Score = ScoreWord(p1Word);
        printf("\nPlayer 2: %s", p2Word.c_str());
        p2Score = ScoreWord(p2Word);

        printf("\nPlayer 1: %i\tPlayer 2: %i. ", p1Score, p2Score);
        if (p1Score > p2Score)
        {
            printf("Player 1 wins!");
            p1W++;
        }
        else if (p2Score > p1Score)
        {
            printf("Player 2 wins!");

            p2W++;
        }
        else
        {
            printf("Tie!");
        }
        printf("\nP1 %i : %i P2", p1W, p2W);

    } while (PlayAgain());
}


string GetString(string String)
{
    string output;
    do
    {
        printf(String.c_str());
        cin >> output;
    } while (output.empty());
    return output;
}

char GetChar(string String)
{
    string output;
    do
    {
        printf(String.c_str());
        cin >> output;
    } while (output.length() != 1 || !isalpha(output[0]));
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return output[0];
}

bool PlayAgain()
{
    do
    {
        char response = GetChar("\nDo you want to play again? Y or N: ");
        if (response == 'Y' || response == 'y')
        {
            return true;
        }
        else if (response == 'n' || response == 'N')
        {
            return false;
        }
        printf("INVALID, Enter a Y or N: ");
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (true);
}

int ScoreWord(string word)
{
    int total = 0;

    for (char a : word)
    {
        switch (a)
        {
        case 'A': case 'E': case 'I': case 'L': case 'N': case 'O': case 'R': case 'S': case 'T': case 'U':
            total++;
            break;
        case 'D': case 'G':
            total += 2;
            break;
        case 'B': case 'C': case 'M': case 'P':
            total += 3;
            break;
        case 'F': case 'V': case 'W': case 'Y':
            total += 4;
            break;
        case 'K':
            total += 5;
            break;
        case 'J':
            total += 8;
            break;
        case 'Q': case 'Z':
            total += 10;
            break;
        default:
            break;
        }
        printf("\n%c New score: %i", a, total);
    }
    
    return total;
}

string ToUpper(string word)
{
    string s = word;
    for (size_t i = 0; i < s.length(); i++)
    {
        s[i] = toupper(s[i]);
    }
    return s;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
