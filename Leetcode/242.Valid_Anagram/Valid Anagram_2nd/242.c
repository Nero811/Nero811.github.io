#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

bool isAnagram(char* s, char* t) {
	int dic[26] = {0};
	int i;
	if (strlen(s) != strlen(t))return false;
	for (int i = 0; i < strlen(s);i++) {
		dic[s[i] - 'a' + 1]++;
	}
	for (int i = 0; i < strlen(t); i++) {
		if (dic[t[i] - 'a' + 1] <1) {
			return false;
		}
		else {
			dic[t[i] - 'a' + 1]--;
		}
	}
	return true;
}

int main(int argc,char *argv[]) {
	char s[5] = "aacc";
	char t[5] = "ccac";
	if (isAnagram(s, t)) {
		printf("true");
	}
	else
	{
		printf("false");
	}
	return 0;
}