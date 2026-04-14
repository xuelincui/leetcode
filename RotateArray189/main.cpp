#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k)
{
    int N = nums.size();

    k = k % N;

    if (k == 0 || N <= 1)
        return;

    vector<int> temp= nums;

    for (int i = 0; i < N; i++)
    {
        int m = (i + k)%N;
        nums[m] = temp[i];
    }
}

int main() {

    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;

    rotate( nums, k);

    for (int i: nums)
        std::cout << i<< std::endl;
    return 0;
}