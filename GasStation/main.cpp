#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int idx = 0;
    int sum = 0;
    std::vector<int> diff(gas.size(), 0);

    for (int n = 0; n <cost.size(); n++)
    {
        diff[n] = gas[n] - cost[n];
        sum += diff[n];
    }

    if ( sum < 0)
    {
        idx = -1;
    }
    else
    {
        int total = 0;

        // because of there is/must be a unique solution
        for (int n = 0; n < cost.size(); n++)
        {
            total += diff[n];

            if (total < 0)
            {
                total = 0;
                idx = n + 1;
            }
        }
    }

    return idx;
}

int main()
{
    std::vector<int> gas = {2,3,4};
    std::vector<int> cost = {3,4,3};

    int idx = canCompleteCircuit( gas,  cost);

    std::cout << idx << std::endl;
    return 0;
}