#include <stdio.h>

#ifndef Header_h
#define Header_h


/**
 Checks if the cell is of the first serie.
 Note: the series are indexed by 1.

 @param array Array of the top 4 braille points.
 @return 0 if it isn't or the position inside the serie
 */
int isFromFirstSerie(int* array);

/**
 Checks if the cell is of the second serie.

 @param array Array with the two inferior braille points.
 @return 1 if it is or 0.
 */
int isFromSecondSerie(int *array);
/**
 Checks if the cell is of the third serie.
 
 @param array Array with the two inferior braille points.
 @return 1 if it is or 0.
 */
int isFromThirdSerie(int *array);
/**
 Decodes a braille cell.

 @param array Array with 6 positions of braille cell.
 @return The decoded char.
 */
char decodeChar(int *array);


#endif /* Header_h */
