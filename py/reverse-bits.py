class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
    	r = 0
        for i in xrange(0,32):
        	val = n & 1
        	n >>= 1
        	r <<= 1
        	r |= val
        return r

s = Solution()
print s.reverseBits(43261596)