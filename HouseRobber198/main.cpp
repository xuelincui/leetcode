#include <iostream>
#include <vector>


using namespace std;


int rob(vector<int>& nums)
{
    int n = nums.size();

    if (n == 0)
        return 0;

    if (n == 1)
        return nums[0];

    std::vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);

    for (int j = 2; j < nums.size(); j++)
    {

        // at j th location, there are only two options:
        // 1. not robbing this house, there fore, dp[j] = dp[j-1]; inheritance
        // 2. robbing this house, and dp[j] = dp[j-2]+nums[j]
        dp[j] = std::max(dp[j - 1], dp[j - 2] + nums[j]);
    }

    return dp[n-1];
}

// Example 1:
//
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4

int main()
{
    std::vector<int> nums = {1,2,3,1,1, 100};

    int a = rob(nums);
    cout<<"max rob: " <<a<<endl;

    return 0;
}