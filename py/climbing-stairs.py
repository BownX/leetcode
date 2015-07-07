class Solution:
    # @param n, an integer
    # @return an integer
    def climbStairs(self, n):
        r = [None] * (n+1)
        r[0] = 1
        r[1] = 1
        for i in xrange(2, n+1):
        	r[i] = r[i-1]+r[i-2]
        return r[n]

s = Solution()
print s.climbStairs(3)