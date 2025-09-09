// CS50_SubstitutionEncryption.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

void GetMessage();
void GetCipher();
string GetString(string String);
bool CheckRepetition(string word);
bool CheckAlpha(string word);


char cipherText[26];
string cipherMessage;
string message;

int main()
{
    std::cout << "Hello World!";
    do
    {
        cipherMessage.clear();
        GetCipher();
        GetMessage();

        int letterValue;
        for (size_t i = 0; i < message.size(); i++)
        {
            letterValue = message[i];
            if (isupper(message[i]))
            {
                letterValue -= 65;
                cipherMessage.push_back(cipherText[letterValue]);
                cipherMessage[i] = toupper(cipherMessage[i]);
            }
            else
            {
                letterValue -= 97;
                cipherMessage.push_back(cipherText[letterValue]);
                cipherMessage[i] = tolower(cipherMessage[i]);
            }
        }
        printf("New Message: %s", cipherMessage.c_str());

    } while (true);
    
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

bool CheckRepetition(string word)
{
    for (char c : word)
    {
        if (count(word.begin(), word.end(), c) > 1)
        {
            return true;
        }
    }
    return false;
}

bool CheckAlpha(string word)
{
    for  (char c : word)
    {
        if (!isalpha(c))
        {
            return true;
        }
    }
    return false;
}

void GetCipher()
{
    do
    {
        string cipher = GetString("\nEnter Cipher: ");
        try
        {
            if (cipher.length() != 26)
            {
                throw - 1;
            }
            if (CheckAlpha(cipher))
            {
                throw - 3;
            }
            for (char c : cipher)
            {
                c = toupper(c);
            }
            //check repetition
            if (CheckRepetition(cipher))
            {
                throw - 2;
            }

            //apply cipher chars to alphabet
            for (size_t i = 0; i < sizeof(cipherText); i++)
            {
                cipherText[i] = cipher[i];
            }
            return;

        }
        catch (const std::exception&)
        {
            printf("Error: Exception found");
        }
        catch (int throwNo)
        {
            printf("Error: ");
            if (throwNo == -1)
            {
                printf("Incorrect amount of characters entered, enter 26");
            }
            else if (throwNo == -2)
            {
                printf("Repeated characters");
            }
            else if (throwNo == -3)
            {
                printf("Can only accept alphabetical characters");
            }
        }
    } while (true);
    
}

void GetMessage()
{
    do
    {
        string word = GetString("Secret Message: ");
        try
        {
            for (char c : word)
            {
                if (!isalpha)
                {
                    throw - 1;
                }
            }
            message = word;
            return;
        }
        catch (const std::exception&)
        {
            printf("ERROR: Eception");
        }
        catch (int throwNo)
        {
            printf("ERROR");
        }
    } while (true);
    
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

/* Checklist of things to include :
~User input 26 character
    -validate 26 characters,
    -validate every character is different
~Assign Encrypted character to alphabet
~Enter phrase
~Replace each character with encrypted counterpart
~print cipher text
*/   
