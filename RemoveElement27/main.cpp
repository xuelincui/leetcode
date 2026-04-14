#include <iostream>
#include <vector>


using namespace std;

int removeElement(vector<int>& nums, int val)
{
    int m = 0;
    for (int n = 0; n < nums.size(); n++)
    {
        if (nums[n] != val)
        {
            nums[m] = nums[n];
            m++;
        }
    }

    return m;
}

int main()
{
    std::vector<int> nums={0,1,2,2,3,0,4,2};
    int m = removeElement(nums, 2);

    for (int n: nums)
        std::cout << n << endl;

    std::cout << m << std::endl;
    return 0;
}