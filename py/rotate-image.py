class Solution:
    # @param matrix, a list of lists of integers
    # @return nothing (void), do not return anything, modify matrix in-place instead.
    def rotate(self, matrix):
        n = len(matrix)
        for i in xrange(0,n):
        	for j in xrange(0,i):
        		matrix[i][j],matrix[j][i] = matrix[j][i],matrix[i][j]

        for i in xrange(0,n):
        	for j in xrange(0,n/2):
        		matrix[i][j],matrix[i][n-j-1] = matrix[i][n-j-1],matrix[i][j]

m = [[1,2,3],[4,5,6],[7,8,9]]

print m
s = Solution()
s.rotate(m)
print m