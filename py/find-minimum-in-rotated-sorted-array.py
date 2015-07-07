class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def findMin(self, nums):
        if nums == None or len(nums) == 0:
        	return None
        for x in xrange(0,len(nums)-1):
        	if nums[x+1] < nums[x]:
        		return nums[x+1]
        return nums[0]