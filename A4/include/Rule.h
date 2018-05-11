
#ifndef _RULE_
#define _RULE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bule{
    char* keyWord;
    char* response;
    double userRating;
    double systemRating;
    double learningRate;
    int timesUsed;
}; 
typedef struct bule Rule;

Rule* createRule(char x[], char y[]);
int compareRule(const void* a, const void* b);
void printRule(void* a);
void deleteRule(void* a);
Rule* clone(Rule* data);
int compareRule2(Rule* a, char* b);
void printResponse(void* a);
void updateUserRate(void* a, double newUserRating);
void updateRule(void* a, char c);
Rule* createRule2(void* data);
#endif 










