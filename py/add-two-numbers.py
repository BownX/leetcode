# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @return a ListNode
    def addTwoNumbers(self, l1, l2):
        if l1 == None:
        	return l2
        if l2 == None:
        	return l1
        p = l1
        q = l2
        head = p
        carry = 0
        while True:
        	val = p.val + q.val + carry
        	if val >= 10:
        		carry = 1
        		val -= 10
        	else:
        		carry = 0
        	p.val = val
        	if p.next == None or q.next == None:
        		break
        	p = p.next
        	q = q.next
        if p.next == None:
        	p.next = q.next
        while p.next != None:
        	p = p.next
        	val = p.val + carry
        	if val >= 10:
        		carry = 1
        		val -= 10
        	else:
        		carry = 0
        	p.val = val
        if carry == 1:
        	p.next = ListNode(1)
        return head

    def reverse(self,head):
    	p = head
    	q = p.next
    	while q != None:
    		n = q.next
    		q.next = p
    		p = q
    		q = n
    		if q == None:
    			head.next = None
    			return p
    	return head

s = Solution()
n1 = ListNode(2)
n2 = ListNode(4)
n3 = ListNode(3)

n4 = ListNode(5)
n5 = ListNode(6)
n6 = ListNode(4)

n1.next = n2
n2.next = n3

n4.next = n5
n5.next = n6

p = s.addTwoNumbers(n1, n4)
while p != None:
	print p.val
	p = p.next