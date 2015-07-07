class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
    	result = 0
        for a in A:
        	result ^= a
        return result

s = Solution()
print s.singleNumber([1,2,3,4,5,6,5,4,3,2,1,2,2,6,4])