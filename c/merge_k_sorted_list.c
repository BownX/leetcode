/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

https://leetcode.com/problems/merge-k-sorted-lists/
*/

#include "stdio.h"
#include "stdlib.h"

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* merge2List(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* head = NULL;
	struct ListNode* tail = NULL;
	struct ListNode* p = NULL;
	if (l1 == NULL && l2 == NULL) {
		return NULL;
	}
	while (l1 != NULL && l2 != NULL) {
		if (l1->val <= l2->val) {
			p = l1;
			l1 = l1->next;
		} else {
			p = l2;
			l2 = l2->next;
		}
		if (head == NULL) {
			head = p;
			tail = p;
		} else {
			tail->next = p;
			tail = p;
		}
	}
	if (l1 == NULL) {
		p = l2;
	} else {
		p = l1;
	}
	if (head == NULL) {
		head = p;
	} else {
		tail->next = p;
	}
	return head;
}

struct ListNode* merge(struct ListNode** lists, int from, int to) {
	if (from == to) {
		return lists[from];
	} else if (to == from + 1) {
		return merge2List(lists[from], lists[to]);
	} else {
		int mid = (from + to) / 2;
		return merge2List(merge(lists, from, mid), merge(lists, mid + 1, to));
	}
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 // 使用分治策略和之前的合并2个list
 // TODO: using Maximum Heap
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
	if (lists == NULL || listsSize <= 0) {
		return NULL;
	}
	return merge(lists, 0, listsSize - 1);
}

int main(int argc, char const *argv[]) {

	return 0;
}