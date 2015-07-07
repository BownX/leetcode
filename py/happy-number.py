class Solution:
    # @param {integer} n
    # @return {boolean}
    def isHappy(self, n):
        saved = []
        while True:
        	n = self.cal(n)
        	print n
        	if n == 1:
        		return True
        	elif n in saved:
        		return False
        	saved.append(n)

    def cal(self,n):
    	result = 0
    	while n != 0:
    		result += (n % 10)**2
    		n /= 10
    	return result

s = Solution()
print s.isHappy(89)