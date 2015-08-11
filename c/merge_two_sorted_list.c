/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

https://leetcode.com/problems/merge-two-sorted-lists/
*/

#include "stdio.h"
#include "stdlib.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
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

int main(int argc, char const *argv[]) {
	struct ListNode* p1 = malloc(sizeof(struct ListNode));
	struct ListNode* p2 = malloc(sizeof(struct ListNode));
	struct ListNode* p3 = malloc(sizeof(struct ListNode));
	struct ListNode* p4 = malloc(sizeof(struct ListNode));
	struct ListNode* q1 = malloc(sizeof(struct ListNode));
	struct ListNode* q2 = malloc(sizeof(struct ListNode));
	struct ListNode* q3 = malloc(sizeof(struct ListNode));
	struct ListNode* q4 = malloc(sizeof(struct ListNode));
	p1->val = 1;
	p1->next = p2;
	p2->val = 4;
	p2->next = p3;
	p3->val = 8;
	p3->next = p4;
	p4-> val = 10;
	p4->next = NULL;
	q1->val = 2;
	q1->next = q2;
	q2->val = 6;
	q2->next = q3;
	q3->val = 7;
	q3->next = q4;
	q4-> val = 16;
	q4->next = NULL;
	p1 = mergeTwoLists(p1, q1);
	while (p1 != NULL) {
		printf("%d ", p1->val);
		p1 = p1->next;
	}
	return 0;
}