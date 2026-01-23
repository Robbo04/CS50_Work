// PluralityVote.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <list>

using namespace std;

typedef struct
{
    string name;
    int votes;
} 
Candidate;

int candidateCount;
Candidate candidates[9];

bool Vote(string name);
void GetCandidates(Candidate candidates[], int& count);
void PrintWinner();


int main(int argc, char* argv[])
{
    std::cout << "Plurality vote!\n";

    
    candidateCount = 0;
    GetCandidates(candidates, candidateCount);

    printf("\n");
    int voterCount;
    do
    {
        printf("\nHow many voters are there: ");
        cin >> voterCount;
        cin.ignore();
    } while (voterCount < 0 || voterCount > 10);
    
    for (size_t i = 0; i < voterCount; i++)
    {
        printf("Vote: ");
        string name;
        getline(cin, name);
        Vote(name);
    }

    PrintWinner();
    return 0;

}

void GetCandidates(Candidate candidates[], int& count)
{
    do
    {
        printf("How many candidates? (1-9): "); 
        cin >> count; 
        cin.ignore(); 
    } while (count <= 0 || count >= 10);
    
    // clear leftover newline 
    for (int i = 0; i < count; i++) 
    { 
        printf("Enter candidate %i:", i+1);
        getline(cin, candidates[i].name); 
        candidates[i].votes = 0; 
    }
}

bool Vote(string name)
{
    for (size_t i = 0; i < candidateCount; i++)
    {
        if (name == candidates[i].name)
        {
            candidates[i].votes++;
            return 1;
        }
    }
    return 0;
}
void PrintWinner()
{
    int highestScore = 0;
    list<Candidate> winnningCandidates;

    for(Candidate c : candidates)
    {
        if (c.votes > highestScore)
        {
            winnningCandidates.clear();
            winnningCandidates.push_back(c);
            highestScore = c.votes;
        }
        else if (c.votes == highestScore)
        {
            winnningCandidates.push_back(c);
        }
    }

    printf("\nWINNER");
    for (Candidate winner : winnningCandidates)
    {
        printf("\n%s: %i", winner.name.c_str(), winner.votes);
    }
}



/*
Plan

Get candidates
Get number of voters
get votes
if new create new vote
if not add to vote count



*/