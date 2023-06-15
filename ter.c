#include <stdio.h>
int ternary(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    
    int result = ternary(a,b);
    printf("Using the ternary operator, the biggest number is: %d\n", result);
    
    return 0;
}
