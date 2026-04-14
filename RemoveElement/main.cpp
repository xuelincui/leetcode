#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val)
{
    int k = 0;
    for (int n = 0; n < nums.size(); n++)
    {
        if (nums[n] != val)
        {
            nums[k] = nums[n];
            k++;
        }
    }

    nums.resize(k);

    return k;
}


int main()
 {
    std::vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int end = removeElement(nums,  val);

    for (int n: nums)
        std::cout << n << " ";

    return 0;
}