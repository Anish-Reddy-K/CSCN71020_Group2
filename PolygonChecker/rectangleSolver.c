#define _CRT_SECURE_NO_WARNINGS

#include "main.h"

// Sort the array of lengths in ascending order
void swapSort(float* lengths, int len)
{
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
			if (lengths[i] < lengths[j])
			{
				float temp = lengths[i];
				lengths[i] = lengths[j];
				lengths[j] = temp;
			}
}

// Sort the array into a set - identify the unique elements
void filter(float* lengths, int len, float* distinct)
{
	int point = 0;
	for (int i = 0; i < len; i++)
		if (lengths[i] != lengths[i + 1])
			distinct[point++] = lengths[i];
}

// Function to solve an edge case - Checking if 3 lengths satisy pythagorous theorem
bool isTriplet(float distinct[])
{
	if (round(pow(distinct[0], 2) + pow(distinct[1], 2)) == round(pow(distinct[2], 2)) || distinct[2] == 0)
		return true;
	return false;
}

// Function to calculate distance formulas for all the points
float distanceFormula(float a, float b, float x, float y)
{
	return sqrt(pow(x - a, 2) + pow(y - b, 2));
}

// Entire rectangle function 
void rectangleFunction()
{
	printf("Please enter all 8 points of the rectangle seperated by a space: ");

	float points[8] = { 0 };  // Array of 8 points
	float pointLengths[12] = { 0 };  // Array of 12 lengths from 4 pairs
	float distinct[12] = { 0 }; // Array to store sorted set of lengths

	// User input for 12 points
	float x = 0;
	for (int i = 0; i < 8; i++)
		x = scanf("%f", &points[i]);

	// 8 points - 4 (X,Y) Pairs
	float a = points[0], b = points[1], c = points[2], d = points[3], e = points[4], f = points[5], g = points[6], h = points[7];

	// Distance formula loop to calculate all 12 distances
	int index = 0; 
	for (int i = 0; i < 8; i += 2)
	{
		for (int j = 0; j < 8; j += 2)
			if (distanceFormula(points[i], points[i + 1], points[j], points[j + 1]) != 0)
				pointLengths[index++] = distanceFormula(points[i], points[i + 1], points[j], points[j + 1]);
	}

	// Calling the functions on the array of lengths
	int counter = 0;
	swapSort(&pointLengths, 12);
	filter(&pointLengths, 12, &distinct);

	// Using the counter to determine if the points form a rectangle or not
	for (int i = 0; i < 12; i++) 
		if (distinct[i] != 0) 
			counter++;

	// Approach: We are calulating every possible length from all the points entered and storing them in an array
	// The rectangle is the only shape where the diagonals are equal, so if there are 3 unique values - length, breadth and diagonal
	// The shape is a rectangle -  every other polygon except a square and and a rectangle will have more than 3 unique lengths
	// If there is only 3 different lengths that means it is a rectangle - Length, Breadth, Diagonal

	// Also using the isTriplet function to check for a pythagorous triplet
	if (counter == 3 && isTriplet(distinct))
	{
		printf("It is a rectangle.\n");
		printf("The Perimeter of this rectangle is: %.2f\n", (distinct[0] * 2) + (distinct[1] * 2));
		printf("The Area of this rectangle is: %.2f\n", distinct[0] * distinct[1]);
	}

	// As every square is a rectangle,
	// This is the case if the shape is a square - 2 unique distances - Side and Diagonal
	else if (counter == 2 && isTriplet(distinct))
	{
		printf("It is a rectangle.\n");
		printf("The perimeter of this rectangle is: %.2f\n", (distinct[0] * 2) + (distinct[0] * 2));
		printf("The area of this rectangle is: %.2f\n", distinct[0] * distinct[0]);
	}

	else
		printf("It is not a rectangle.");
}