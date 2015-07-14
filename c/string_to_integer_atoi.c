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