// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Driver code
int main(int argc, char *argv[])
{
    FILE *fp_r;
    fp_r = fopen(argv[1], "r");
	char str[50];
	// fp_r = fopen("inp.txt", "a+");

	if (NULL == fp_r) {
		printf("file can't be opened \n");
	}

	printf("content of this file are \n");

	while (fgets(str, 50, fp_r) != NULL) {
		// printf("%s", str);
		char* token_1 = strtok(str," ");
		printf("%c \n", token_1[0]);
		char* token_2 = strtok(NULL," ");
		if(token_2!=NULL)
			printf("%s",token_2);
	}

	fclose(fp_r);
	return 0;
}

// int main()
// {
// 	char dest[50] = "Hello World";
// 	char* token = strtok(dest," ");
// 	printf("%s \n",dest);

// 	return 0;
// }
