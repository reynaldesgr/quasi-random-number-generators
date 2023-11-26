#include <stdio.h>
#include <math.h>

// Séquence de van der Corput
double van_der_corput(int n, int base) 
{
    double result = 0.0;
    double f = 1.0 / base;
    while (n > 0) {
        result += (n % base) * f;
        n /= base;
        f /= base;
    }
    return result;
}

// Suite de Halton en deux dimensions
void halton_sequence(int n, double *x, double *y) 
{
    x[0] = van_der_corput(n, 2); // Base 2 pour la dimension 1
    y[0] = van_der_corput(n, 3); // Base 3 pour la dimension 2
}

void main() 
{
    const int N = 100;
    double x[N], y[N];

    for (int n = 1; n <= N; ++n) 
    {
        halton_sequence(n, &x[n-1], &y[n-1]);
    }

    printf("Points de la suite de Halton en 2D:\n");
    for (int i = 0; i < N; ++i) 
    {
        printf(" %d: (%lf, %lf)\n", i + 1, x[i], y[i]);
    }

    return;
}
