class Solution:
    # @param A  a list of integers
    # @param m  an integer, length of A
    # @param B  a list of integers
    # @param n  an integer, length of B
    # @return nothing(void)
    def merge(self, A, m, B, n):
        ia = 0
        ib = 0
        while ia < m:
        	if A[ia] <= B[0]:
        		ia += 1
        	else:
        		ib = 0
        		A[ia],B[ib] = B[ib],A[ia]
        		while ib+1 < n and B[ib] > B[ib+1]:
        			B[ib],B[ib+1] = B[ib+1],B[ib]
        			ib+=1
        	print A
        	print B
        	print "* * * * *"
        ia = m
        for index in xrange(0,n):
        	A[ia] = B[index]
        	ia+=1
        print A
        print B

s = Solution()
s.merge([4,5,6,None,None,None,None,None,None,None],3,[1,2,3],3)
        		