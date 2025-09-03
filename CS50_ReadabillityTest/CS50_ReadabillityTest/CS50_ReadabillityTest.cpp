// CS50_ReadabillityTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

string GetString(string String);
int GetWordCount(string text);
int GetLetters(string text);
float GetAvgLetters(int words, int letters);

int GetSentenceCount(string text);
float GetAvgSentences(int words, int sentences);




int main()
{
    std::cout << "Readabillity Level Checker!";
    do
    {
        try
        {
            string wordInput = GetString("\nText: ");
            if (wordInput == "x")
            {
                return 0;
            }
            //check if string begins or ends with a space
            if (wordInput.front() == ' ' || wordInput.back() == ' ')
            {
                throw -1;
            }
            if (wordInput.find("  ") != string::npos)
            {
                throw - 2;
            }
            int wordCount = GetWordCount(wordInput);
            int letterCount = GetLetters(wordInput);
            float avgLetters = GetAvgLetters(wordCount, letterCount);
            int sentenceCount = GetSentenceCount(wordInput);
            float avgSentences = GetAvgSentences(wordCount, sentenceCount);


            //index = 0.0588 * L - 0.296 * S - 15.8
            //split index into two parts: A = 0.0588 * L, B = 0.296 * S

            float a = 0.0588 * avgLetters;
            float b = 0.296 * avgSentences;
            float wordIndex = a - b - 15.8;
            
            printf("\nGrade: ");
            if (wordIndex < 1)
            {
                printf("Below grade 1");
            }
            else
            {
                printf("%i", (int) floor(wordIndex));
            }
            
            
            
        }
        catch (const std::exception&)
        {
            printf("Caught Error getting string");
        }
        
        catch (int noThrown)
        {
            printf("\nERROR: ");
            switch (noThrown)
            {
            case -1:
                printf("Cannot begin or end with a space.");
                break;
            case -2:
                printf("\nCannot include multiple spaces in a row");
            default:
                printf("\nUnknown");
                break;
            }
        }


        
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

int GetWordCount(string text)
{
    int counter = 1;
    for (char c : text)
    {
        if (c == ' ')
        {
            counter++;
        }
    }
    printf("Words: %i", counter);
    return counter;
}

int GetLetters(string text)
{
    int counter = 0;
    for (char c : text)
    {
        if (isalpha(c))
        {
            counter++;
        }
    }
    printf("\nLetters: %i", counter);
    return counter;
}

float GetAvgLetters(int words, int letters)
{
    float x = (float) 100 / words;
    float output = x * letters;
    printf("\nAvg Letters per 100 words: %f", output);
    return output;
}

int GetSentenceCount(string text)
{
    int counter = 0;
    for (size_t i = 0; i < text.length(); i++)
    {
        if (text[i] == '?' || text[i] == '!' || text[i] == '.' || text[i] == ';')
        {
            counter++;
        }
    }
    if (text.back() != '.' && text.back() != '?' && text.back() != '!' || text.back() == ';')
    {
        counter++;
    }
    printf("\nSentences: %i", counter);
    return counter;
}

float GetAvgSentences(int words, int sentences)
{
    float x = (float) 100 / words;
    float output = x * sentences;
    printf("\nAvg Sentences per 100 words: %f", output);
    return output;
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
