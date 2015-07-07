class Solution:
    # @param a list of integers
    # @return an integer
    def removeDuplicates(self, A):
    	start = 0
    	end = 0
    	if len(A) <= 1:
    		return len(A)
    	while end+1 < len(A):
    		if A[start] == A[end+1]:
    			end+=1
    		else:
    			start+=1
    			end+=1
    			A[start],A[end] = A[end],A[start]
    	return start +1

s = Solution()
print s.removeDuplicates([1,1,2,3,3,3,4,4,5,5,5,5])
        	