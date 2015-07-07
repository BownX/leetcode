class Solution:
    # @param n, an integer
    # @return an integer
    def hammingWeight(self, n):
        count = 0
        while n != 0:
        	if n & 1 == 1:
        		count = count + 1
        	n = n >> 1
        return count


s = Solution()
print s.hammingWeight(2349)