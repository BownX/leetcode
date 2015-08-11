/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

https://leetcode.com/problems/add-two-numbers/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include "stdio.h"
#include "stdlib.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode* p = l1;
    struct ListNode* q = l2;
    if (p == NULL) return q;
    if (q == NULL) return p;
    while (1) {
        int num = p->val + (q != NULL ? q->val : 0) + carry;
        if (num >= 10) {
            num -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        p->val = num;
        if (p->next == NULL) {
            if (q != NULL && q->next != NULL) {
                p->next = q->next;
                q = NULL;
            } else {
                break;
            }
        }
        p = p->next;
        q = q != NULL ? q->next : NULL;
    }
    if (carry != 0) {
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = carry;
        node->next = NULL;
        p->next = node;
    }
    return l1;
}

int main() {
    // test
    struct ListNode* l1 = malloc(sizeof(struct ListNode));
    struct ListNode* l2 = malloc(sizeof(struct ListNode));
    struct ListNode* l3 = malloc(sizeof(struct ListNode));
    struct ListNode* l4 = malloc(sizeof(struct ListNode));
    struct ListNode* l5 = malloc(sizeof(struct ListNode));
    struct ListNode* l6 = malloc(sizeof(struct ListNode));
    l1->val = 2;
    l1->next = l2;
    l2->val = 4;
    l2->next = l3;
    l3->val = 3;
    l3->next = NULL;

    l4->val = 5;
    l4->next = l5;
    l5->val = 2;
    l5->next = l6;
    l6->val = 4;
    l6->next = NULL;

    struct ListNode* result = addTwoNumbers(l3, l4);
    while (result != NULL) {
        printf("%d ", result->val);
        result = result->next;
    }
    return 0;
}