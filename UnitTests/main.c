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
        printf("ALPHABET\n");
        
        for(i=0; i<26; i++) {
            selected = alphabet[i];
            printf("%c: %d%d%d%d%d%d\n", selected.decoded, selected.array[0], selected.array[1], selected.array[2], selected.array[3], selected.array[4], selected.array[5]);
        }
    }

    void printNumbers() {
        brailleCell *numbers = getNumbersCells(), selected;
        int i;
        
        printf("----------\n");
        printf("NUMBERS\n");
        
        for(i=0; i<10; i++) {
            selected = numbers[i];
            printf("%d: %d%d%d%d%d%d ", i, numbers[10].array[0], numbers[10].array[1], numbers[10].array[2], numbers[10].array[3], numbers[10].array[4], numbers[10].array[5]);
            printf("%d%d%d%d%d%d\n", selected.array[0], selected.array[1], selected.array[2], selected.array[3], selected.array[4], selected.array[5]);
        }
    }

// MAIN
    int main(int argc, char **argv) {
        char *result = all_tests();

        printAlphabet();
        printNumbers();
        printf("----------\n");
        
        if (result != 0)
            printf("%s\n", result);
        else
            printf("ALL TESTS PASSED\n");
        printf("Tests run: %d\n", tests_run);
        
        return result != 0;
    }
