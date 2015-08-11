/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

https://leetcode.com/problems/valid-parentheses/
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

bool isValid(char* s) {
	int length = strlen(s);
	char* stack = malloc(sizeof(char) * length);
	int stackIndex = -1;
    while (s != NULL && *s != '\0') {
    	switch (*s) {
    		case '(':
    		case '[':
    		case '{':
    			stackIndex++;
    			stack[stackIndex] = *s;
    			break;
    		case ')':
				if (stackIndex >= 0 && stack[stackIndex] == '(') stackIndex--;
				else return false;
				break;
			case ']':
				if (stackIndex >= 0 && stack[stackIndex] == '[') stackIndex--;
				else return false;
				break;
			case '}':
				if (stackIndex >= 0 && stack[stackIndex] == '{') stackIndex--;
				else return false;
				break;
    	}
    	s++;
    }
    return stackIndex < 0;
}

int main(int argc, char const *argv[]) {
	char* s = "a[sd(fs{d)f]f}";
	printf("%d\n", isValid(s));
	return 0;
}