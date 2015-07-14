/*
Reverse digits of an integer.
Example1: x = 123, return 321
Example2: x = -123, return -321

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

https://leetcode.com/problems/reverse-integer/
*/

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

int reverse(int x) {
	int MAX = (~(unsigned)0) >> 1;
	int MIN = -(int)((~(unsigned)0) >> 1) - 1;
	int result = 0;
	while(x != 0) {
		// 在值*10之前预先一步判断是否overflow (虽然ac了但是严格来说判断不严谨，后面atoi那题更严谨一些)
		if ((result > 0 && result > MAX / 10) || (result < 0 && result < MIN / 10)) {
			// overflow
			return 0;
		}
		result = result * 10;
		result += x % 10;
		x = x / 10;
	}
	return result;
}

int main(int argc, char const *argv[]) {
	printf("%d\n", reverse(-1000000003));
	return 0;
}