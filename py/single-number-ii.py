class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        one = two = three = 0
        for x in xrange(0,len(A)):
        	two |= one&A[x]
        	one^=A[x]
        	three=one&two
        	one&=~three
        	two&=~three
        return one

s = Solution()
print s.singleNumber([1,1,1,2,2,2,3,3,3,5,5])