class Solution:
    # @param digits, a list of integer digits
    # @return a list of integer digits
    def plusOne(self, digits):
    	if len(digits) == 0:
    		return [1]
    	digits[len(digits)-1] += 1
    	carry = 0
    	for x in xrange(len(digits)-1,-1,-1):
        	if digits[x] == 10:
        		digits[x] = 0
        		if x != 0:
        			digits[x-1] += 1
        		else:
        			carry = 1

        if carry == 1:
        	digits = [1] + digits
        return digits


s = Solution()
print s.plusOne([9,9,9,9,9,9,9])