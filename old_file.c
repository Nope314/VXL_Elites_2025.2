#include <stdio.h>
//#include "external.h"

const int MAX_LIMIT = 100;
int g_initialized = 42;
int g_uninitialized;
volatile int g_volatile_flag = 1;

int g_numbers[5] = {10, 20, 30, 40, 50};
int g_first_number = 0;

union Data {
    int i;
    float f;
    char str[20];
};

union Data g_data;

struct Point {
    int x;
    int y;
};

struct Point g_point = {1, 2};

int internal_add(int a, int b) {
    return a + b;
}

int choose_value(int code) {
    switch (code) {
        case 1:
            return 100;
        case 5:
            return 500;
        default:
            return -1;
    }
}

int sum_array_for(void) {
    int total = 0;
    int i;

    for (i = 0; i < 5; i++) {
        total += g_numbers[i];
    }

    return total;
}

int countdown_while(int start) {
    int count = start;

     while (count > 0) {
        count--;
    }

    return count;
}

int main(void) {
    int local_var = 5;
    static int local_static = 10;

    g_first_number = g_numbers[0];
    g_data.i = 1234;
    g_point.x = 7;
    g_point.y = 9;

    if (local_var < local_static) {
        local_var = internal_add(local_var, 1);
    } else {
        local_var = internal_add(local_var, -1);
    }

    int switched = choose_value(local_var);
    int internal_result = internal_add(local_var, switched);
    int external_result = external_multiply(internal_result, g_initialized);

    if (g_volatile_flag) {
        g_uninitialized = external_result + sum_array_for();
    } else {
        g_uninitialized = external_result;
    }

    int remaining = countdown_while(3);

    printf("MAX_LIMIT=%d, g_uninitialized=%d, first=%d, point=(%d,%d), remaining=%d\n",
           MAX_LIMIT,
           g_uninitialized,
           g_first_number,
           g_point.x,
           g_point.y,
           remaining);

    return 0;
}

