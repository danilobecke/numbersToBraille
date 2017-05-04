#include <stdio.h>
#include "cellsFactory.h"

int main() {
    
    brailleCell *alphabet = getAlphabetCells(), selected;
    int i;
    
    for(i=0; i<26; i++) {
        selected = alphabet[i];
        printf("%c: %d%d%d%d%d%d\n", selected.decoded, selected.array[0], selected.array[1], selected.array[2], selected.array[3], selected.array[4], selected.array[5]);
    }
    
    return 0;
}
