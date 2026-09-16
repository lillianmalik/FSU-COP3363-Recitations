#include <iostream>
#include <string>
#include <cctype>   //  for character classification and manipulation
using namespace std;

/*
    This is what we call a global variable. (lineCount)
    When we have it flagged as "extern" it means we can use it
    outside of just our current file, inside those that
    have this directive (#include "header.hpp") included in 
    their header
*/
extern int lineCount;

void menu();

void insert_char(char arr[], int size, int spot, char chosenChar);
void leave_line(char arr[], int size, int spot);
void serve_line(char arr[], int size);

int spotInLine(char arr[], int size, char userEntry);

void printLine(char arr[], int size);