#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *crypt(char *in, unsigned char key);

int main(int argc, char *argv[]) {
	crypt("testing", 5);
	return 0;
}

char *crypt(char *in, unsigned char key) {
	char *p = in;
	while(*p) {
		putchar(*p++ ^ key);
	}

}

