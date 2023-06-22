#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

void calculateVolumeAndSurfaceArea(struct Box* boxPtr, double* volumePtr, double* surfaceAreaPtr) {
    double length = (*boxPtr).length;
    double width = boxPtr->width;
    double height = boxPtr->height;

    *volumePtr = length * width * height;

    *surfaceAreaPtr = 2 * (length * width + length * height + width * height);
}

int main() {
    struct Box myBox;
    printf("Enter the length of box:\n");
    scanf("%d",myBox.length);
    printf("Enter the width of box:\n");
    scanf("%d",myBox.width);
    printf("Enter the height of box:\n");
    scanf("%d",myBox.height);
    struct Box* boxPtr = &myBox;

    double volume, surfaceArea;
    double* volumePtr = &volume;
    double* surfaceAreaPtr = &surfaceArea;

    calculateVolumeAndSurfaceArea(boxPtr, volumePtr, surfaceAreaPtr);

    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);

    return 0;
}