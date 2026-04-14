#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums)
{
    int goal = nums.size() - 1;
    int num_jump = 0;

    // left and right of a window
    int l = 0;
    int r = 0;

    while (r < goal) // when right side not reaching the end of the sequence
    {
        int farthest = 0;

        for (int i = l; i <= r; i++)
        {
            farthest = std::max(farthest, nums[i] + i);
        }

        std::cout << "l=" << l <<"; r="<<r<< std::endl;

        l = r + 1;
        r = farthest;
        num_jump++;
    }

    return num_jump;

}

// Example 1:
//
// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2.
// Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:
//
// Input: nums = [2,3,0,1,4]
// Output: 2


int main()
{

    std::vector<int> nums = {2,3,1,1,4};

    int n = jump(nums);
    std::cout << n << std::endl;
    return 0;
}


