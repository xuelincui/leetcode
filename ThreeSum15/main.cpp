#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> ret;
    std::sort(nums.begin(), nums.end());

    int len_nums = nums.size();

    int n = 0;

    while (nums[n] <= 0 && n < len_nums-2)
    {
        if (n > 0 && nums[n - 1] == nums[n])
        {
            n++;
            continue;
        }

        int l = n+1;
        int r = len_nums-1;

        while (l < r)
        {
            int sum = nums[n] + nums[l] + nums[r];

            if (sum > 0)
            {
                r--;
            }
            else if (sum < 0)
            {
                l++;
            }
            else
            {
                vector<int> v = {nums[n], nums[l], nums[r]};
                ret.push_back(v);

                l++;
                r--;

                while (l<r && nums[l] == nums[l-1])
                    l++;

                while (l<r && nums[r] == nums[r+1])
                    r--;
            }
        }

        n++;
    }

    return ret;

}
int main()
{
    vector nums = {2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10};

    vector<vector<int>> v = threeSum( nums);

    for (vector<int>& vec : v)
    {
        for (int & num : vec)
            std::cout<<num <<' ';

        std::cout<<std::endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}