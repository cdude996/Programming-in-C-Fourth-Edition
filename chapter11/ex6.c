/* 
 * 6. Write a function called bitpat_search() that looks for the occurrence of
 * a specified pattern of bits inside an unsigned int. The function should
 * take three arguments and should be called as shown:
 *
 * index = bitpat_search (0xe1f4, 0x5, 3);
 *
 * causes the bitpat_search() function to search the number 0xe1f4 ( = 1110
 * 0001 1111 0100 binary ) for the occurrence of the three-bit pattern 0x5 (=
 * 101 binary). The function returns 11 to indicate that the pattern was found
 * in the source beginning with bit number 11.  Make certain that the function
 * makes no assumptions about the size of an int (see exercise 3 in this
 * chapter).
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdbool.h>

/* Function that returns the number of bits contained in an integer. */
int int_size(int w)
{
	int mask, nBits = 0, nibble = 4;
	
	mask = ~0;                     /* Integer full of 1's */
	if (w >= 0) {
		w = ~w;                    /* One's complement to invert the bits */
		while (w != mask) {
			w >>= 1;               /* Right shift until w equals mask */
			++nBits;
		}
		if (nBits % nibble !=0)    /* Ensure each nibble is 4 bits */
			nBits += nibble - nBits % nibble;
	} else if (w < 0) {            /* Negative integers */
		w |= mask;                 /* Set all bits to 1 */
		while (w != 0) {           /* Left shift until w equal zero */
			w <<= 1;          
			++nBits;
		}
	}
	return nBits;
}

/* Function that searches source for a given pattern of bits.
 *
 * The variable match contains the chunk of n bits to be compared against
 * the variable pattern in the loop. Var match first, shifts n bits in source
 * from the leftmost position to the rightmost position; second, it AND's the 
 * result with var mask that is shifted n bits to the right and inverted--this
 * is to make sure only n bits are preserved at the rightmost position during 
 * each iteration of the loop.
 */
int bitpat_search(unsigned int source, unsigned pattern, int n)
{
	int size, mask, position = 0;
	unsigned int match;
	bool matchFound = false;
	
	size = int_size(source);                         /* Size of int source */
	mask = ~0;                                       /* Mask integer of 1's */

	while (size >= n) {		
		match = source >> (size - n) & ~(mask << n);  /* See above explanation */
			if (pattern == match) { 
				matchFound = true;                   /* Found it */
				break;
			} else {
				--size;
				++position;
			}
	}
	if (matchFound == true)
		return position;
	else
		return -1;
}

int main(void) 
{
	int int_size(int w), word_size(int w);
	int bitpat_search(unsigned int source, unsigned pattern, int n);
	
	int index;

	index = bitpat_search(0xe1f4, 0x5, 3);

	if (index == -1)
		printf("Match not found.\n");
	else
		printf("Match found at bit %i\n", index);

	return 0;
}