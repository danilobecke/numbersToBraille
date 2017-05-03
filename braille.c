int sizeOfArray(int *array) {
    return sizeof(array) / sizeof(int);
}

int isFromFirstSerie(int* array) {
    
    if(sizeOfArray(array) != 6) {
        return 0;
    }
    
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

int isFromSecondSerie(int *array){
    
    if(sizeOfArray(array) != 6) {
        return 0;
    }
    
    if(array[3]==1 && array[6]==0){
        return 1;
    } else
        return 0;
}

int isFromThirdSerie(int *array){
    
    if(sizeOfArray(array) != 6) {
        return 0;
    }
    
    if(array[3] == 1 && array[6] == 1) {
        return 1;
    } else
        return 0;
}
