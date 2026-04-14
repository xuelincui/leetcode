#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int majorityElement(vector<int>& nums)
{
    std::sort(nums.begin(), nums.end());

    return nums[nums.size()/2];
}

int main()
{
    std::vector<int> nums = {1,1,1,2,2,1,1,4,4,4,4,5,5,1,1,1,1,1};

    int m = majorityElement( nums);

    std::cout << m << std::endl;
    return 0;
}
