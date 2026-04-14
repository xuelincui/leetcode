#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int n = 0;      // base pointer

    for (int m = 0; m < nums.size(); m++)       // m is the sliding pointer
    {
        if (nums[n] != nums[m]) // if next number is the same then continue until it is different
        {
            n++;                // move base pointer to the 2nd position of the duplicates
            nums[n] = nums[m];  // fill the 2nd position with the different number
        }
    }

    nums.resize(n+1);   // note n is 1 shorter
    return n+1;
}

int main()
{
    std::vector<int> nums = {1,1,2};

    removeDuplicates(nums);

    for (int n: nums)
        std::cout << n << " ";

    return 0;
}
