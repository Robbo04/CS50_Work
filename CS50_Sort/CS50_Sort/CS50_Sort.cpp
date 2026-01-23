// CS50_Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <list>
#include <vector>

using namespace std;

void BubbleSort();
void SelectionSort();
void MergingSort();

void MergeSort(int arr[], int left, int right);

void Merge(int arr[], int left, int mid, int right);

void ListSorting();

list<int> hoursSlept = { 4, 3, 7, 5, 3, 12, 6, 7, 2, 1 };

int numberArray[5] = { 5, 4, 3, 1, 2 };
int bubbleArray[5] = { 5, 4, 3, 1, 2 };
int selectArray[5] = { 5, 4, 3, 1, 2 };
int mergeArray[5] = { 5, 7, 3, 9, 2 };


int arraySize;

int mergeStep = 0;

int main()
{
	printf("Sorting algorithms");
	
	//ListSorting();

	arraySize = sizeof(numberArray) / 4;
	printf("\n%i", arraySize);
	
	printf("\nBefore array sorts:");
	for (int num : numberArray)
	{
		printf("\t%i", num);
	}
	BubbleSort();
	SelectionSort();
	MergingSort();
}

void BubbleSort()
{
	printf("\n");
	//cyle through comparing each int at a time and moving it over
	bool hasSwapped;
	for (size_t i = 0; i < arraySize-1; i++)
	{
		hasSwapped = false;
		for (size_t j = 0; j < arraySize - i - 1; j++)
		{
			if (bubbleArray[j] > bubbleArray[j+1])
			{
				swap(bubbleArray[j], bubbleArray[j+1]);
				hasSwapped = true;
			}
		}
		printf("\nStep %i bubble sort:", i+1);
		for (int num : bubbleArray)
		{
			printf("\t%i", num);
		}
		if (!hasSwapped)
		{
			break;
		}
	}
	printf("\nAfter bubble sort:");
	for (int num : bubbleArray)
	{
		printf("\t%i", num);
	}
	printf("\n");
}
void SelectionSort()
{
	for (size_t i = 0; i < arraySize; i++)
	{
		int lowest = selectArray[i];
		int lowestPos = i;
		for (size_t j = i+1; j < arraySize; j++)
		{
			if (lowest > selectArray[j])
			{
				lowest = selectArray[j];
				lowestPos = j;
			}
		}
		swap(selectArray[i], selectArray[lowestPos]);
		printf("\nStep %i selection sort: ", i);
		for (int num : selectArray)
		{
			printf("\t%i", num);
		}

	}

	printf("\nAfter selection sort:");
	for (int num : selectArray)
	{
		printf("\t%i", num);
	}
	//for size of array
	//go through every element is greater than
	//put the smallest at the start
}
void MergingSort()
{
	mergeStep = 0;
	printf("\n");
	MergeSort(mergeArray, 0, arraySize);
}


void MergeSort(int arr[], int left, int right)
{
	if (left < right) {

		// Calculate the midpoint
		int mid = left + (right - left) / 2;

		// Sort first and second halves
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		// Merge the sorted halves
		Merge(arr, left, mid, right);

		printf("\nStep %i: ", mergeStep);
		for (int num : mergeArray)
		{
			printf("\t%i", num);
		}
		mergeStep++;
	}
}

void ListSorting()
{
	printf("\nlist before sorting:");
	for (int hours : hoursSlept)
	{
		printf("\t%i", hours);
	}
	hoursSlept.sort();
	printf("\nlist after sort:");
	for (int hours : hoursSlept)
	{
		printf("\t%i", hours);
	}
}

void Merge(int arr[], int left, int mid, int right) {
	
	int n1 = mid - left + 1; int n2 = right - mid; 
	
	// Temporary arrays 
	int* L = new int[n1]; int* R = new int[n2]; 
	
	// Copy data 
	for (int i = 0; i < n1; i++) 
		L[i] = arr[left + i]; 
	for (int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j]; 
	int i = 0, j = 0, k = left; 
	
	// Merge back into arr 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k++] = L[i++];
		}
		else
		{
			arr[k++] = R[j++];
		}
	} 
	// Leftovers 
	while (i < n1)
	{
		arr[k++] = L[i++];
	} 
	while (j < n2)
	{
		arr[k++] = R[j++];
	} 
	delete[] L; 
	delete[] R;
}

