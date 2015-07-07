class Solution:
    # @return a string
    def convertToTitle(self, num):
		s = ""
		while num != 0:
			# 注意这个-1即可，将1~26转化为0~25
			num = num - 1
			s = s + chr(ord('A') + num % 26)
			num = num / 26
		return s[::-1]

s = Solution()
print s.convertToTitle(26)