class Solution:
    # @return an integer
    def trailingZeroes(self, n):
    	count = 0
        while n / 5 != 0:
        	n = n / 5
        	count = count + n
        return count

s = Solution()
print s.trailingZeroes(10)