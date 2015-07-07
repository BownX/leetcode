class Solution:
    # @return a list of integers
    def getRow(self, rowIndex):
        top = [1]
        bottom = top
        while rowIndex >= 0:
        	bottom = [1]
        	for i in xrange(1,len(top)):
        		bottom.append(top[i-1] + top[i])
        	bottom.append(1)
        	top, bottom = bottom, top
        	rowIndex -= 1
        return bottom

s = Solution()
print s.getRow(3)
