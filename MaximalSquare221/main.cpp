#include <iostream>
#include <vector>

using namespace std;

int maximalSquare(vector<vector<char>>& matrix)
{
    int M = matrix.size();
    int N = matrix[0].size();

    if (M == 0 || N == 0)
        return 0;

    vector<vector<int>> dp(M, vector<int>(N));

    int ans = 0;

    for (int m = 0; m < M; m++)
    {
        for (int n = 0; n < N; n++)
        {
            if (matrix[m][n] == '1')
            {
                dp[m][n] = 1;

                if (m != 0 && n != 0)
                {
                    dp[m][n] += std::min(std::min(dp[m - 1][n - 1], dp[m - 1][n]), dp[m][n - 1]);
                }

                ans = max(ans, dp[m][n]);
            }
        }
    }

    return ans * ans;
}


int main()
{
    vector<vector<char>> matrix =
{
{'1','0','1','0','0'},
{'1','0','1','1','1'},
{'1','1','1','1','1'},
{'1','0','0','1','0'}
};


    int ms = maximalSquare(matrix);


    std::cout << ms << std::endl;
    return 0;
}