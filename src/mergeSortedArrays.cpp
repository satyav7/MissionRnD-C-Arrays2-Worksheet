/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  {30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
int compare2(char *, char* );

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A==NULL || B==NULL)
		return NULL;
	int i = 0, j = 0, k = 0;
	struct transaction *mergedArray = NULL;
	mergedArray = (struct transaction *)malloc(sizeof(struct transaction)*(ALen + BLen));
	while (k < ALen + BLen)
	{
		if (compare2(A[i].date, B[j].date) == 1)
		{
			mergedArray[k] = B[j];
			k++;
			j++;
		}
		else
		{
			mergedArray[k] = A[i];
			k++;
			i++;
		}
		if (i == ALen)
		{
			while (j < BLen)
			{
				mergedArray[k] = B[j];
				k++;
				j++;
			}
		}
		if (j == BLen)
		{
			while (i < ALen)
			{
				mergedArray[k] = A[i];
				k++;
				i++;
			}
		}
	}
	return mergedArray;
}

int compare2(char *dob1, char* dob2){
	int i, day1=0, day2=0, mnth1=0, mnth2=0, year1=0, year2=0;
	for (i = 0; dob1[i] != '\0' && dob2[i] != '\0'; i++){
		if (i < 2){
			day1 = (day1 * 10) + (dob1[i] - '0');
			day2 = (day2 * 10) + (dob2[i] - '0');
		}
		else if (i>2 && i < 5){
			mnth1 = (mnth1 * 10) + (dob1[i] - '0');
			mnth2 = (mnth2 * 10) + (dob2[i] - '0');
		}
		else if (i>5 && i < 10){
			year1 = (year1 * 10) + (dob1[i] - '0');
			year2 = (year2 * 10) + (dob2[i] - '0');
		}
	}
	if (year1 > year2)
		return 1;
	else if (year1 < year2)
		return -1;
	else
	{
		if (mnth1 > mnth2)
		{
			return 1;
		}
		else if (mnth1 < mnth2)
			return -1;
		else
		{
			if (day1 > day2)
				return 1;
			else if (day1 < day2)
				return -1;
			else
				return 0;
		}
	}
}

