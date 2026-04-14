#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minPathSum(vector<vector<int>>& grid)
{
    int M = grid.size();
    int N = grid[0].size();

    for (int m = 0; m < M; m++)
    {
        for (int n = 0; n < N; n++)
        {
            if (m == 0 && n == 0)
                continue;

            int left_path_cost = INT_MAX;
            int up_path_cost = INT_MAX;

            if ( n != 0)
                left_path_cost = grid[m][n] + grid[m ][n - 1];

            if (m != 0)
                up_path_cost = grid[m][n] + grid[m - 1][n];

            grid[m][n] = min(left_path_cost, up_path_cost);
        }
    }

    return grid[M-1][N-1];
}

int main() {
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};

    int min_l = minPathSum(grid);
    std::cout <<min_l << std::endl;
    return 0;
}