class Solution:
    # @param S, a list of integer
    # @return a list of lists of integer
    def subsets(self, S):
        l = 0
        S = sorted(S)
        for x in xrange(0,len(S)):
        	l <<= 1 
        	l |= 1
        result = []
        for l in xrange(0,l+1):
        	result.append(self.getSet(l,S))
        return result

    def getSet(self,l,S):
    	result = []
    	for i in xrange(0,len(S)):
    		if l & (1 << i) != 0:
    			result.append(S[i])
    	return result


s = Solution()
print s.subsets([4,1,0])