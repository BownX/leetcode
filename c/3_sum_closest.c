/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

https://leetcode.com/problems/3sum-closest/
*/

#include "stdio.h"
#include "stdlib.h"

static int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int abs(int n) {
	return n < 0 ? -n : n;
}

// 解法和3 sum类似，只不过目标变成了找最小diff
int threeSumClosest(int* nums, int numsSize, int target) {
	if (nums == NULL || numsSize < 3) {
		return target;
	}
	qsort(nums, numsSize, sizeof(int), cmp);
	int diff = (~(unsigned)0) >> 1; // MAX
	int min = 0;
	for (int i = 0; i < numsSize - 2; ++i) {
		int start = i + 1;
		int end = numsSize - 1;
		while (start < end) {
			int sum = nums[i] + nums[start] + nums[end];
			if (abs(sum - target) <= diff) {
				diff = abs(sum - target);
				min = sum;
			}
			if (sum > target) {
				end--;
			} else {
				start++;
			}
		}
	}
	return min;
}

int main(int argc, char const *argv[]) {
	int nums[4] = { -1, 2, 1, -4};
	printf("%d\n", threeSumClosest(nums, 4, 1));
	return 0;
}