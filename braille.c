/**
 Checks if the cell is of the first sequence.
 Note: the sequences are indexed by 1.
 
 @param array Array with the braille cell.
 @return 0 if it isn't or the position inside the sequence
 */
int isFromFirstSequence(int* array) {
    
    int pos1 = array[0],
        pos2 = array[1],
        pos4 = array[3],
        pos5 = array[4];
    
    if(pos1 == 0) {
        if(pos2 != 1 && pos4 != 1) {
            return 0;
        } else {
            if(pos5 == 1) {
                return 10;
            } else {
                return 9;
            }
        }
    } else {
        switch (pos4) {
            case 1:
                if(pos2 == 0) {
                    // 1 4
                    if(pos5 == 0) {
                        return 3;
                    }
                    // 1 4 5
                    else {
                        return 4;
                    }
                } else {
                    // 1 2 4
                    if(pos5 == 0) {
                        return 6;
                    }
                    // 1 2 4 5
                    else {
                        return 7;
                    }
                }
                break;
            case 0:
                if(pos2 == 0) {
                    // 1
                    if(pos5 == 0) {
                        return 1;
                    }
                    // 1 5
                    else {
                        return 5;
                    }
                } else {
                    // 1 2
                    if(pos5 == 0) {
                        return 2;
                    }
                    // 1 2 5
                    else {
                        return 8;
                    }
                }
                break;
            default:
                return 0;
                break;
        }
    }
    
}

/**
 Checks if the cell is of the second sequence.
 
 @param array Array with the braille cell.
 @return 1 if it is or 0.
 */
int isFromSecondSequence(int *array){
    
    if(array[2]==1 && array[5]==0){
        return 1;
    } else
        return 0;
}

/**
 Checks if the cell is of the third sequence.
 
 @param array Array with the braille cell.
 @return 1 if it is or 0.
 */
int isFromThirdSequence(int *array){
    
    if(array[2] == 1 && array[5] == 1) {
        return 1;
    } else
        return 0;
}

int checkSpecialChar(int* array) {
    if(array[3] == 1 && array[4] == 1 && array[5] == 1) {
        if(array[0] == 0 && array[1] == 1 && array[2] == 0) {
            return 'w';
        } else if(array[0] == 1 && array[1] == 0 && array[2] == 1) {
            return 'y';
        }
    }
    return ' ';
}

char decodeChar(int *array) {
    
    int firstSerie = isFromFirstSequence(array),
        secondSerie = isFromSecondSequence(array),
        thirdSerie = isFromThirdSequence(array);
    
    //is alphabetic char
    if(firstSerie != 0) {
        if(secondSerie == 1) {
            return (char)((int)'j' + firstSerie);
        } else if(thirdSerie == 1) {
            if(firstSerie < 2) {
                return (char)((int)'t' + firstSerie);
            } else {
                switch (firstSerie) {
                    case 3:
                        return 'x';
                        break;
                    case 5:
                        return 'z';
                        break;
                    default:
                        return checkSpecialChar(array);
                        break;
                }
            }
        } else {
            char special = checkSpecialChar(array);
            if(special == ' ') {
                return (char)((int)'a' + firstSerie - 1);
            } else {
                return special;
            }
        }
    } /*else {
        
    }*/
    return ' ';
}
