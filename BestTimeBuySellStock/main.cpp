#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices)
{
    int max_profit = 0;
    int min_price = prices[0];

    for (int r = 1; r < prices.size(); r++)
    {
        int profit = prices[r] - min_price;
        if (max_profit < profit)
        {
            max_profit = profit;
        }

        if (prices[r] < min_price)
        {
            min_price = prices[r];
        }
    }

    return max_profit;
}

int main()
{
    std::vector stock_price = {9,2,4,3,1,8,5};

    int max_profit = maxProfit(stock_price);

    std::cout <<max_profit;

    return 0;
}
