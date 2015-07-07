# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of lists of integers
    def levelOrderBottom(self, root):
    	vals = []
    	self.visit(root,0,vals)
        return vals[::-1]

    def visit(self,root,layer,vals):
    	if root == None:
    		return
    	if len(vals) - 1 < layer:
    		vals.append([root.val])
    	else:
    		vals[layer].append(root.val)
    	self.visit(root.left,layer+1,vals)
    	self.visit(root.right,layer+1,vals)


s = Solution()
n3 = TreeNode(3)
n9 = TreeNode(9)
n20 = TreeNode(20)
n15 = TreeNode(15)
n7 = TreeNode(7)
n3.left = n9
n3.right = n20
n20.left = n15
n20.right = n7
print s.levelOrderBottom(n3)
