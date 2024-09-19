//
// Created by mcdd2024 on 2024/9/18.
//

#include <stdio.h>
#include <math.h>

double reduce(int index);
/**
 * 1 + (1+sq2) + (1 + sq2 +sq3)
 * @return code status
 */
int main() {
    printf("%.3lf\n", reduce(2));
    printf("%.3lf\n", reduce(3) - sqrt(3));
    printf("%.3lf\n", reduce(3));
    return 0;
}

double reduce(const int index) {
    if (index == 0 || index == 1) {
        return 1;
    }
    return sqrt(index) + reduce(index - 1);
}
