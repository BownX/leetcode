/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

https://leetcode.com/problems/4sum/
*/

#include "stdio.h"
#include "stdlib.h"

static int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

/**
 * 解法同 3 sum，只是又多了一层。。 
 * 
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    if (nums == NULL || numsSize < 4) {
    	return NULL;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int resultSize = 0;
    int resultCapacity = numsSize;
    int **result = malloc(sizeof(int *) * resultCapacity);
    for (int i = 0; i < numsSize - 3; ++i) {
    	for (int j = i + 1; j < numsSize - 2; ++j) {
    		int start = j + 1;
    		int end = numsSize - 1;
    		while (start < end) {
    			int sum = nums[i] + nums[j] + nums[start] + nums[end];
    			if (sum == target) {
                    // skip duplication
                    int duplicate = 0;
                    for (int k = 0; k < resultSize; ++k) {
                        if (result[k][0] == nums[i] &&
                            result[k][1] == nums[j] &&
                            result[k][2] == nums[start] &&
                            result[k][3] == nums[end]) {
                            duplicate = 1;
                            break;
                        }
                    }
                    if (duplicate) {
                        start++;
                        end--;
                        continue;
                    }
                    result[resultSize] = malloc(sizeof(int) * 4);
                    result[resultSize][0] = nums[i];
                    result[resultSize][1] = nums[j];
                    result[resultSize][2] = nums[start];
                    result[resultSize][3] = nums[end];
    				resultSize++;
                    // extend result array.
                    if (resultSize == resultCapacity) {
                        resultCapacity += resultSize;
                        result = realloc(result, sizeof(int *) * resultCapacity);
                    }
    				start++;
    				end--;
    			} else if (sum < target) {
    				start++;
    			} else {
    				end--;
    			}
    		}
    	}
    }
    *returnSize = resultSize;
    return result;
}

int main(int argc, char const *argv[]) {
	int nums[] = {-9,4,0,-3,6,3,-3,-9,-7,1,0,-7,-8,7,1};
	int *size = malloc(sizeof(int));
	int **result = fourSum(nums, 15, -9, size);
	for (int i = 0; i < (*size); ++i) {
		printf("result[%d] = {%d %d %d %d}\n", i, result[i][0], result[i][1], result[i][2], result[i][3]);
	}
	return 0;
}