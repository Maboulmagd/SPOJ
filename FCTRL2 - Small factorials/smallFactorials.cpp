#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 500

void multiply(int digits[], int& digitsSize, int& i)
{
    int carry = 0;

    for (int index = MAX_SIZE - 1; index >= MAX_SIZE - digitsSize; index--)
    {
        int mul = digits[index] * i + carry;

        digits[index] = mul % 10;

        carry = mul / 10;
    }

    int x = digitsSize+1;

    while(carry > 0)
    {
        //printf("x: %d\n", x);
        digits[MAX_SIZE - x++] = carry % 10;
        carry /= 10;
        digitsSize++;
        //printf("digitsSize: %d\n", digitsSize);
    }
}

void smallFactorial(int num)
{
    int digits[MAX_SIZE];

    digits[MAX_SIZE-1] = 1;

    int digitsSize = 1;

    for (int i = 2; i <= num; i++)
    {
        multiply(digits, digitsSize, i);
    }

    for (int i = MAX_SIZE - digitsSize; i < MAX_SIZE; i++)
    {
        printf("%d", digits[i]);
    }
    
    printf("\n");
}

int main()
{
    int testCases;

    scanf("%d", &testCases);

    int num;

    while (testCases-- > 0)
    {
        scanf("%d", &num);
        smallFactorial(num);
    }

    return 0;
}