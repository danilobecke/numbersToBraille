#include "cellsFactory.h"
#include "../braille.h"
#include "minunit.h"

//TESTS
    int tests_run = 0;

    static char * test_alphabet() {
        
        int i;
        brailleCell *alphabet = getAlphabetCells(), selected;
        char *resultMsg = malloc(10*sizeof(char));
        
        for(i=0; i<26; i++) {
            selected = alphabet[i];
            sprintf(resultMsg, "error with %c", selected.decoded);
            mu_assert(resultMsg, decodeChar(selected.array) == selected.decoded);
        }
        
        return 0;
    }

    static char * all_tests() {
        mu_run_test(test_alphabet);
        return 0;
    }

// PRINT
void printAlphabet() {
    brailleCell *alphabet = getAlphabetCells(), selected;
    int i;
    
    printf("----------\n");
    
    for(i=0; i<26; i++) {
        selected = alphabet[i];
        printf("%c: %d%d%d%d%d%d\n", selected.decoded, selected.array[0], selected.array[1], selected.array[2], selected.array[3], selected.array[4], selected.array[5]);
    }
    
    printf("----------\n");
}

    int main(int argc, char **argv) {
        char *result = all_tests();
        if (result != 0) {
            printf("%s\n", result);
        }
        else {
            printf("ALL TESTS PASSED\n");
        }
        printf("Tests run: %d\n", tests_run);
        
        printAlphabet();
        
        return result != 0;
    }
