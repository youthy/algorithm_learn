#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int maxProfit(int *prices, int pricesSize)
{
    int min_price = INT_MAX;
    int max_profit = 0;
    for(int i = 1; i < pricesSize; i++)
    {
        if(prices[i] > prices[i - 1])
            max_profit += prices[i] - prices[i-1];
    }
    return max_profit;
}

int main(void)
{
    int prices[] = {1,7,5,3,4,2};
    printf("%d", maxProfit(prices, sizeof(prices)/sizeof(int)));
    return 0;
}