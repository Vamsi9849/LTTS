#include <stdio.h>

int bitop(int num, int oper_type) {
    int result = num;
    switch (oper_type) {
        case 1:
            result = result | 1;
            break;
        case 2:
            result &= ~(1 << 31);
            break;
        case 3:
            result ^= 1 << 15;
            break;
        default:
            printf("Invalid operation\n");
            break;
    }
    return result;
}

int main() {
    int num, oper_type;
    scanf("%d", &num);
    scanf("%d", &oper_type);
    int result = bitop(num, oper_type);
    printf("%d\n", result);
    return 0;
}
