#include <iostream>

using namespace std;

int numOfDigits(int n)
{
    int digits = 0;

    while (n > 0)
    {
        n /= 10;
        digits++;
    }

    return digits;
}

int reverseNumber(int n)
{
    int res = 0;

    while (n > 0)
    {
        res *= 10;
        res += n % 10;
        n /= 10;
    }

    return res;
}

int addReverse(int& a, int& b)
{
    // note: 0 is not a positive integer, and a and b are both guaranteed to be positive integers...
    if (a == 0) return b;
    else if (b == 0) return a;

    int aNumOfDigits = numOfDigits(a);
    int bNumOfDigits = numOfDigits(b);

    // printf("before aNumOfDigits: %d\n", aNumOfDigits);
    // printf("before bNumOfDigits: %d\n", bNumOfDigits);

    while (aNumOfDigits > bNumOfDigits)
    {
        b *= 10;
        bNumOfDigits++;
    }

    while (aNumOfDigits < bNumOfDigits)
    {
        a *= 10;
        aNumOfDigits++;
    }

    // printf("after aNumOfDigits: %d\n", aNumOfDigits);
    // printf("after bNumOfDigits: %d\n", bNumOfDigits);

    // a = reverseNumber(a);
    // b = reverseNumber(b);

    // printf("a: %d\n", a);
    // printf("b: %d\n", b);

    return reverseNumber(reverseNumber(a) + reverseNumber(b));
}

int main()
{
    int testCases;
    scanf("%d", &testCases);

    int a;
    int b;

    while (testCases-- > 0)
    {
        scanf("%d", &a);
        scanf("%d", &b);

        printf("%d\n", addReverse(a, b));
    }

    return 0;
}