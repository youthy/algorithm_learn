#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int maxProfit(int *price, int pricesSize)
{
    int min_price = INT_MAX;
    int max_profit = 0;
    for(int i = 0; i < pricesSize; i++)
    {
        min_price = price[i] > min_price? min_price:price[i];
        max_profit = price[i] - min_price > max_profit? price[i] - min_price : max_profit;
    }
    return max_profit;
}

int main(void)
{
    int prices[] = {1,7,5,3,4,2};
    printf("%d", maxProfit(prices, sizeof(prices)/sizeof(int)));
}