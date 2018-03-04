/*
Kirubel Worede
HW #1
02/22/2016

strings.c
USAGE: ./strings '[STRING]'
This program allows a user to pass in a string and carry out different
operations on the passed string. The first operation allows the user to
clean the string of any non-alphabet characters. The second operation
allows the user to lower case the string. The third operation sorts the
character in alphabetical order.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare function prototypes
void strlower(char* str);
void strclean(char* str);
void strsort(char* str);

int main(int argc, char *argv[]) {
    int k;  // Counter for function pointer iteration.
    // Function pointers declaration.
    void (*functionpointer[3])(char*);
    functionpointer[1] = &strlower;
    functionpointer[0] = &strclean;
    functionpointer[2] = &strsort;
    // Iteration for the three functions
    for (k = 0; k < 3; k++) {
        functionpointer[k](argv[1]);
        printf("%s\n", argv[1]);
    }
    return 0;
}

/*
void strlower
Takes some input string and sets all capital letters to lowercase ones.
*/
void strlower(char* str) {
    int i;
    int k = 97;
    for (i = 0; i < strlen(str); i++) {
        if ((str[i] - k) < 0) {
            str[i] = str[i] + 32;
        }
    }
}
/*
void strclean
Takes some input string and removes all
non-alphabetic characters from the string.
*/
void strclean(char* str) {
    int i;
    char st[256];
    strcpy(st, str);
    int k = 0;
    for (i = 0; i < strlen(st); i++) {
        // Checks if character is within the ASCII range of alphabet
        if ((st[i] >= 65 && st[i] <=90) || (st[i] >= 97 && st[i] <=122)) {
            str[k] = st[i];
            k++;
        }
        str[k] = 0;
    }
}
/*
void strsort
Takes some input string and sorts the characters of
a string from lowest to highest (a = low, z = high).
*/
void strsort(char* str) {
    char st[256];
    strcpy(st, str);
    char c;
    int y;
    int z;
    for (y = 0; y < (strlen(str)); y++) {
        for (z = y; z < (strlen(str)); z++) {
            if (str[z] < str[y]) {  // Bubble sorting, grabbing the
                // first character
                // and compares it with every character
                // within the given string
                c = str[z];  // swaping the character position.
                str[z] = str[y];
                str[y] = c;
            }
        }
    }
}
