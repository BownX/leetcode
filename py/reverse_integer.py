class Solution:
    # @return an integer
    def reverse(self, x):
    	try:
    		if x > 0:
	        	return int(str(x)[::-1])
	        elif x < 0:
	        	return int(str(-x)[::-1])*(-1)
	        else:
	        	return 0
    	except Exception, e:
    		return 0

s = Solution()
print s.reverse(1000000003)