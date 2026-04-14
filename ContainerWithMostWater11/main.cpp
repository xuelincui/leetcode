#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height)
{
    int max_area = 0;

    int N = height.size();
    int l = 0;
    int r = N - 1;

    while (l < r)
    {
        int H = height[l] <= height[r] ? height[l] : height[r];
        int area = H * (r - l);

        if (area > max_area)
        {
            max_area = area;
        }

        if (height[l] <= height[r])
        {
            l++;
        }
        else
        {
            r--;
        }
    }

    return max_area;
}
int main() {
    std::vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout << maxArea(height) << endl;

    return 0;
}