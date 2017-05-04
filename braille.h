#include <stdio.h>

#ifndef Braille_h
#define Braille_h

/**
 Decodes a braille cell.

 @param array Array with 6 positions of the braille cell.
 @return The decoded char.
 */
char decodeChar(int *array);

#endif /* Braille_h */
