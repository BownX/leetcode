/*
Implement atoi to convert a string to an integer.
Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
spoilers alert... click to show requirements for atoi.
Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

https://leetcode.com/problems/string-to-integer-atoi/
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*
总体思想就是考虑各种边界条件
*/
int myAtoi(char* str) {
	if (str == NULL) {
		return 0;
	}
	int MAX = (~(unsigned)0) >> 1;
	int MIN = -(int)((~(unsigned)0) >> 1) - 1;
	int len = strlen(str);
	int result = 0;
	int i = 0;
	int symbol = 1;
	int canIgnore = 0;
	// skip  space
	while(str[i] == ' ') i++;
	// check symbol
	if (str[i] == '+') {
		i++;
		symbol = 1;
	} else if (str[i] == '-') {
		i++;
		symbol = -1;
	}
	// calc digit
	for (; i < len; ++i) {
		char ch = str[i];
		if (ch < '0' || ch > '9')  {
			canIgnore = 1;
		}
		// skip remaining
		if (!canIgnore) {
			int add = (result < 0 ? -1 : 1) * (ch - '0');
			if (result > MAX / 10 || (result == MAX / 10 && add >= MAX % 10)) {
				// overflow 
				return MAX;
			}
			if (result < MIN / 10 || (result == MIN / 10 && add <= MIN % 10)) {
				// overflow
				return MIN;
			}
			result = result * 10;
			result = result + add;
			if (result != 0) {
				result *= symbol;
				symbol = 1;
			}
		}
	}
	return result;
}

int main(int argc, char const *argv[]) {
	printf("%d\n", myAtoi("2147483649"));
	return 0;
}