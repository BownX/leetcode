class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        m = {}
        index1 = 0
        index2 = 0
        for i in xrange(0,len(num)):
        	if num[i] in m:
        		index1 = i + 1
        		index2 = m[num[i]] + 1
        	m[target - num[i]] = i
        if index1 > index2:
        	return (index2, index1)
        else:
        	return (index1, index2)


s = Solution()
print s.twoSum([-1,-2,-3,-4,-5], -8)