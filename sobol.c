#include <stdio.h>

unsigned int grayCode(unsigned int n) 
{
    return n ^ (n >> 1);
}


void propagateValues(const size_t dimension, const unsigned int *x_n_minus_1, unsigned int *x_n, unsigned int n) 
{
    unsigned int gray = grayCode(n);

    for (size_t i = 0; i < dimension; ++i) 
    {
        x_n[i] = x_n_minus_1[i] ^ gray;
    }
}

int main() {
    const size_t dimension = 3;  // Nombre de dimensions
    const unsigned int n_minus_1 = 5;  // Valeur de n - 1
    unsigned int x_n_minus_1[] = {1, 2, 3};  // Valeurs de xn-1 pour chaque dimension

    unsigned int x_n[dimension];

    // Valeurs de xn-1 à xn en utilisant le code de Gray
    propagateValues(dimension, x_n_minus_1, x_n, n_minus_1 + 1);

    // Affichage des résultats
    printf("xn-1: ");
    for (size_t i = 0; i < dimension; ++i) {
        printf("%u ", x_n_minus_1[i]);
    }

    printf("\n");

    printf("xn  : ");
    for (size_t i = 0; i < dimension; ++i) {
        printf("%u ", x_n[i]);
    }

    printf("\n");

    return 0;
}
