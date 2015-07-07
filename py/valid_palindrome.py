class Solution:
    # @param s, a string
    # @return a boolean
    def isPalindrome(self, s):
        if s == "":
        	return True
        s = s.lower()
        convert = ''.join([c for c in s if (c >= 'a' and c <= 'z') or (c >= '0' and c <= '9')])
        return convert == convert[::-1]


s = Solution()
print s.isPalindrome("1a2")
