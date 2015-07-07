class Solution:
    # @param A, a list of integers
    # @param target, an integer to be inserted
    # @return integer
    def searchInsert(self, A, target):
    	if A == None:
    		return 0
    	for x in xrange(0,len(A)):
    		if target <= A[x]:
    			return x
    	return len(A)

s = Solution()
print s.searchInsert([1,3,5,6],0)