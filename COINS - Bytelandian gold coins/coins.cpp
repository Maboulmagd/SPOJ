//#include<stdio.h>
//#include<stdlib.h>
#include<iostream>
//#include<unordered_map>

typedef long unsigned int ll;

using namespace std;

ll helperRecursion(ll coinMaxDollar[], ll coin)
{
    if (coin < 1000000)
    {
        /*coinMaxDollar[coin] = max(coin, coinMaxDollar[(coin/2)] + coinMaxDollar[(coin/3)] +
         coinMaxDollar[(coin/4)]);
        return coinMaxDollar[coin];*/

        return max(coin, coinMaxDollar[(coin/2)] + coinMaxDollar[(coin/3)] +
         coinMaxDollar[(coin/4)]);
    }

    // use this to pass the coin by reference, if needed
    // ll div2 = coin/2;
    // ll div3 = coin/3;
    // ll div4 = coin/4;

    return max(coin, helperRecursion(coinMaxDollar, coin/2) + helperRecursion(coinMaxDollar, coin/3)
    + helperRecursion(coinMaxDollar, coin/4));
}

ll maximumDollarAmount(ll& coin)
{
    // could use an array...
    //unordered_map<ll, ll> coinMaxDollar;

    ll coinMaxDollar[1000000];

    ll i;

    for (i = 0; i < 12; i++)
    {
        coinMaxDollar[i] = i;
    }

    for (; i < 1000000; i++)
    {
        /*ll maxDollars = max(i, coinMaxDollar[(i/2)] + coinMaxDollar[(i/3)]
         + coinMaxDollar[(i/4)]);
         coinMaxDollar[i] = maxDollars;*/

         coinMaxDollar[i] = max(i, coinMaxDollar[(i/2)] + coinMaxDollar[(i/3)]
          + coinMaxDollar[(i/4)]);
    }

    if (coin >= 1000000)
    {
        return helperRecursion(coinMaxDollar, coin);
    }

    return coinMaxDollar[coin];
}

int main()
{
    ll coin;

    // stops at new line character...
    while (scanf("%lu", &coin) != EOF)
    {
        printf("%lu\n", maximumDollarAmount(coin));
    }

    // Uncomment below, if want to use streaming, but this is slower???

    // while (cin >> coin)
    // {
    //     printf("%lu\n", maximumDollarAmount(coin));
    // }

    return 0;
}
