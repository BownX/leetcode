/*
Write a function to find the longest common prefix string amongst an array of strings.

https://leetcode.com/problems/longest-common-prefix/
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*
Trie Tree
*/
char* longestCommonPrefix(char** strs, int strsSize) {
	if (strs == NULL || strsSize == 0) return "";
	char *result = malloc(sizeof(char) * strlen(strs[0]));
	strcpy(result, strs[0]);
	int common = strlen(result);
	for (int i = 1; i < strsSize; ++i) {
		int len = strlen(strs[i]);
		int match = 0;
		for (match = 0; match < len && match < common && strs[i][match] == result[match]; ++match);
		common = match;
	}
	result[common] = '\0';
	return result;
}

int main(int argc, char const *argv[]) {
	char *strs[3] = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",  "aaaaab", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"};
	printf("%s\n", longestCommonPrefix(strs, 0));
	return 0;
}