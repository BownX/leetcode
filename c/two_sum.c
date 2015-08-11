/*
Given an array of integers, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution.
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

https://leetcode.com/problems/two-sum/
*/

#include "stdio.h"
#include "stdlib.h"

// Brute Force Solution (Time Limit Exceeded (when numsSize=16000))
int* twoSum_bruteforce(int* nums, int numsSize, int target) {
	for (int i = 0; i < numsSize; ++i) {
		for (int j = i; j < numsSize; ++j) {
			if (nums[i] + nums[j] == target) {
				int* result = malloc(sizeof(int) * 2);
				result[0] = i + 1;
				result[1] = j + 1;
				return result;
			}
		}
	}
	return NULL;
}

// HASH Solution(4ms)
typedef struct Node {
	int key;
	int value;
	struct Node* next;
} Node;

void insert(Node** table, int size, int key, int value) {
	int hash = abs(key) % size;
	Node* node = malloc(sizeof(Node));
	node->key = key;
	node->value = value;
	node->next = NULL;
	if (table[hash] == NULL) {
		table[hash] = node;
	} else {
		Node* p = table[hash];
		while (p->next != NULL) p = p->next;
		p->next = node;
	}
}

Node* get(Node** table, int size, int key, int ignoreValue) {
	int hash = abs(key) % size;
	Node* p = table[hash];
	if (p != NULL) {
		while (p != NULL) {
			// ignoreValue to solve two-same-key case.
			if (p->key == key && p->value != ignoreValue) {
				return p;
			}
			p = p->next;
		}
	}
	return NULL;
}

int* twoSum(int* nums, int numsSize, int target) {
	// build hash table.
	Node** table = malloc(sizeof(Node*) * numsSize);
	for (int i = 0; i < numsSize; table[i++] = NULL);
	for (int i = 0; i < numsSize; ++i) {
		insert(table, numsSize, nums[i], i);
	}
	// two sum.
	for (int i = 0; i < numsSize; ++i) {
		int targetKey = target - nums[i];
		Node* node = get(table, numsSize, targetKey, targetKey == nums[i] ? i : -1);
		if (node != NULL) {
			int* result = malloc(sizeof(int) * 2);
			result[0] = i + 1;
			result[1] = node->value + 1;
			free(table);
			return result;
		}
	}
	free(table);
	return NULL;
}

int main(int argc, char const *argv[]) {
	// test.
	int input[] = {2, 1, 9, 4, 4, 56, 90, 3};
	int* result = twoSum(input, 8, 8);
	printf("%d %d\n", result[0], result[1]);
	return 0;
}