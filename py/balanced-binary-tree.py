# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return a boolean
    def isBalanced(self,root):
    	if root == None:
    		return True
    	if abs(self.depth(root.left, 1)-self.depth(root.right, 1)) > 1:
    		return False
    	return self.isBalanced(root.left) and self.isBalanced(root.right)

    def depth(self,root,layer):
    	if root == None:
    		return layer
    	return max(self.depth(root.left,layer+1), self.depth(root.right, layer+1))

s = Solution()
n1 = TreeNode(1)
n2 = TreeNode(2)
n3 = TreeNode(3)
n4 = TreeNode(4)
n5 = TreeNode(5)
n6 = TreeNode(6)
n7 = TreeNode(7)
n1.left = n2
n2.left = n3
n3.left = n4
n1.right = n5
n5.left = n6

print s.isBalanced(n1)
