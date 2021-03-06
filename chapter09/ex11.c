/*
 * 11. Extend the strToInt() function from Program 9.11 so that if the first
 * character of the string is a minus sign, the value that follows is taken as
 * a negative number.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdbool.h>

int strToInt(const char []);

int strToInt(const char string[])
{
	int  i, digit, number = 0;
	bool negative = false;

	/* skip leading whitespace */
	for (i = 0; string[i] == ' ' || string[i] == '\t'; ++i)
		;

	if (string[i] == '-') {
		++i;
		negative = true;
	}

	for (; string[i] >= '0' && string[i] <= '9'; ++i) {
		digit = string[i] - '0';
		number = number * 10 + digit;
	}

	if (negative == true)
		number *= -1;

	return number;
}

int main(void) 
{
	printf("%i\n", strToInt("-245"));
	printf("%i\n", strToInt(" 100") + 25);
	printf("%i\n", strToInt("\t13x5"));
	printf("%i\n", strToInt("xxx"));
	printf("%i\n", strToInt("2147483647"));
	printf("%i\n", strToInt("-2147483648"));

	return 0;
}
