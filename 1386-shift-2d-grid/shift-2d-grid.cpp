class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        while (k--) {
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {

                    if (i == 0 && j == 0)
                        break;

                    if (j > 0)
                        swap(grid[i][j], grid[i][j - 1]);
                    else
                        swap(grid[i][j], grid[i - 1][m - 1]);
                }
            }
        }

        return grid;
    }
};