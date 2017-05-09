/**
 Checks if the cell is of the first sequence.
 Note: the sequences are indexed by 1.
 
 @param array Array with the braille cell.
 @return 0 if it isn't or the position inside the sequence
 */
int isFromFirstSequence(int* array) {
    
    if(array[2] != 0 || array[5] != 0)
        return 0;
    
    int pos1 = array[0],
        pos2 = array[1],
        pos4 = array[3],
        pos5 = array[4];
    
    if(pos1 == 0) {
        if(pos2 != 1 || pos4 != 1) {
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
int isFromSecondSequence(int *array) {
    
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
int isFromThirdSequence(int *array) {
    
    if(array[2] == 1 && array[5] == 1)
        return 1;
    else
        return 0;
}

/**
 Checks if the cell is of the forth sequence.
 
 @param array Array with the braille cell.
 @return 1 if it is or 0.
 */
int isFromFourthSequence(int *array) {
    if(array[2] == 0 && array[5] == 1)
        return 1;
    else
        return 0;
}

/**
 Checks if the cell is of the fifth sequence

 @param array Array with the braille cell
 @return 0 if it isn't or the position inside the sequence
 */
int isFromFifthSequence(int *array) {
    if(array[0] !=0 || array[3] != 0)
        return 0;
    int i, aux[6];
    for(i=1; i<6; i++) {
        if(i != 3)
            aux[i-1] = array[i];
        else
            aux[i-1] = 0;
    }
    aux[5] = 0;
    return isFromFirstSequence(aux);
}

/**
 Checks if the cell is of the sixth sequence.
 
 @param array Array with the braille cell.
 @return 1 if it is or 0.
 */
int isFromSixthSequence(int *array) {
    if(array[2] == 1)
        return 1;
    else
        return 0;
}

int checkSpecialChar(int* array) {
    if(array[3] == 1 && array[4] == 1 && array[5] == 1) {
        if(array[0] == 0 && array[1] == 1 && array[2] == 0) {
            return 'w';
        }
    }
    return ' ';
}

char decodeChar(int *array) {
    
    int aux[6] = {array[0],array[1],0,array[3],array[4],0},
        firstSequence = isFromFirstSequence(aux),
        secondSequence = isFromSecondSequence(array),
        thirdSequence = isFromThirdSequence(array),
        fourthSequence = isFromFourthSequence(array),
        fifthSequence = isFromFifthSequence(array);
    
    if(firstSequence != 0 && fifthSequence == 0) {
        //is from 1st + 2nd sequences
        if(secondSequence == 1) {
            return (char)((int)'j' + firstSequence);
        }
        // is from 1st + 3rd sequences
        else if(thirdSequence == 1) {
            // letter before w
            if(firstSequence < 3) {
                return (char)((int)'t' + firstSequence);
            }
            // letter after w
            else if(firstSequence < 6) {
                return (char)((int)'t' + firstSequence + 1);
            }
            // symbol isn't from alphabet
            else {
                return checkSpecialChar(array);
            }
        }
        // is from 1st + 4th sequences
        else if(fourthSequence == 1) {
            //TODO: fix here
            return checkSpecialChar(array);
        }
        // is from 1st sequence
        else {
            return (char)((int)'a' + firstSequence - 1);
        }
    }
    // symbol isn't from first sequence
    else {
        // is from 5th sequence
        if(fifthSequence != 0) {
            //TODO: fifth sequence decoder
        }
        // is from 6th sequence
        else if(isFromSixthSequence(array) != 0) {
            //TODO: sixth sequence decoder
        }
        // is from 7th sequence
        else {
            //TODO: seventh sequence decoder
        }
    }
    return ' ';
}
