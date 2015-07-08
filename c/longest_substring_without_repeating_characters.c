/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int lengthOfLongestSubstring(char* s) {
	int ids[256];
	memset(ids, -1, sizeof(int) * 256);
	int length = strlen(s);
	int result = 0;
	for (int start = -1, end = 0; end < length; end++) {
		if (ids[s[end]] != -1 && start < ids[s[end]]) {
			start = ids[s[end]];
		}
		result = end - start > result ? end - start : result;
		ids[s[end]] = end;
	}
	return result;
}

int main(int argc, char const *argv[]) {
	char str[] = "a";
	printf("%d\n", lengthOfLongestSubstring(str));
	return 0;
}