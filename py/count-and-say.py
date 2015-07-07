# -*- coding: utf-8 -*-

class Solution:

	def count(self, s):
		currentCh = ''
		currentCount = 0
		result = ""
		s = s + "#"
		for ch in s:
			if currentCh != ch:
				if currentCount != 0:
					result = result + str(currentCount) + str(currentCh)
				currentCount = 1
				currentCh = ch
			else:
				currentCount = currentCount + 1
		return result	

    # @return a string
	def countAndSay(self, n):
		if n == 1:
			return "1"
		elif n == 2:
			return "11"
		else:
			return self.count(self.countAndSay(n - 1))

s = Solution()
print s.countAndSay(6)