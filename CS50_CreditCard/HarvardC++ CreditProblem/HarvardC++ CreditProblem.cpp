// HarvardC++ CreditProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <limits>
#include <stdexcept>
#include <string>

using namespace std;

bool ValidateNum(string Number, int Quantity);
int GetDigit(string input, int digit);
void IndividualDigits(string input, long long num);

enum cardtype {VISA, Mastercard, AmericanExpress, NA};

//ToDo
cardtype CheckType(int64_t size);
bool CheckStartingDigits(string input, cardtype type);

int quantity = 0;

int main()
{
    printf("Credit Problem\n");
    
    while (true)
    {
        string input;
        printf("\nEnter Number: ");
        cin >> input;
        //Validate out of bounds, wrong character inclusion or invalid input
        try
        {
            long long num = stoll(input);
            if (input.find('-') < input.length())
            {
                throw -1;
            }
            else if (input.length() < 10)
            {
                throw - 2;
            }
            printf("Valid\n");
            printf("Digits: %zi", input.length());

            IndividualDigits(input, num);

            
            if (ValidateNum(input, input.length()))
            {
                printf("\nChecksum passed");
            }
            else
            {
                printf("\nChecksum failed");
            }
            
        }
        catch (const invalid_argument&)
        {
            if (input == "x")
            {
                return 0;
            }
            printf("Invalid");
        }
        catch (const out_of_range&)
        {
            printf("Out of Range");
        }
        catch (int noThrown)
        {
            if (noThrown == -1)
            {
                printf("Includes incorrect character");
            }
            else if (noThrown == -2)
            {
                printf("Number of digits is doesn't match");
            }
        }

        printf("\n");
        
    }
    
}


bool ValidateNum(string Number, int Quantity)
{
    int total = 0;
    int totalX = 0;
    int totalY = 0;
    bool toggle(false);

    int doubledDigit;


    for (size_t i = 0; i < Quantity; i++)
    {
        //get the digit from then end
        //printf("\n%c", Number[Quantity - i-1]);
        if (toggle)
        {
            //convert character to int
            doubledDigit = Number[Quantity - i - 1] - '0';
            //double digit
            doubledDigit *= 2;
            if (doubledDigit>9)
            {
                totalX += 1 + (doubledDigit - 10);
            }
            else
            {
                totalX += doubledDigit;
            }
        }
        else
        {
            totalY += Number[Quantity - i - 1] - '0';
        }
        toggle = !toggle;
        //printf("\n%c", Number[i]);
        
    }
    total = totalX + totalY;
    printf("\nResult: %i", total);

    if (total % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int GetDigit(string input, int digit)
{
    return 2;
}

void IndividualDigits(string input, long long num)
{
    for (size_t i = 0; i < input.length(); i++)
    {
        int64_t digitCalc = 1;
        for (size_t j = 0; j < i + 1; j++)
        {
            digitCalc *= 10;
        }
        int64_t output = num % digitCalc;
        while (output >= 10)
        {
            output /= 10;
        }
        printf("\n%llds : %i", digitCalc / 10, output);
    }
}

cardtype CheckType(int64_t size)
{
    return cardtype();
}

bool CheckStartingDigits(string input, cardtype type)
{
    int firstTwoChar = 0;
    switch (type)
    {
    case VISA:
        if (input[0] == '3')
        {
            return true;
        }
        else
            return false;
        break;
    case Mastercard:
        firstTwoChar = stoi(input.substr(0, 2));
        if (firstTwoChar >50 && firstTwoChar <56)
        {
            return true;
        }
        else
        {
            return false;
        }
            
        break;
    case AmericanExpress:
        firstTwoChar = stoi(input.substr(0, 2));
        if (firstTwoChar == 34 || firstTwoChar == 37)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    default:
        printf("\nERROR with CheckStartingString");
        break;
    }
    return false;
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
