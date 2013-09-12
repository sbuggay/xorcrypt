//Devan Buggay 2013
//xorcrypt

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

void crypt_file (char *in, char *out, uint8_t key) {
	//create file pointers
	FILE *ifp;
	FILE *ofp;

	//open and test input file
	ifp = fopen(in, "rb");
	if (ifp == NULL) {
		fprintf(stderr, "Can't open input file %s!\n", in);
		exit(1);
	}

	//open and test output file
	ofp = fopen (out, "wb");
	if (ofp == NULL) {
		fprintf(stderr, "Can't open output file %s!\n", out);
		exit(1);
	}

	uint8_t temp;
	while (fread(&temp, 1, 1, ifp) == 1) {
		temp = temp ^ key; //xor with key
		fwrite(&temp, 1, 1, ofp); //write to output file
	}
	if (feof(ifp)) //reached end of input file
	{
		printf("Output file written to %s\n", out);
	}
	else // error occured
	{
		fprintf(stderr, "Error occured while reading input file %s!\n", in);
		exit(1);
	}

	//close file pointers
	fclose(ifp);
	fclose(ofp);
}

int main(int argc, char *argv[]) {
	if(argc == 4) {
		crypt_file (argv[1], argv[2], atoi(argv[3]));
	}
	else {
		puts ("please use xorcrypt [in.file] [out.file] [key[byte]]");
	}
	return 0;
}



