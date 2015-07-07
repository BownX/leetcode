class Solution:
    # @param num, a list of integers
    # @return an integer
    def majorityElement(self, num):
        num = sorted(num)
        return num[len(num)/2]


s = Solution()
print s.majorityElement([4,5,4])