#ifndef UTILS_C
#define UTILS_C

#include <stdio.h>

/**@Author    : wyj
 * @function  : print a specified number of stars
 * @parameter : the number of stars
 * @return    : void
 */
void printStars(int starNum) {
	while(starNum--) printf("*");
}

/**@Author    : wyj
 * @function  : get user's choice input with costom style
 * @parameter : void
 * @return    : an integer of the choice
 */
int getChoice() {
	int res;
	printf("Choice >> ");
	scanf("%d",&res);
	return res;
}

/**@Author    : wyj
 * @function  : get user's choice input with costom style
 * @parameter : void
 * @return    : a char of the input
 */
char getChar() {
	char res;
	printf("Char >> ");
	scanf("%c",&res);
	return res;
}

/**@Author    : wyj
 * @function  : print the given string
 * @parameter : a pointer to the string
 * @return    : void
 */
void printString(char *str) {
	int i = 0;
	while(str[i] != '\0') printf("%c",str[i++]);
}

/**@Author    : wyj
 * @function  : count the number of words in a sentence
 * @parameter : the pointer to the sentence
 * @return    : the count
 */
int countWords(char *input) {
	int wordCount = 0;
	int inWord = 0;
	while (*input) {
		if (isspace(*input)) {
			inWord = 0;
		} else if (!inWord) {
			inWord = 1;
			++wordCount;
		}
		input++;
	}
	return wordCount;
}

/**@Author    : wyj
 * @function  : get the concrete word at the given index on the given sentence
 * @parameter : the pointer to the sentence, the index
 * @return    : the word at input[index]
 */
char* getWord(char* input, const int index) {
	int wordCount = 0;
	int inWord = 0;
	char* start = NULL;
	char* end = NULL;

	while (*input) {
		if (isspace(*input)) {
			inWord = 0;
			if (start && !end) {
				end = input - 1;
			}
		} else if (!inWord) {
			inWord = 1;
			wordCount++;
			if (wordCount == index) {
				start = input;
			}
			if (wordCount == index + 1) {
				end = input - 1;
				break;
			}
		}
		input++;
	}
	if (start && !end) {
		end = input - 1;
	}
	if (start && end) {
		int len = (int)(end - start + 1);
		char* result = malloc(len + 1);
		strncpy(result, start, len);
		result[len] = '\0';
		return result;
	} else {
		return NULL;
	}
}

/**@Author    : wyj
 * @function  : remove the last char of the given string
 * @parameter : the pointer to the string
 * @return    : void
 */
void removeLastChar(char* str) {
	int len = strlen(str);
	if (len > 0) {
		str[len - 1] = '\0';
	}
}

#endif
