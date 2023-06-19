#include <stdio.h>

void find_smallest_and_largest(int n, int nums[]) {
    int i, j;

    for (i = 0; i < n; i++) {
        int num = nums[i];
        int digit;
        int smallest = 9;
        int largest = 0;

        while (num > 0) {
            digit = num % 10;
            smallest = (digit < smallest) ? digit : smallest;
            largest = (digit > largest) ? digit : largest;
            num /= 10;
        }

        printf("For n%d = %d, ", i + 1, nums[i]);
        if (smallest == largest) {
            printf("Not Valid\n");
        } else {
            printf("Smallest digit: %d, Largest digit: %d\n", smallest, largest);
        }
    }
}

int main() {
    int n;
    int i;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    int nums[n];

    for (i = 0; i < n; i++) {
        printf("Enter n%d: ", i + 1);
        scanf("%d", &nums[i]);
    }

    find_smallest_and_largest(n, nums);

    return 0;
}
