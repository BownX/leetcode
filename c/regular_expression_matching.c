/*
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true  // 注，这里是匹配 (c*)(a*)b 这个模式，*号是可以和前面一个元素组合起来看的

https://leetcode.com/problems/regular-expression-matching/
*/	

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

// dp solution
bool isMatch(char* s, char* p) {
	int len_s = strlen(s);
	int len_p = strlen(p);
	bool dp[len_s + 1][len_p + 1];
	memset(dp, false, sizeof(bool) * (len_s + 1) * (len_p + 1));
	dp[0][0] = true;
	for (int i = 0; i <= len_s; ++i) {
		for (int j = 1; j <= len_p; ++j) {
			if (p[j - 1] == '*') {
				dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
			} else {
				dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
			}
		}
	}
	return dp[len_s][len_p];
}

int main(int argc, char const *argv[]) {
	printf("%d\n", isMatch("abcd", "d*"));
	return 0;
}