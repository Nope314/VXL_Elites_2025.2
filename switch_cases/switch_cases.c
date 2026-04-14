#include <stdio.h>

int main() {
    int local_val = 15;

    int test_variable_1;
    int test_variable_2;
    int test_variable_3;
    
    //Test case 1 : standard case
    switch (local_val) {
        case 5:
            test_variable_1 = -1;
            break;
        case 15:
            test_variable_1 = 1;
            break;
    }
    printf("%d \n", test_variable_1);

    //Test case 2 : Switch input is a number
    switch (10) {
        case 5:
            test_variable_2 = 0;
            break;
        case 10:
            test_variable_2 = -1;
            break;
        case 15:
            test_variable_2 = 1;
            break;
    }
    printf("%d \n", test_variable_2);
    
    //Test case 3: No break
    switch (local_val) {
        case 15:
            test_variable_3 = 5;
        case 30:
            test_variable_3 = 15;
            break;
    }
    printf("%d \n", test_variable_3);

    return 0;
}

