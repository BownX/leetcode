class MinStack:
	def __init__(self):
		self.data = []
		self.min = []

	# @param x, an integer
	# @return an integer
	def push(self, x):
		minIndex = 0
		self.data.append(x)
		if len(self.data) == 1:
			self.min.append(0)
			return
		if x < self.getMin():
			minIndex = len(self.data) - 1
		else:
			minIndex = self.min[-1]
		self.min.append(minIndex)

    # @return nothing
	def pop(self):
		if len(self.data) != 0:
			del self.data[-1]
			del self.min[-1]

    # @return an integer
	def top(self):
		return self.data[-1]

    # @return an integer
	def getMin(self):
		if len(self.data) == 0:
			return 0
		return self.data[self.min[-1]]


s = MinStack()
s.push(2)
s.push(4)
s.push(6)
s.push(1)
s.push(3)
s.push(9)
s.push(8)
s.push(0)

print s.getMin()

s.pop()

print s.getMin()

s.pop()

print s.getMin()

s.pop()

print s.getMin()

s.pop()

print s.getMin()

s.pop()

print s.getMin()

s.pop()

print s.getMin()

s.pop()

print s.getMin()

s.pop()

print s.getMin()

s.pop()

print s.getMin()