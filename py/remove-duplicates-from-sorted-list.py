# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def deleteDuplicates(self, head):
        if head == None:
        	return head
        p = head
        while p != None:
        	if p.next != None:
        		if p.next.val != p.val:
        			p = p.next
        		else:
        			p.next = p.next.next
        	else:
        		break
        return head

n1 = ListNode(1)
n2 = ListNode(2)
n3 = ListNode(2)
n4 = ListNode(2)
n5 = ListNode(2)
n6 = ListNode(2)
n1.next = n2
n2.next = n3
n3.next = n4
n4.next = n5
n5.next = n6

s = Solution()
head = s.deleteDuplicates(n1)

p = head
while p != None:
	print p.val
	p = p.next