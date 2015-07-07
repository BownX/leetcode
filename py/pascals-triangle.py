# -*- coding: utf-8 -*-

class Solution:
    # @return a list of lists of integers
    def generate(self, numRows):
    	if numRows == 0:
    		return []
        result = [[1]]
        for x in xrange(1,numRows):
        	row = []
        	lastRow = result[x-1]
        	row.append(lastRow[0])
        	for y in xrange(1,len(lastRow)):
        		row.append(lastRow[y-1]+lastRow[y])
        	row.append(lastRow[-1])
        	result.append(row)
        return result

solution = Solution()
print solution.generate(5)