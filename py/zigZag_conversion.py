class Solution:
    # @return a string
    def convert(self, s, nRows):
    	if nRows <= 1:
    		return s
        zegSize = nRows * 2 - 2
        result = ""
        for row in xrange(0,nRows):
        	print "***** ROW %d *****" % (row)
        	for n in xrange(0,len(s),zegSize):
        		left = n+row
        		right = n+zegSize-row
        		if left < len(s):
        			result = result + s[left]
        		if row != nRows - 1 and right < len(s) and right < n+zegSize:
        			result = result + s[right]
        return result

s = Solution()
print s.convert("ABCDEFGHIJ", 2)