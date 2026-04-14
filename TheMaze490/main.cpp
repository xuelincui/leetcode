#include <iostream>
#include <vector>

using namespace std;

struct move_dir
{
    int row;
    int col;
};

// moving vectors {row, col}
move_dir up{-1, 0};
move_dir dn{ 1, 0};
move_dir lt{ 0, -1};
move_dir rt{ 0, 1};

vector<move_dir> moving_dir{ up, rt, dn, lt };

void printMaze(const vector<vector<int>>& maze)
{
    cout << endl;
    for (const auto& row : maze)
    {
        for (int cell : row)
        {
            cout << cell << ' ';
        }

        cout << endl;
    }
}

bool dfs( vector<vector<int>>& maze,
    int current_row,
    int current_col,
    int dest_row,
    int dest_col,
    vector<vector<int>>& visited)
{
    // destination found
    if (current_row == dest_row && current_col == dest_col)
    {
        return true;
    }

    // if this location has been visited already
    if (visited[current_row][current_col] == 1 )
    {
        return false;
    }

    int M = maze.size();
    int N = maze[0].size();

    // if we are here then this location is visited
    visited[current_row][current_col] = 1;
    printMaze(visited);

    // walk into all possible four directions
    for ( auto& dir : moving_dir)
    {
        int updated_row = current_row ;
        int updated_col = current_col;

        // if an unvisited location found; do recursive operation
        while ( updated_row + dir.row>= 0 && updated_col + dir.col >= 0 &&  // updated position did not hit lower bound
            updated_row + dir.row< M && updated_col  + dir.col< N &&
            maze[updated_row+ dir.row][updated_col + dir.col] == 0)
        {
            updated_row += dir.row;
            updated_col += dir.col;
        }

        if ( dfs( maze, updated_row, updated_col, dest_row, dest_col, visited))
        {
            return true;
        }
    }

    // no path found from this position
    return false;
}

bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination)
{
    vector<vector<int>> visited{ maze.size(), vector<int>(maze[0].size())};

    int current_row = start[0];
    int current_col = start[1];

    int dest_row = destination[0];
    int dest_col = destination[1];

    return dfs( maze,  current_row,current_col, dest_row, dest_col, visited);
}

int main()
{
    vector<vector<int>> maze =
        {
        {0,0,1,0,0},
        {0,0,0,0,0},
        {0,0,0,1,0},
        {1,1,0,1,1},
        {0,0,0,0,0},
        };

    vector<int> start = {0,4};      // {row, col}
    vector<int> destination = {4,4};

    bool ret = hasPath(maze, start, destination);

    std::cout << ret << std::boolalpha<< std::endl;
    return 0;
}
