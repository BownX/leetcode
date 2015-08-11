/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

https://leetcode.com/problems/integer-to-roman/
*/

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

char* intToRoman(int num) {
	if (num <= 0 || num >= 4000) {
		return NULL;
	}
	char *TENS[4] = {"I", "X", "C", "M"};
	char *FIVES[3] = {"V", "L", "D"};
	char* result = malloc(sizeof(char) * 20);
	int current_digits = 0;
	if (num >= 10) current_digits = 1;
	if (num >= 100) current_digits = 2;
	if (num >= 1000) current_digits = 3;
	while (num != 0) {
		int number = num / pow(10, current_digits);
		if (number == 9) {
			strcat(result, TENS[current_digits]);
			strcat(result, TENS[current_digits + 1]);
		} else if (number >= 5) {
			strcat(result, FIVES[current_digits]);
			for (int i = 0; i < number - 5; ++i) strcat(result, TENS[current_digits]);
		} else if (number > 0) {
			strcat(result, TENS[current_digits]);
			if (number == 4) {
				strcat(result, FIVES[current_digits]);
			} else {
				for (int i = 1; i < (3 < number ? 3 : number); ++i) strcat(result, TENS[current_digits]);
			}
		}
		num -= pow(10, current_digits) * number;
		current_digits -= 1;
	}
	return result;
}

int main(int argc, char const *argv[]) {
	while (1) {
		int digit;
		scanf("%d", &digit);
		printf("%s\n", intToRoman(digit));
	}
	return 0;
}