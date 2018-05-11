#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "Rule.h"
#include "ctype.h"

Rule* createRule(char x[], char y[])
{
     Rule* newRule = (Rule*)malloc(sizeof(Rule)); 
     newRule->keyWord = (char*)malloc(sizeof(char)*strlen(x));
     newRule->response = (char*)malloc(sizeof(char)*strlen(y));
     strcpy(newRule->keyWord, x);
     strcpy(newRule->response, y);
     newRule->userRating = 0.5;
     newRule->systemRating = 0.5;
     newRule->learningRate = 0.05;
     newRule->timesUsed = 0;
     return newRule;
}

Rule* createRule2(void* data)
{
    Rule* rule2 = (Rule*)malloc(sizeof(Rule));
    Rule* temp = (Rule*)data;
    rule2->keyWord = (char*)malloc(sizeof(char)*strlen(temp->keyWord));
    rule2->response = (char*)malloc(sizeof(char)*strlen(temp->response));
    rule2->systemRating = temp->systemRating + temp->userRating;
    strcpy(rule2->keyWord, temp->keyWord);
    strcpy(rule2->response, temp->response);
    return rule2;
}
int compareRule(const void* a, const void* b)
{
    Rule* temp1 = (Rule*)a;
    Rule* temp2  = (Rule*)b;
    int i = 0;
    for(i = 0; i < strlen(temp1->keyWord); i++){
	temp1->keyWord[i] = tolower(temp1->keyWord[i]);
    }
    for(i = 0; i < strlen(temp2->keyWord); i++){
	temp2->keyWord[i] = tolower(temp2->keyWord[i]);
    }
    if(strcmp(temp1->keyWord, temp2->keyWord)>0){
	return 1;
    }
    else if(strcmp(temp1->keyWord, temp2->keyWord) < 0){
	return -1;
    }
    else {
	return 0;
    }
}

int compareRule2(Rule* a, char* b)
{
    Rule* temp1 = a;
    char* temp2 = b;
    int i = 0;
    for(i = 0; i < strlen(temp1->keyWord); i++){
	temp1->keyWord[i] = tolower(temp1->keyWord[i]);
    }
    for(i = 0; i < strlen(temp2); i++){
	temp2[i] = tolower(temp2[i]);
    }
    if(strcmp(temp1->keyWord, temp2)>0){
	return 1;
    }
    else if(strcmp(temp1->keyWord, temp2) < 0){
	return -1;
    }
    else {
	return 0;
    }
}

void printRule(void* a)
{
    Rule* temp = (Rule*)a;
    printf("%s Rating:<%.2f> System:<%.2f> Occurrences:<%d>\n", temp->keyWord, temp->userRating, temp->systemRating, temp->timesUsed);
}

Rule* clone(Rule* data)
{
    Rule* theClone = (Rule*)malloc(sizeof(Rule));
    theClone->keyWord = (char*)malloc(sizeof(char)*strlen(data->keyWord));
    theClone->response = (char*)malloc(sizeof(char)*strlen(data->keyWord));
    strcpy(theClone->keyWord, data->keyWord);
    strcpy(theClone->response, data->response);
    theClone->userRating = data->userRating;
    theClone->learningRate = data->learningRate;
    theClone->systemRating = data->systemRating;
    theClone->timesUsed = data->timesUsed;
    return theClone;
}

void printResponse(void* a)
{
    Rule* temp = (Rule*)a;
    printf("%s\n", temp->response);
}

void deleteRule(void* a)
{
    free(a);
    a = NULL;
}

void updateRule(void* a, char c)
{
    Rule* temp = (void*)a;
    temp->timesUsed = temp->timesUsed + 1;
    double updateSystem = ((temp->systemRating)*(temp->learningRate))/temp->timesUsed;
    if(c == 'y' || c == 'Y'){
	temp->systemRating = temp->systemRating + updateSystem;
    }   
    else {
	temp->systemRating = temp->systemRating - updateSystem;
    }
}

void updateUserRate(void* a, double newUserRating)
{
    Rule* temp = (void*)a;
    temp->userRating = newUserRating;
    printf("%.2lf", temp->userRating);
}
