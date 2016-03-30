/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }
INPUTS: Two bank statements (array of transactions).
OUTPUT: Transactions having same dates.
ERROR CASES: Return NULL for invalid inputs.
NOTES:
*/

#include <iostream>
int compare1(char *, char*);
int greaterLen(int, int);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	int gLen = greaterLen(ALen, BLen);
	int ctranCount = 0;
	struct transaction * commonDates = (struct transaction *)malloc(sizeof(struct transaction)*gLen);
	for (int fStatment = 0; fStatment < ALen; fStatment++){
		for (int sStatment = 0; sStatment < BLen; sStatment++){
			if (compare1(A[fStatment].date, B[sStatment].date) == 1){
				commonDates[ctranCount] = A[fStatment];
				ctranCount++;
			}
		}
	}
	if (ctranCount == 0)
		return NULL;
	return commonDates;
}


int compare1(char *date1, char* date2){
	int i = 0;
	while (date1[i++] != '\0')
	if (date1[i] != date2[i])
		return 0;
	return 1;
}

int greaterLen(int A, int B){
	if (A < B)
		return A;
	return B;
}