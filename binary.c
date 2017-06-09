#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned int binary_number;
const int N = sizeof(binary_number) * 8;

typedef struct list_of_binary_numbers_t {
    int length;
    binary_number element[N];
} list_of_binary_numbers;

bool bit_set(b, i) {
    if (b & (1<<i)) {
        return true;
    }
    return false;
}

list_of_binary_numbers * one_more_bit(binary_number b) {
    list_of_binary_numbers * l = malloc(sizeof(list_of_binary_numbers));
    if(!l) {
        perror("malloc()");
        exit(EXIT_FAILURE);
    }
    l->length = 0;
    for (int i=0; i<N; i++) {
        if (!bit_set(b, i)) {
            *l[l->length].element = b | (1<<i);
            l->length++;
        }
    }
    return l;
}

void blank_line(void) {
    printf("\n");
}

void display_binary(binary_number b) {
    for(int i = N - 1; i >= 0; i--) {
        // printf("%d", b & (1 << i) ? 1 : 0);
        if (bit_set(b, i)) {
            printf ("1");
        }
        else {
            printf ("0");
        }

        if(i % 4 == 0) {
            printf(" ");
        }
    }
    blank_line();
}

int main(void) {
    binary_number b = 10;
    display_binary(b);
    blank_line();
    // Every time you add a row, hook up the pointers.
    // Can I return a struct in this version of C?
    list_of_binary_numbers *l = one_more_bit(b);
    for (int i=0; i<l->length; i++) {
        display_binary(l->element[i]);
    }
    return EXIT_SUCCESS;
}

