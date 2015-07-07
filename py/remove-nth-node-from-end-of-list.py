# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @return a ListNode
    def removeNthFromEnd(self, head, n):
    	if head == None or head.next == None:
    		return None
        p1 = head
        p2 = head
        while n >= 0 and p2 != None:
            p2 = p2.next
            n = n - 1
        if n >= 0:
        	return head.next
        while p1 != None and p2 != None:
        	p1 = p1.next
        	p2 = p2.next
        if p1 != None and p1.next != None:
        	p1.next = p1.next.next
        return head