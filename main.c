#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char *variableList[1000]; int vIndex = 0;
int integerList[1000] = { 0 }; int iIndex = 0;

bool isKeyword(char* str) {

	if (!strcmp(str, "int") ||
		!strcmp(str, "move") || !strcmp(str, "to") || !strcmp(str, "add") ||
		!strcmp(str, "sub") || !strcmp(str, "from") ||
		!strcmp(str, "loop") || !strcmp(str, "times") ||
		!strcmp(str, "out")) {
		return true;
	}

	return false;
}

bool isInteger(char* str) {

	int len = strlen(str);

	if (len > 100) {
		return false;
	}

	for (int i = 0; i < len; i++) {
		if (i > 0) {
			if (str[i] == '-' || len == 1) {
				return false;
			}
		}
		if (!(isdigit(str[i]) || str[i] == '-')) {
			return false;
		}
	}

	return true;
}

bool isIntegerVariable(char* str) {

	for (int i = 0; i < vIndex; i++) {
		if (!strcmp(str, variableList[i])) {
			return true;
		}
	}

	return false;
}

bool isVariable(char* str)
{
	int len = strlen(str);

	if (len > 20) {
		return false;
	}

	for (int i = 0; i < len; i++) {
		if (str[0] == '_') {
			return false;
		}
		if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] == '_'))) {
			return false;
		}
	}

	return true;
}

void parse(char* code) {
	int lineCount = 0;
	char *line[1000];
	char *splitCode = strtok(code, ".");
	while (splitCode != NULL) {
		line[lineCount++] = splitCode;
		splitCode = strtok(NULL, ".");
	}

	for (int i = 0; i < lineCount; i++) {
		int wordCount = 0;
		char *word[1000];
		char *splitLine = strtok(line[i], " \n\r[]\"");
		while (splitLine != NULL) {
			word[wordCount++] = splitLine;
			splitLine = strtok(NULL, " \n\r");
		}

		if (wordCount == 0) { return; }

		//Int
		if (!strcmp(word[0], "int")) {
			printf("'int' is a keyword.\n");

			//Variable
			if (word[1] == NULL) {
				printf("Variable is expected.\n");
				return 0;
			}
			else if (isKeyword(word[1])) {
				printf("'%s' is a keyword. Variable is expected.\n", word[1]);
				return 0;
			}
			else if (isVariable(word[1])) {
				printf("'%s' is a variable.\n", word[1]);

				variableList[vIndex++] = word[1];
				integerList[iIndex++] = 0;
			}
			else {
				printf("'%s' is not a variable. Variable is expected.\n", word[1]);
				return 0;
			}

			//End Of Line
			if (wordCount == 2) {
				printf("'.' End of Line.\n");
			}
			else {
				printf("End of line is expected.\n");
				return 0;
			}
		}


		//Move
		else if (!strcmp(word[0], "move")) {
			printf("'move' is a keyword.\n");

			//Integer Or Variable
			int moveInt = 0;
			if (word[1] == NULL) {
				printf("Integer or variable are expected.\n");
				return 0;
			}
			else if (isKeyword(word[1])) {
				printf("'%s' is a keyword. Integer or variable are expected.\n", word[1]);
				return 0;
			}
			else if (isInteger(word[1])) {
				printf("'%s' is an integer.\n", word[1]);

				moveInt = atoi(word[1]);
			}
			else if (isIntegerVariable(word[1])) {
				printf("'%s' is a variable.\n", word[1]);

				for (int i = 0; i < vIndex; i++) {
					if (!strcmp(variableList[i], word[1])) {
						moveInt = integerList[i];
						break;
					}
				}
			}
			else {
				printf("'%s' is not a integer or variable. Integer or variable are expected.\n", word[1]);
				return 0;
			}

			//To
			if (word[2] == NULL) {
				printf("Keyword 'to' is expected.\n");
				return 0;
			}
			else if (!strcmp(word[2], "to")) {
				printf("'to' is a keyword.\n");
			}
			else {
				printf("Keyword 'to' is expected.\n");
				return 0;
			}

			//Variable
			if (word[3] == NULL) {
				printf("Variable is expected.\n");
				return 0;
			}
			else if (isKeyword(word[3])) {
				printf("'%s' is a keyword. Variable is expected.\n", word[3]);
				return 0;
			}
			else if (isIntegerVariable(word[3])) {
				printf("'%s' is a variable.\n", word[3]);

				for (int i = 0; i < vIndex; i++) {
					if (!strcmp(variableList[i], word[3])) {
						integerList[i] = moveInt;
						break;
					}
				}
			}
			else {
				printf("'%s' is not a variable. Variable is expected.\n", word[3]);
				return 0;
			}

			//End Of Line
			if (wordCount == 4) {
				printf("'.' End of Line.\n");
			}
			else {
				printf("End of line is expected.\n");
				return 0;
			}
		}


		//Add
		else if (!strcmp(word[0], "add")) {
			printf("'add' is a keyword.\n");

			//Integer Or Variable
			int addInt = 0;
			if (word[1] == NULL) {
				printf("Integer or variable are expected.\n");
				return 0;
			}
			else if (isKeyword(word[1])) {
				printf("'%s' is a keyword. Integer or variable are expected.\n", word[1]);
				return 0;
			}
			else if (isInteger(word[1])) {
				printf("'%s' is an integer.\n", word[1]);

				addInt = atoi(word[1]);
			}
			else if (isIntegerVariable(word[1])) {
				printf("'%s' is a variable.\n", word[1]);

				for (int i = 0; i < vIndex; i++) {
					if (!strcmp(variableList[i], word[1])) {
						addInt = integerList[i];
						break;
					}
				}
			}
			else {
				printf("'%s' is not a integer or variable. Integer or variable are expected.\n", word[1]);
				return 0;
			}

			//To
			if (word[2] == NULL) {
				printf("Keyword 'to' is expected.\n");
				return 0;
			}
			else if (!strcmp(word[2], "to")) {
				printf("'to' is a keyword.\n");
			}
			else {
				printf("Keyword 'to' is expected.\n");
				return 0;
			}

			//Variable
			if (word[3] == NULL) {
				printf("Variable is expected.\n");
				return 0;
			}
			else if (isKeyword(word[3])) {
				printf("'%s' is a keyword. Variable is expected.\n", word[3]);
				return 0;
			}
			else if (isIntegerVariable(word[3])) {
				printf("'%s' is a variable.\n", word[3]);

				for (int i = 0; i < vIndex; i++) {
					if (!strcmp(variableList[i], word[3])) {
						integerList[i] += addInt;
						break;
					}
				}
			}
			else {
				printf("'%s' is not a variable. Variable is expected.\n", word[3]);
				return 0;
			}

			//End Of Line
			if (wordCount == 4) {
				printf("'.' End of Line.\n");
			}
			else {
				printf("End of line is expected.\n");
				return 0;
			}
		}


		//Sub
		else if (!strcmp(word[0], "sub")) {
			printf("'sub' is a keyword.\n");

			//Integer Or Variable
			int subInt = 0;
			if (word[1] == NULL) {
				printf("Integer or variable are expected.\n");
				return 0;
			}
			else if (isKeyword(word[1])) {
				printf("'%s' is a keyword. Integer or variable are expected.\n", word[1]);
				return 0;
			}
			else if (isInteger(word[1])) {
				printf("'%s' is an integer.\n", word[1]);

				subInt = atoi(word[1]);
			}
			else if (isIntegerVariable(word[1])) {
				printf("'%s' is a variable.\n", word[1]);

				for (int i = 0; i < vIndex; i++) {
					if (!strcmp(variableList[i], word[1])) {
						subInt = integerList[i];
						break;
					}
				}
			}
			else {
				printf("'%s' is not a integer or variable. Integer or variable are expected.\n", word[1]);
				return 0;
			}

			//To
			if (word[2] == NULL) {
				printf("Keyword 'from' is expected.\n");
				return 0;
			}
			else if (!strcmp(word[2], "from")) {
				printf("'to' is a keyword.\n");
			}
			else {
				printf("Keyword 'from' is expected.\n");
				return 0;
			}

			//Variable
			if (word[3] == NULL) {
				printf("Variable is expected.\n");
				return 0;
			}
			else if (isKeyword(word[3])) {
				printf("'%s' is a keyword. Variable is expected.\n", word[3]);
				return 0;
			}
			else if (isIntegerVariable(word[3])) {
				printf("'%s' is a variable.\n", word[3]);

				for (int i = 0; i < vIndex; i++) {
					if (!strcmp(variableList[i], word[3])) {
						integerList[i] -= subInt;
						break;
					}
				}
			}
			else {
				printf("'%s' is not a variable. Variable is expected.\n", word[3]);
				return 0;
			}

			//End Of Line
			if (wordCount == 4) {
				printf("'.' End of Line.\n");
			}
			else {
				printf("End of line is expected.\n");
				return 0;
			}
		}

		//Out
		else if (!strcmp(word[0], "out")) {
			printf("'out' is a keyword.\n");

			//Integer, Variable Or String
			if (word[1] == NULL) {
				printf("Integer, variable or string are expected.\n");
				return 0;
			}
			else if (isInteger(word[1])) {
				printf("'%s' is an integer.\n", word[1]);

				printf("Integer Value: %s\n", word[1]);
			}
			else if (isIntegerVariable(word[1])) {
				printf("'%s' is a variable.\n", word[1]);

				for (int i = 0; i < vIndex; i++) {
					if (!strcmp(variableList[i], word[1])) {
						printf("'%s' variable value: %i\n", word[1], integerList[i]);
						break;
					}
				}
			}
			else {
				printf("%s\n", word[1]);
			}

			//End Of Line
			if (wordCount == 2) {
				printf("'.' End of Line.\n");
			}
			else {
				printf("End of line is expected.\n");
				return 0;
			}
		}

		//Loop
		else if (!strcmp(word[0], "loop")) {
			printf("'loop' is a keyword.\n");

			//Integer Or Variable
			int loopInt = 0;
			if (word[1] == NULL) {
				printf("Integer or variable are expected.\n");
				return 0;
			}
			else if (isKeyword(word[1])) {
				printf("'%s' is a keyword. Integer or variable are expected.\n", word[1]);
				return 0;
			}
			else if (isInteger(word[1])) {
				printf("'%s' is an integer.\n", word[1]);

				loopInt = atoi(word[1]);
			}
			else if (isIntegerVariable(word[1])) {
				printf("'%s' is a variable.\n", word[1]);

				for (int i = 0; i < vIndex; i++) {
					if (!strcmp(variableList[i], word[1])) {
						loopInt = integerList[i];
						break;
					}
				}
			}
			else {
				printf("'%s' is not a integer or variable. Integer or variable are expected.\n", word[1]);
				return 0;
			}

			//Times
			if (word[2] == NULL) {
				printf("Keyword 'times' is expected.\n");
				return 0;
			}
			else if (!strcmp(word[2], "times")) {
				printf("'times' is a keyword.\n");
			}
			else {
				printf("Keyword 'times' is expected.\n");
				return 0;
			}

			//Code
			for (int i = 0; i < loopInt; i++) {
				char newCode[100] = "";
				for (int i = 3; i < wordCount; i++) {
					strcat(newCode, " ");
					strcat(newCode, word[i]);
				}
				strcat(newCode, ".");
				parse(newCode);
			}

			//End Of Line
			if (wordCount > 4) {
				printf("'.' End of Line.\n");
			}
			else {
				printf("End of line is expected.\n");
				return 0;
			}
		}

		else {
			printf("%s", word[0]);
		}
	}
}

char commentLine[100]; char a[100]; char b[100];
void isComment(char* str) {
	bool trueComment = false;
	int j;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '{') {
			for (j = i; j < strlen(str); j++) {
				if (str[j] == '}') {
					substring(str, i + 1, j - i - 1, commentLine);
					printf("Comment Line: '%s'\n", commentLine);

					substring(str, 0, i, a);
					substring(str, j + 1, strlen(str), b);
					strcat(a, b);
					strcpy(str, a);

					trueComment = true;

					isComment(str);
				}
			}
			if (!trueComment) {
				printf("Comment Line is not completed.\n");
				exit(0);
			}
		}
	}
}
int substring(char *source, int from, int n, char *target) {
	int length, i;
	for (length = 0; source[length] != '\0'; length++);
	if (from > length) {
		printf("Starting index is invalid.\n");
		return 1;
	}
	if ((from + n) > length) {
		n = (length - from);
	}
	for (i = 0; i < n; i++) {
		target[i] = source[from + i];
	}
	target[i] = '\0';
	return 0;
}

int main() {
	FILE *fp;
	long lSize;
	char *code;

	fp = fopen("myscript.ba", "rb");
	if (!fp) perror("myscript.ba"), exit(1);

	fseek(fp, 0L, SEEK_END);
	lSize = ftell(fp);
	rewind(fp);

	code = calloc(1, lSize + 1);
	if (!code) fclose(fp), fputs("memory alloc fails", stderr), exit(1);

	if (1 != fread(code, lSize, 1, fp)) {
		fclose(fp), free(code), fputs("entire read fails", stderr), exit(1);
	}

	isComment(code);
	parse(code);
}