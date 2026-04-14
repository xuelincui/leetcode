#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    std::unordered_map<int, int> uMap;

    for(int i = 0; i < nums.size(); i++)
    {
        int compliment = target - nums[i];

        if(uMap.find(compliment) != uMap.end())
        {
            return {uMap[compliment], i};
        }

        uMap[nums[i]] = i;
    }

    return {};
}

int main()
{


    vector<int> nums = {3,2,4};
    int target = 6;

    vector<int> v = twoSum(nums,  target);

    for (int n:v)
        std::cout<<n<<" ";
    std::cout<<std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}