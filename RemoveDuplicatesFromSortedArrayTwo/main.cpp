#include <iostream>
#include <vector>

using namespace std;
int removeDuplicates(vector<int>& nums)
{
    int l = 1;
    int count = 1; // count of duplicates

    for (int r = 1; r < nums.size(); r++)       // r
    {
        if (nums[r] == nums[r-1])
        {
            count++;
        }
        else
        {
            count = 1;
        }

        if (count <= 2)
        {
            nums[l] = nums[r];
            l++;
        }
    }

    nums.resize(l);
    return l;
}


int main()
{
    std::vector<int> nums ={0,0,1,1,1,1,2,3};

    removeDuplicates( nums);

    for (int n: nums)
        std::cout << n << " ";
    return 0;
}
