// CS50_Caesar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

string GetString(string String);
int GetNum(string String);
char EncryptLetter(char letter, int level);

int main()
{
    std::cout << "Caesars Cipher\n";
    int encryptLvl;
    string phrase;
    string cipher;

    //get encryption level
    encryptLvl = GetNum("Encryption Level: ");
    encryptLvl = encryptLvl % 26;
    

    //get phrase
    phrase = GetString("Enter message: ");
     
    //encrypt
    for (char& c : phrase)
    {
        c = EncryptLetter(c, encryptLvl);
    }

    printf("\nOutput: %s", phrase.c_str());

    //output cipher
}

string GetString(string String)
{
    string output;
    do
    {
        printf(String.c_str());
        getline(cin, output);
    } while (output.empty());
    return output;
}

int GetNum(string String)
{
    printf(String.c_str());
    int number;
    while (!(cin >> number))
    {
        printf("INVALID, Enter a number: ");
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return number;
}

char EncryptLetter(char letter, int level)
{
    if (level < 0)
    {
        //for negative
        level += 26;
    }
    int change = level % 26;
    int extra;
    int newLetter;
    //uppercase
    if (isalpha(letter))
    {
        if (letter >= 65 && letter <= 90)
        {
            extra = letter + change - 90;
            extra = extra % 26;
            newLetter = extra + 90;
        }
        else
        {
            extra = letter + change - 122;
            extra = extra % 26;
            newLetter = extra + 90;
        }
        printf("\nNew: %c", newLetter);
        return newLetter;
    }
    else
    {
        return letter;
    }
    
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
