#include <stdio.h>

void main()
{
    double temp_fahrenheit = 70.0;
    double temp_celsius = (temp_fahrenheit - 32)*(5/9);
    printf("The temperature conversion is: %.2f F = %.2f C\n", temp_fahrenheit, temp_celsius);
}