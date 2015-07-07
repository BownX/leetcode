class Solution:
    # @param a, a string
    # @param b, a string
    # @return a string
    def addBinary(self, a, b):
    	if len(a) > len(b):
    		b = '0' * (len(a) - len(b)) + b
    	elif len(a) < len(b):
    		a = '0' * (len(b) - len(a)) + a
        size = min(len(a),len(b))
        result = ""
        carry = 0
        ra = a[::-1]
        rb = b[::-1]
        for x in xrange(0,size):
        	v = carry
        	if ra[x] == '1':
        		v += 1
        	if rb[x] == '1':
        		v += 1
        	if v == 0:
        		result = '0' + result
        		carry = 0
        	elif v == 1:
        		result = '1' + result
        		carry = 0
        	elif v == 2:
        		result = '0' + result
        		carry = 1
        	elif v == 3:
        		result = '1' + result
        		carry = 1
        if carry == 1:
        	result = '1' + result
       	return result


s = Solution()
print s.addBinary("11","11")
