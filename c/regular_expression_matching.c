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

Thanks to: https://leetcode.com/discuss/43860/9-lines-16ms-c-dp-solutions-with-explanations
*/	

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

/* dp solution
s = source, p = pattern
*/
bool isMatch(char* s, char* p) {
	int len_s = strlen(s);
	int len_p = strlen(p);
	// 定义 dp 二维数组用来描述 s[0~i] 和 p[0~j] 是否匹配，值存储于 dp[i][j]
	bool dp[len_s + 1][len_p + 1];
	memset(dp, false, sizeof(bool) * (len_s + 1) * (len_p + 1));
	dp[0][0] = true;
	for (int i = 0; i <= len_s; ++i) {
		for (int j = 1; j <= len_p; ++j) {
			// 如果 p[j-1] != '*': 若s[0~i-1]和p[0~j-1]匹配，且p[j-1] == '.' 或 p[j-1]==s[i-1]，则有s[0~i]和p[0~j]匹配，即dp[i][j]=dp[i-1][j-1]
			// 如果 p[j-1] == '*': 
			// 		1. 无论p[j-2]是什么值都由于后面有一个'*'可以匹配，就有了 dp[i][j] = dp[i][j-2]
			// 		2. 若s[0~i-1]和p[0~j]匹配，且s[i-1]==p[j-2]，或p[j-2]是'.'，这时既s[0~i-1]和p[0~j-2]匹配且s[0~i-1]和p[0~j]匹配，说明p[j]是'*'或'.'，一定可以匹配s[i]，即 dp[i][j]
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