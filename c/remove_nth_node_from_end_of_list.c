/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/

#include "stdio.h"
#include "stdlib.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int size = 0;
    struct ListNode* p = head;
    while (p != NULL) {
        size++;
        p = p->next;
    }
    if (size < n || n <= 0) return head;
    if (size == n) {
        p = head->next;
        free(head);
        return p;
    }
    p = head;
    size -= 1;
    struct ListNode* q = p->next;
    while (size - n > 0) {
        size--;
        p = p->next;
        q = p->next;
    }
    if (q != NULL) p->next = q->next;
    free(q);
    return head;
}


int main(int argc, char const *argv[]) {
    struct ListNode *p = malloc(sizeof(struct ListNode));
    p->val = 1;
    p->next = malloc(sizeof(struct ListNode));
    p->next->val = 2;
    p->next->next = malloc(sizeof(struct ListNode));
    p->next->next->val = 3;
    p->next->next->next = malloc(sizeof(struct ListNode));
    p->next->next->next->val = 4;
    p->next->next->next->next = malloc(sizeof(struct ListNode));
    p->next->next->next->next->val = 5;
    p->next->next->next->next->next = NULL;
    p = removeNthFromEnd(p, 2);
    while (p != NULL) {
        printf("%d\n", p->val);
        p = p->next;
    }
    return 0;
}