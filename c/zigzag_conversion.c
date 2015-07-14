#include "stdio.h"
#include "string.h"
#include "stdlib.h"

char* convert(char* s, int numRows) {
	if (numRows <= 1) {
		return s;
	}
    int length = strlen(s);
    int row_of_char[length];
    int current_row = 0;
    int direction = 1;
    for (int i = 0; i < length; ++i) {
    	row_of_char[i] = current_row;
    	if (current_row == 0) {
    		direction = 1;
    	}
    	if (current_row == numRows - 1) {
    		direction = -1;
    	}
    	current_row += direction;
    }
    char* result = malloc(sizeof(char) * (length + 1));
    int index = 0;
    for (int i = 0; i < numRows; ++i) {
    	for (int j = 0; j < length; ++j) {
    		if (row_of_char[j] == i) {
    			result[index] = s[j];
    			index++;
    		}
    	}
    }
    result[length] = '\0';
    return result;
}

int main(int argc, char const *argv[]) {
	printf("%s\n", convert("AB", 1));
	return 0;
}