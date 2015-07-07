class Solution:
    # @param s, a string
    # @return an integer
    def titleToNumber(self, s):
        count = 0
        for c in s:
        	count = count * 26 + ord(c) - ord('A') + 1
        return int(count)


s = Solution()
print s.titleToNumber('AB')