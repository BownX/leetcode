/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

https://leetcode.com/problems/longest-palindromic-substring/
*/

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

/*
最大回文串的动态规划解法，复杂度: 时间空间都是 O(n^2)
主要思想是：如果s[i+1~j-1]是回文串且s[i]=s[j]，那么s[i][j]也一定是

AC失败，超时了 = =
*/
char* longestPalindrome_dp(char* s) {
	int length = strlen(s);
	bool isPalindrome[length][length];
	// 定义 isPalindrome，用于记录 s 中位置 i~j 这一段是不是回文的.
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			// 初始化时，i=j(1个字符)和i>j(0个字符)时为true，其他都false
			isPalindrome[i][j] = (i >= j);
		}
	}

	int j, k;
	int max_length = 0;
	int max_start = 0;
	// k代表s[i~j]长度，循环从长度为1开始
	for (int k = 1; k < length; ++k) {
		for (int i = 0; k + i < length; ++i) {
			j = i + k;
			if (s[i] != s[j]) {
				isPalindrome[i][j] = false;
			} else {
				isPalindrome[i][j] = isPalindrome[i + 1][j - 1];
				if (isPalindrome[i][j]) {
					// 记录最大回文串的长度和起点index
					if (k + 1 > max_length) {
						max_length = k + 1;
						max_start = i;
					}
				}
			}
		}
	}
	char* result = malloc(sizeof(char) * (max_length + 1));
	memcpy(result, &s[max_start], max_length);
	result[max_length] = '\0';
	return result;
}

/*
Thanks to: http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
Manacher解法，复杂度: O(n)
目测此解法也只能用于这个问题了。。
*/
char* longestPalindrome_manacher(char* s) {
	int length = strlen(s);
	int t_length = 2 * length + 3;
	// 先将原始字符串转换为'#'间隔、'^'开头、'$'结尾的串
	char temp[2 * length + 3];
	temp[0] = '^';
	for (int i = 1; i < t_length - 2; i += 2) {
		temp[i] = '#';
		temp[i + 1] = s[i / 2];
	}
	temp[t_length - 2] = '#';
	temp[t_length - 1] = '$';

	// p保存对应index的节点为中心的最大回文串长度
	int p[t_length];
	// C为当前回文串中心index，R为当前回文串右边界
	int C = 0, R = 0;
	for (int i = 0; i < t_length - 1; ++i) {
		// i_mirror 对应 i 相对于 C 的对称点
		int i_mirror = 2 * C - i;
		// 这里有一个上面文章推导出的结论，若p[i_mirror] <= R-i，则p[i]=p[i_mirror]
		// 即若 i 在以 C 为中心 R 为半径的回文串内，i 以 C 对称的点 i_mirror 的最大回文串长度 <= R-i
		p[i] = (R > i) ? (R - i < p[i_mirror] ? R - i : p[i_mirror]) : 0;
		// 两边延伸 R
		while (temp[i + 1 + p[i]] == temp[i - 1 - p[i]]) p[i]++;
		if (i + p[i] > R) {
			C = i;
			R = i + p[i];
		}
	}

	int max_length = 0;
	int center_index = 0;
	for (int i = 0; i < t_length - 1; ++i) {
		if (p[i] > max_length) {
			max_length = p[i];
			center_index = i;
		}
	}

	char* result = malloc(sizeof(char) * (max_length + 1));
	memcpy(result, &s[(center_index - 1 - max_length) / 2], max_length);
	result[max_length] = '\0';
	return result;
}

int main(int argc, char const *argv[]) {
	char str[] = "abccba";
	printf("%s\n", longestPalindrome_manacher(str));
	return 0;
}