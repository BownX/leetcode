/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

https://leetcode.com/problems/generate-parentheses/
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void generate(int left, int right, int currentLen, char* str, char*** result, int* resultCount, int* resultCapacity) {
	if (right < left) {
		return;
	}
	if (left == 0 && right == 0) {
		char* temp = malloc(sizeof(char) * (currentLen + 1));
		temp = strcpy(temp, str);
		(*result)[*resultCount] = temp;
		(*resultCount)++;
	}
	if (*resultCount >= *resultCapacity) {
		*resultCapacity = (*resultCapacity) * 2;
		// NOTICE: 注意realloc扩容需要三级指针才能来引用修改原二级指针char** result
		char** temp = realloc(*result, sizeof(char*) * (*resultCapacity));
		*result = temp;
	}
	if (left > 0)  {
		str[currentLen] = '(';
		str[currentLen + 1] = '\0';
		generate(left - 1, right, currentLen + 1, str, result, resultCount, resultCapacity);
	}
	if (right > 0) {
		str[currentLen] = ')';
		str[currentLen + 1] = '\0';
		generate(left, right - 1, currentLen + 1, str, result, resultCount, resultCapacity);
	}
}

char** generateParenthesis(int n, int* returnSize) {
	if (n < 1) {
		return NULL;
	}
    int* resultCount = malloc(sizeof(int));
    int* resultCapacity = malloc(sizeof(int));
    (*resultCount) = 0;
    (*resultCapacity) = n;
    char** result = malloc(sizeof(char*) * (*resultCapacity));
    char* str = malloc(sizeof(char) * (n * 2 + 1));
    generate(n, n, 0, str, &result, resultCount, resultCapacity);
    *returnSize = *resultCount;
    return result;
}

int main(int argc, char const *argv[]) {
	int* returnSize = malloc(sizeof(int));
	char** result = generateParenthesis(10, returnSize);
	for (int i = 0; i < *returnSize; ++i) {
		printf("%s\n", result[i]);
	}
	return 0;
}