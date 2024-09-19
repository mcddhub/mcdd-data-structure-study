//
// Created by mcdd2024 on 2024/9/18.
//


#include <stdio.h>

int fibonacci(int index);

int main() {
    printf("%d\n", fibonacci(0));
    printf("%d\n", fibonacci(1));
    printf("%d\n", fibonacci(2));
    printf("%d\n", fibonacci(3));
    printf("%d\n", fibonacci(4));
    printf("%d\n", fibonacci(5));

    return 0;
}

int fibonacci(const int index) { // 3 --> 2
    if (index == 0) {
        return 0;
    }
    if (index == 1) {
        return 1;
    }
    return fibonacci(index - 1) + fibonacci(index - 2);
}