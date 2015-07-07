# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a boolean
    def hasCycle(self, head):
        p = head
        q = head
        while p != None and q != None and q.next != None:
        	p = p.next
        	q = q.next.next
        	if p == q:
        		return True

        return False

s = Solution()
print s.hasCycle(None)