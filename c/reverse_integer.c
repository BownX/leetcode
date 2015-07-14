#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

int reverse(int x) {
	int MAX = (~(unsigned)0) >> 1;
	int MIN = -(int)((~(unsigned)0) >> 1) - 1;
	int result = 0;
	while(x != 0) {
		// 在值*10之前预先一步判断是否overflow
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