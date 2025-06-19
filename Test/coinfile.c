// coinfile.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "coinfile.h"

// Helper: Checks if string is a valid name (non-empty, no spaces)
// (Here, since fscanf with %s reads until whitespace, no spaces expected)
int IsValidName(const char* name) {
    return (name != NULL && strlen(name) > 0);
}

// Helper: Checks if amount is in [1, 95]
int IsValidAmount(int amount) {
    return (amount >= 1 && amount <= 95);
}

// Helper: Checks if currency is exactly 3 letters (case insensitive)
int IsValidCurrency(const char* currency) {
    if (strlen(currency) != 3)
        return 0;
    
    // Allow 3 letters (EUR)
    int allLetters = 1;
    for (int i = 0; i < 3; i++) {
        if (!isalpha(currency[i])) {
            allLetters = 0;
            break;
        }
    }
    if (allLetters) return 1;
    
    // Allow 2 letters + $ (AU$, US$)
    if (isalpha(currency[0]) && isalpha(currency[1]) && currency[2] == '$') {
        return 1;
    }
    
    return 0;
}

int ValidateFile(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return -1;
    }

    char name[128];
    int amount;
    char currency[10];
    int lineNum = 0;
    int valid = 1;

    while (1) {
        lineNum++;
        int ret = fscanf(file, "%127s %d %9s", name, &amount, currency);
        if (ret == EOF) break;

        if (ret != 3) {
            printf("Error on line %d: Line does not contain name, amount, and currency.\n", lineNum);
            valid = 0;
            break;
        }

        if (!IsValidName(name)) {
            printf("Error on line %d: Invalid name.\n", lineNum);
            valid = 0;
        }
        if (!IsValidAmount(amount)) {
            printf("Error on line %d: Amount %d is out of valid range (1-95).\n", lineNum, amount);
            valid = 0;
        }
        if (!IsValidCurrency(currency)) {
            printf("Error on line %d: Currency \"%s\" is invalid. Must be exactly 3 characters.\n", lineNum, currency);
            valid = 0;
        }
    }

    fclose(file);
    return valid;
}