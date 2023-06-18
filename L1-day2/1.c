#include <stdio.h>

int main() {
    double x = 0.7;
    unsigned long long* p = (unsigned long long*)&x;
    unsigned long long exponent = (*p >> 52) & 0x7FF;

    printf("Exponent in hexadecimal: 0x%llX\n", exponent);
    printf("Exponent in binary: 0b");
    
    for (int i = 11; i >= 0; i--) {
        printf("%d", (exponent >> i) & 1);
    }

    return 0;
}
