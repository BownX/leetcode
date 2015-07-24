/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

https://leetcode.com/problems/3sum/

Thanks to: https://leetcode.com/discuss/34216/share-my-23ms-c-solutions
*/

#include "stdio.h"
#include "stdlib.h"

static int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

/*
按顺序先固定第一个值，然后在剩下的部分中two pointer两端搜的方式寻找两点（事先sort一遍），注意跳过重复的情况
*/
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int **ret = NULL;
	int total = 64;
	int size = 0;
	int i,start,end;
	int sum;

	ret = (int **)malloc(sizeof(int *) * total);
	for(i = 0; i < total; ++i)
	    ret[i] = (int *)malloc(sizeof(int) * 3);

	qsort(nums,numsSize,sizeof(int),cmp);

	for(i = 0; i < numsSize-2; ++i){
	    if(i > 0 && nums[i] == nums[i-1])
	        continue;

	    start = i + 1;
	    end = numsSize - 1;
	    while(start < end){
	        sum = nums[i] + nums[start] + nums[end];
	        if(sum == 0){
	            if(size > 0 && ret[size-1][0] == nums[i] && 
	                ret[size-1][1] == nums[start] && ret[size-1][2] == nums[end]){
	                ++start;
	                --end;
	                // skip duplication.
	                continue;
	            }
	            ret[size][0] = nums[i];
	            ret[size][1] = nums[start];
	            ret[size][2] = nums[end];
	            size++;

	            if(size == total){
	                total <<= 1;
	                int t;
	                ret = (int **)realloc(ret,sizeof(int *) * total);
	                for(t = size; t < total; ++t)
	                    ret[t] = (int *)malloc(sizeof(int) * 3);
	            }
	            ++start;
	            --end;
	        } else if(sum > 0){
	        	// 由于qsort后是升序，sum>0的时候是第三个数大了点，需要第三个数小点，end往前
	            --end;
	        }else{
	        	// 同理sum<0的时候第二个数小了点，需要start往后
	            ++start;
        	}
    	}
	}

	*returnSize = size;
	return ret;
}

int main(int argc, char const *argv[]) {
	int nums[7] = {1,2,0,-1,-2,4,-2};
	int *returenSize = malloc(sizeof(int));
	int **result = threeSum(nums, 7, returenSize);
	for (int i = 0; i < *returenSize; ++i) {
		printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
	}
	return 0;
}