#include <stdio.h>


double van_der_corput(int n) {
    double result = 0.0;
    double denom  = 1.0;

    while (n > 0) 
    {
        denom *= 2.0;
        result += (n % 2) / denom;
        n /= 2;
        printf(" denom : %.1f, result : %f, n : %d\n", denom, result, n);
    }
    printf("\n============================================\n");
    return result;
}

void main()
{
    int sequence_length = 10;
    for (int i = 0; i < sequence_length; ++i) 
    {
        double vdc_number = van_der_corput(i);
        //printf("\n%f\n", vdc_number);
    }
    return;
}