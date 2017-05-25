//
//  CellsFactory.hpp
//  numbersToBrailleXcode
//
//  Created by Danilo Becke on 24/05/17.
//  Copyright © 2017 Danilo Becke. All rights reserved.
//

#ifndef CellsFactory_hpp
#define CellsFactory_hpp

#include <stdio.h>
#include <stdlib.h>

typedef struct brailleCell {
    char decoded;
    int array[6];
} brailleCell;

brailleCell* getAlphabetCells();
brailleCell* getNumbersCells();

#endif /* CellsFactory_hpp */
