# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param two ListNodes
    # @return the intersected ListNode
    def getIntersectionNode(self, headA, headB):
        p1 = headA
        p2 = headB
        p4 = None
        while p1 != None and p2 != None:
        	p1 = p1.next
        	p2 = p2.next
        if p1 == None:
        	p4 = headA
        	p3 = headB
        	while p2 != None:
        		p2 = p2.next
        		p3 = p3.next
        elif p2 == None:
        	p4 = headB
        	p3 = headA
        	while p! != None:
        		p1 = p1.next
        		p3 = p3.next
        while p3 != None and p4 != None:
        	if p3 == p4:
        		return p3
        	p3 = p3.next
        	p4 = p4.next
        return None