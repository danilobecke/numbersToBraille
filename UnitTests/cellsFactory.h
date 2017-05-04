#include <stdlib.h>
#include <stdio.h>

#ifndef CellFactory_h
#define CellFactory_h

typedef struct brailleCell {
    char decoded;
    int array[6];
} brailleCell;

brailleCell* getAlphabetCells();

#endif /* CellFactory_h */
