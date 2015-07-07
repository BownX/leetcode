# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param two ListNodes
    # @return a ListNode
    def mergeTwoLists(self, l1, l2):
    	if l1 == None:
    		return l2
    	if l2 == None:
    		return l1
    	head = None
    	if l1.val < l2.val:
    		head = l1
    		l1 = l1.next
    	else:
    		head = l2
    		l2 = l2.next
    	p = head
    	while l1 != None and l2 != None:
    		if l1.val < l2.val:
    			p.next = l1
    			l1 = l1.next
    		else:
    			p.next = l2
    			l2 = l2.next
    		p = p.next
    	if l1 == None:
    		p.next = l2
    	elif l2 == None:
    		p.next = l1
    	return head

s = Solution()
node1 = ListNode(3)
node2 = ListNode(2)
node = s.mergeTwoLists(node1, node2)
while node != None:
	print node.val
	node = node.next