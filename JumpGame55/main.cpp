#include <iostream>

#include <vector>

using namespace std;

bool canJump(vector<int>& nums)
{
   // work backward; if the current (final) post is reachable from
   // the previous post, then set previous post to be the current/final
    int goal = nums.size()-1;

    for (int n = goal; n >= 0; n--)
    {
        if (n + nums[n] >= goal)
        {
            goal = n;
        }
    }

    if (goal == 0)
        return true;

    return false;
}
int main()
{
    std::vector<int> nums = {2,3,2,1,2,0,4};

    bool can_jump = canJump(nums);
    std::cout << can_jump << std::endl;
    return 0;
}
