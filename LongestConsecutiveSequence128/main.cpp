#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int longestConsecutive(vector<int>& nums)
{
    // Handle empty array
    if (nums.empty())
        return 0;

    // Insert all numbers into a hash set for O(1) lookups
    std::unordered_set numSet(nums.begin(), nums.end());

    int longestStreak = 0;

    // Iterate through each number in the array
    for (int num : numSet)
    {
        // Only start checking sequences at the start of a sequence
        // If num-1 exists, num is not the start of a sequence
        if (numSet.find(num-1) == numSet.end())
        {
            int currentNum = num;
            int currentStreak = 1;

            // Count consecutive numbers
            while (numSet.find(currentNum+1) != numSet.end())
            {
                currentNum++;
                currentStreak++;
            }

            longestStreak = max(longestStreak, currentStreak);
        }
    }

    return longestStreak;
}

int main()
{
    vector<int> nums = {100,4,200,1,3,2};

    int n = longestConsecutive( nums);


    std::cout << n << std::endl;
    return 0;
}