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
            sprintf(resultMsg, "error with letter %c", selected.decoded);
            mu_assert(resultMsg, decodeChar(selected.array) == selected.decoded);
        }
        
        return 0;
    }

    static char * test_oneDigitNumbers() {
        
        int i, clearState[6] = {1,1,1,1,0,0};
        brailleCell *numbers = getNumbersCells(), selected;
        char *resultMsg = malloc(10*sizeof(char));
        
        for(i=0; i<10; i++) {
            selected = numbers[i];
            sprintf(resultMsg, "error with number %d", i);
            mu_assert(resultMsg, decodeChar(numbers[10].array) == (char)0);
            mu_assert(resultMsg, decodeChar(selected.array) == (char)(i+48));
            decodeChar(clearState);
        }
        
        return 0;
    }

    static char * test_moreThanOneDigitsNumbers() {
        
        brailleCell *numbers = getNumbersCells();
        char *resultMsg = malloc(10*sizeof(char));
        int clearState[6] = {1,1,1,1,0,0},
            separator[6] = {0,0,1,0,0,0},
            decimal[6] = {0,1,0,0,0,0};
        
        mu_assert(resultMsg, decodeChar(numbers[10].array) == (char)0);
        
        sprintf(resultMsg, "error with number %d", 15);
        mu_assert(resultMsg, decodeChar(numbers[1].array) == '1');
        mu_assert(resultMsg, decodeChar(numbers[5].array) == '5');
        
        decodeChar(clearState);
        mu_assert(resultMsg, decodeChar(numbers[10].array) == (char)0);
        
        sprintf(resultMsg, "error with number %d", 203);
        mu_assert(resultMsg, decodeChar(numbers[2].array) == '2');
        mu_assert(resultMsg, decodeChar(numbers[0].array) == '0');
        mu_assert(resultMsg, decodeChar(numbers[3].array) == '3');
        
        // class separator
        decodeChar(clearState);
        mu_assert(resultMsg, decodeChar(numbers[10].array) == (char)0);
        
        sprintf(resultMsg, "error with number %d", 467890);
        mu_assert(resultMsg, decodeChar(numbers[4].array) == '4');
        mu_assert(resultMsg, decodeChar(numbers[6].array) == '6');
        mu_assert(resultMsg, decodeChar(numbers[7].array) == '7');
        mu_assert(resultMsg, decodeChar(separator) == '.');
        mu_assert(resultMsg, decodeChar(numbers[8].array) == '8');
        mu_assert(resultMsg, decodeChar(numbers[9].array) == '9');
        mu_assert(resultMsg, decodeChar(numbers[0].array) == '0');
        
        // decimal
        decodeChar(clearState);
        mu_assert(resultMsg, decodeChar(numbers[10].array) == (char)0);
        
        sprintf(resultMsg, "error with number %d,%d", 3, 5);
        mu_assert(resultMsg, decodeChar(numbers[3].array) == '3');
        mu_assert(resultMsg, decodeChar(decimal) == ',');
        mu_assert(resultMsg, decodeChar(numbers[5].array) == '5');
        
        decodeChar(clearState);
        
        return 0;
    }

    static char * test_letterAfterNumber() {
        
        brailleCell *numbers = getNumbersCells(),
                    *alphabet = getAlphabetCells();
        char *resultMsg = malloc(10*sizeof(char));
        
        mu_assert(resultMsg, decodeChar(numbers[10].array) == (char)0);
        
        sprintf(resultMsg, "error with %dok", 15);
        mu_assert(resultMsg, decodeChar(numbers[1].array) == '1');
        mu_assert(resultMsg, decodeChar(numbers[5].array) == '5');
        mu_assert(resultMsg, decodeChar(alphabet[14].array) == 'o');
        mu_assert(resultMsg, decodeChar(alphabet[10].array) == 'k');
        
        sprintf(resultMsg, "error with ok%d", 15);
        mu_assert(resultMsg, decodeChar(alphabet[14].array) == 'o');
        mu_assert(resultMsg, decodeChar(alphabet[10].array) == 'k');
        mu_assert(resultMsg, decodeChar(numbers[10].array) == (char)0);
        mu_assert(resultMsg, decodeChar(numbers[1].array) == '1');
        mu_assert(resultMsg, decodeChar(numbers[5].array) == '5');
        
        sprintf(resultMsg, "error with %dopa", 15);
        mu_assert(resultMsg, decodeChar(numbers[1].array) == '1');
        mu_assert(resultMsg, decodeChar(numbers[5].array) == '5');
        mu_assert(resultMsg, decodeChar(alphabet[14].array) == 'o');
        mu_assert(resultMsg, decodeChar(alphabet[15].array) == 'p');
        mu_assert(resultMsg, decodeChar(alphabet[0].array) == 'a');
        
        return 0;
    }

    static char * all_tests() {
        mu_run_test(test_alphabet);
        mu_run_test(test_oneDigitNumbers);
        mu_run_test(test_moreThanOneDigitsNumbers);
        mu_run_test(test_letterAfterNumber);
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
