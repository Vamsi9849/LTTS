#include <stdio.h>
struct Complex {
    double real;
    double imaginary;
};

void read(struct Complex* complexPtr) {
    printf("Enter the real part: ");
    scanf("%lf", &(complexPtr->real));

    printf("Enter the imaginary part: ");
    scanf("%lf", &(complexPtr->imaginary));
}

void write(struct Complex complex) {
    printf("Complex number: %.2lf + %.2lfi\n", complex.real, complex.imaginary);
}

struct Complex addComplex(struct Complex complex1, struct Complex complex2) {
    struct Complex result;
    result.real = complex1.real + complex2.real;
    result.imaginary = complex1.imaginary + complex2.imaginary;
    return result;
}

struct Complex multiplyComplex(struct Complex complex1, struct Complex complex2) {
    struct Complex result;
    result.real = complex1.real * complex2.real - complex1.imaginary * complex2.imaginary;
    result.imaginary = complex1.real * complex2.imaginary + complex1.imaginary * complex2.real;
    return result;
}

int main() {
    struct Complex complex1, complex2;

    printf("Reading Complex Number 1:\n");
    read(&complex1);

    printf("\nReading Complex Number 2:\n");
    read(&complex2);

    printf("\nComplex Number 1:\n");
    write(complex1);

    printf("\nComplex Number 2:\n");
    write(complex2);

    struct Complex sum = addComplex(complex1, complex2);
    printf("\nSum of Complex Numbers:\n");
    write(sum);

    struct Complex product = multiplyComplex(complex1, complex2);
    printf("\nProduct of Complex Numbers:\n");
    write(product);

    return 0;
}