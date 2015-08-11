/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

static const char* letters[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

/*
recursive
*/
void combine(char* digits, int from, int to, char* result, char** combinations, int* index) {
    if (from <= to) {
        const char *letter = letters[digits[from] - '0'];
        for (int i = 0; i < strlen(letter); ++i) {
            result[from] = letter[i];
            combine(digits, from + 1, to, result, combinations, index);
        }
    } else {
        result[from] = '\0';
        combinations[*index] = malloc(sizeof(strlen(result)));
        strcpy(combinations[*index], result);
        (*index)++;
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    if (digits == NULL) {
        return NULL;
    }
    int digitsLength = strlen(digits);
    if (digitsLength == 0) {
        return NULL;
    }
    int returnStrLen = 0;
    *returnSize = 1;
    for (int i = 0; i < digitsLength; ++i) {
        int index = (int)(digits[i] - '0');
        if (index >= 2 && index <= 9) {
            *returnSize *= strlen(letters[index]);
            returnStrLen++;
        }
    }
    char** combinations = malloc(sizeof(char*) * (*returnSize));
    char* resultStr = malloc(sizeof(returnStrLen + 1));
    int* index = malloc(sizeof(int));
    *index = 0;
    combine(digits, 0, digitsLength - 1, resultStr, combinations, index);
    return combinations;
}

int main(int argc, char const *argv[]) {
    int *t = malloc(sizeof(int));
    char *str = "";
    char** result = letterCombinations(str, t);
    for (int i = 0; i < *t; ++i) {
        printf("%s\n", result[i]);
    }
    return 0;
}