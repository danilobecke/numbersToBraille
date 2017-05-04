typedef struct brailleCell {
    char decoded;
    int array[6];
} brailleCell;

brailleCell* getAlphabetCells();
