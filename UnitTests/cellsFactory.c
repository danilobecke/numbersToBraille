#include "cellsFactory.h"

brailleCell letterFromFirstSequence(char decoded) {
    
    brailleCell cell;
    cell.decoded = decoded;
    
    cell.array[2] = 0;
    cell.array[5] = 0;
    
    if((int)decoded < (int)'i') {
        cell.array[0] = 1;
    } else {
        cell.array[0] = 0;
    }
    
    if(decoded == 'b' || decoded == 'f' || decoded == 'g' || decoded == 'h' || decoded == 'i' || decoded == 'j')
        cell.array[1] = 1;
    else
        cell.array[1] = 0;
    if(decoded == 'c' || decoded == 'd' || decoded == 'f' || decoded == 'g' || decoded == 'i' || decoded == 'j')
        cell.array[3] = 1;
    else
        cell.array[3] = 0;
    if(decoded == 'd' || decoded == 'e' || decoded == 'g' || decoded == 'h' || decoded == 'j')
        cell.array[4] = 1;
    else
        cell.array[4] = 0;
    
    return cell;
}

brailleCell letterFromSecondSequence(char decoded) {
    
    int number = (int)decoded - (int)'j' + (int)'a' - 1;
    char letter = (char)number;
    
    brailleCell cell = letterFromFirstSequence(letter);
    cell.decoded = decoded;
    cell.array[2] = 1;
    
    return cell;
}

brailleCell letterFromThirdSequence(char decoded) {
    
    int number = (int)decoded - (int)'t' + (int)'a' - 1;
    char letter = (char)number;
    
    brailleCell cell;
    
    if((int)decoded < (int)'w') {
        cell = letterFromFirstSequence(letter);
    } else if((int)decoded > (int)'w') {
        letter--;
        cell = letterFromFirstSequence(letter);
    } else {
        cell.decoded = 'w';
        cell.array[0] = 0;
        cell.array[1] = 1;
        cell.array[2] = 0;
        cell.array[3] = 1;
        cell.array[4] = 1;
        cell.array[5] = 1;
        return cell;
    }
    
    cell.decoded = decoded;
    cell.array[2] = 1;
    cell.array[5] = 1;
    
    return cell;
}

brailleCell getLetter(char decoded) {
    
    brailleCell cell;
    
    if((int)decoded < (int)'k' ) {
        cell = letterFromFirstSequence(decoded);
    } else if((int)decoded < (int)'u') {
        cell = letterFromSecondSequence(decoded);
    } else {
        cell = letterFromThirdSequence(decoded);
    }
    
    return cell;
}

brailleCell* getAlphabetCells() {
    
    int i;
    brailleCell *alphabet = malloc(26*sizeof(brailleCell));
    
    char letter = 'a';
    for(i=0; i<26; i++) {
        alphabet[i] = getLetter(letter);
        letter++;
    }
    
    return alphabet;
}

brailleCell* getNumbersCells() {
    
    int i;
    brailleCell *numbers = malloc(11*sizeof(brailleCell));
    
    char letter = 'a';
    for(i=1; i<10; i++) {
        numbers[i] = getLetter(letter);
        letter++;
    }
    numbers[0] = getLetter(letter);
    
    brailleCell numberSymbol;
    numberSymbol.decoded = (char)0;
    for(i=0;i<6;i++) {
        if(i<2)
            numberSymbol.array[i] = 0;
        else
            numberSymbol.array[i] = 1;
    }
    numbers[10] = numberSymbol;
    
    return numbers;
}
