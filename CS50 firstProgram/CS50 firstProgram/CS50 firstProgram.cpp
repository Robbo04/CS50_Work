// CS50 firstProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

//functions
string GetString(string String);
int GetNum(string String);
int GetNum(string String, int min, int max);
void Update();
void DrawRamp();
void DrawRamp(int height);
void DrawPyramid(int height);

int main()
{
    /*bool programAlive = true;
    string name = GetString("What is your name? ");
    printf("%s, Welcome! ", name.c_str());
    int age = GetNum("How old are you? ", 2, 120);
    printf("you are %d years old", age);*/
    /*do
    {
        Update();
    } while (programAlive);*/
    
    //DrawRamp(GetNum("enter height:", 0, 23));
    DrawPyramid(GetNum("enter height:", 1, 10));



    return 0;
}

void Update()
{
    string task;
    cin >> task;
    if (task == "Hi")
    {
        printf("XXX\n");
    }
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

int GetNum(string question, int min, int max)
{
    //bool valid = false;
    int number;
    while (true)
    {
        printf(question.c_str());
        while (!(cin >> number))
        {
            printf("INVALID, Enter a number: ");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (number >= min && number <= max)
        {
            return number;
        }
        else
        {
            printf("\nInvalid, number out of bounds, enter between %d and %d.\n", min, max);
        }
    }
    

}

void DrawRamp()
{
    for (size_t i = 0; i < 6; i++)
    {
        //collumns
        for (size_t j = 0; j < 6; j++)
        {
            if (5 - j <= i)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }

        }
        printf("\n");
    }
}

void DrawRamp(int height)
{
    for (size_t i = 0; i < height; i++)
    {
        //collumns
        for (size_t j = 0; j < height; j++)
        {
            if (height - 1 - j <= i)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }

        }
        printf("\n");
    }
}

void DrawPyramid(int height)
{
    for (size_t i = 0; i < height; i++)
    {
        //collumns
        for (size_t j = 0; j < (height*2)+1; j++)
        {
            if (height - 1 - j <= i)
            {
                printf("#");
            }
            else if (j > height && j < (height*2) + 1 - (height - i - 1))
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }

        }
        printf("\n");
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
