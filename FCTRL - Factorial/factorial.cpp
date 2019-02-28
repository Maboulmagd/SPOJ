#include <iostream>
//#include <stdlib.h>
#include <vector>

using namespace std;

int trailingZeros(int num)
{
    // First, we need to figure out all powers of five (5^k) that are less than the given positive integer
    
    vector<int> powersOfFive;

    for (int i = 5; i <= num; i *= 5)
    {
        powersOfFive.push_back(i);
    }

    // Now we need to figure out how many trailing zeros there are...

    int trailingZeros = 0;

    for (int power : powersOfFive)
    {
        trailingZeros += num / power;
    }

    return trailingZeros;
}

int main()
{
    int testCases;

    scanf("%d", &testCases);

    int i = 0;

    int num;
    while (i++ < testCases)
    {
        scanf("%d", &num);
        printf("%d\n", trailingZeros(num));
    }

    //printf("\n");
    return 0;
}