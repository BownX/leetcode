# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def preorderTraversal(self, root):
        result = []
        if root != None:
       		self.visit(root,result)
       	return result

    def visit(self,node,vals):
    	if node != None:
    		vals.append(node.val)
    		self.visit(node.left,vals)
    		self.visit(node.right,vals)