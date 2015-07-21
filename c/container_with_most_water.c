/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

https://leetcode.com/problems/container-with-most-water/
*/

#include "stdio.h"
#include "stdlib.h"

/*
等价于 给出a[1~n], f(i, j) = |j - i| * min(a[i], a[j]), 1 <= i <= n, 1 <= j <= n, 求 fmax

从两端开始找，这时width最大，逐渐缩小width且找到更高的height
*/
int maxArea(int* height, int heightSize) {
	int i = 0 ;
	int j = heightSize - 1;
	int max = 0;
	while(i < j) {
		int h = (height[i] < height[j] ? height[i] : height[j]);
		int vol = (j - i) * h;
		max = vol > max ? vol : max;
		while(height[i] <= h) i++;
		while(height[j] <= h) j--;
	}
	return max;
}

int main(int argc, char const *argv[]) {
	int height[2] = {2, 1};
	printf("%d\n", maxArea(height, 2));
	return 0;
}