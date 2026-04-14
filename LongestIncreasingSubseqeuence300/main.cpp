#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int lengthOfLIS(vector<int>& nums)
{
    int N = nums.size();
    vector<int> dp(N, 1);

    for (int i = N-2; i >=0; i--)
    {
        for (int j = i+1; j < N; j++)
        {
            if (nums[i] < nums[j])
                dp[i] = std::max(dp[i], dp[j]+1);
        }
    }

    auto ret = std::max_element(dp.begin(), dp.end());
    return *ret;
}
int main()
{
    vector<int> v = {1,9,2,5,3,7,101,18};
    int l = lengthOfLIS(v);

    std::cout << l << std::endl;
    return 0;
}