/* 
 * 6. Write a program that displays the contents of a file at the terminal 20
 * lines at a time. At the end of each 20 lines, have the program wait for a
 * character to be entered from the terminal. If the character is the letter q,
 * the program should stop the display of the file; any other character should
 * cause the next 20 lines from the file to be displayed.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

int main(void) 
{
	int  i;
	char fileName[64], line[81], input;
	FILE *inFile;

	printf("Enter the name of file to read: ");
	scanf("%63s", fileName);

	if ((inFile = fopen(fileName, "r")) == NULL) {
		printf("Can't open %s for reading.\n", fileName);
		return 1;
	}

	while (input != 'q') {
		for (i = 1; i <= 20; ++i)
			fprintf(stdout, fgets(line, 80, inFile));
		scanf("%c", &input);
	}

	return 0;
}