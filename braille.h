#include <stdio.h>

#ifndef Header_h
#define Header_h

/**
 Decodes a braille cell.

 @param array Array with 6 positions of the braille cell.
 @return The decoded char.
 */
char decodeChar(int *array);

#endif /* Header_h */
