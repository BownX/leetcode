class Solution:
    # @return a boolean
    def isValid(self, s):
        stack = []
        for ch in s:
        	if ch in ['(', '[', '{']:
        		stack.insert(0, ch)
        	elif ch in [')', ']', '}']:
        		if len(stack) == 0:
        			return False
        		if ch == ')':
        			if stack[0] == '(':
        				del stack[0]
        			else:
        				return False
        		elif ch == ']':
        			if stack[0] == '[':
        				del stack[0]
        			else:
        				return False
        		elif ch == '}':
        			if stack[0] == '{':
        				del stack[0]
        			else:
        				return False
        return len(stack) == 0

s = Solution()
print s.isValid("asdfasdf[asdff[{(f)aesf]asfe]}")