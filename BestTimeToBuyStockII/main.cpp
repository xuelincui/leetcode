#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices)
{
    int max_profit = 0;

    for (int r = 1; r < prices.size(); r++)
    {
        if (prices[r] > prices[r-1])
        {
            max_profit += prices[r] -  prices[r-1];
        }
    }

    return max_profit;
}

int main()
{
    std::vector stock_price = {7,1,5,3,6,4};

    int max_profit = maxProfit(stock_price);

    std::cout <<max_profit;

    return 0;
}
