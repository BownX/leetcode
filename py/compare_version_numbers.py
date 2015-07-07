class Solution:
    # @param version1, a string
    # @param version2, a string
    # @return an integer
    def compareVersion(self, version1, version2):
        l1 = version1.split('.')
        l2 = version2.split('.')
        size = min(len(l1),len(l2))
        for x in xrange(0, size):
        	if int(l1[x]) > int(l2[x]):
        		return 1
        	elif int(l1[x]) < int(l2[x]):
        		return -1
        longer = None
        result = 0
        if len(l1) > len(l2):
        	longer = l1
        	result = 1
        elif len(l1) < len(l2):
        	longer = l2
        	result = -1
        else:
        	return 0
        tailCount = 0
        for x in xrange(size,len(longer)):
        	tailCount = tailCount + int(longer[x])
        if tailCount == 0:
        	return 0
        else:
        	return result

s = Solution()
print s.compareVersion("1.0", "1")