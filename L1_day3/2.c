#include <stdio.h>

void print_bits(int num) {
    int i;
    int mask = 1 << 31; 

    for (i = 0; i < 32; i++) {
        int bit = (num & mask) != 0; 
        printf("%d", bit);
        mask >>= 1; 
    }

    printf("\n");
}

int main() {
    int num;

    printf("Enter a 32-bit integer: ");
    scanf("%d", &num);

    printf("Bits: ");
    print_bits(num);

    return 0;
}
