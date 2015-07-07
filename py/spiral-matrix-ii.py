class Solution:
    # @return a list of lists of integer
    def generateMatrix(self, n):
        result = [[0 for i in range(n)] for j in range(n)]
        direction = 1
        i = j = 0
        for x in xrange(1,n*n+1):
        	result[i][j] = x
        	if direction == 1:
        		if j+1<n and result[i][j+1] == 0:
	        		j += 1
	        		continue
	        	else:
	        		i += 1
	        		direction = 2
	        		continue
        	if direction == 2:
        		if i+1<n and result[i+1][j] == 0:
	        		i += 1
	        		continue
	        	else:
	        		j -= 1
	        		direction = 3
	        		continue
        	if direction == 3:
	        	if j>0 and result[i][j-1] == 0:
	        		j -= 1
	        		continue
	        	else:
	        		i -= 1
	        		direction = 4
	        		continue
        	if direction == 4:
	        	if i>0 and result[i-1][j] == 0:
	        		i -= 1
	        		continue
	        	else:
	        		j += 1
	        		direction = 1
	        		continue
	return result
	        		

s = Solution()
print s.generateMatrix(4)