#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *crypt(char *in, unsigned char key);

int main(int argc, char *argv[]) {
	if(argc == 3) {
		crypt(argv[1], atoi(argv[2]));
	}
	else {
		puts("please use xorcrypt [word] [key]");
	}
	return 0;
}

char *crypt(char *in, unsigned char key) {
	char *p = in;
	while(*p) {
		putchar(*p++ ^ key);
	}
	puts("");
}

