class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false);             // Columns under attack
        vector<bool> diag1(2 * n - 1, false);    // "row + col" diagonals
        vector<bool> diag2(2 * n - 1, false);    // "row - col + n -1" diagonals
        backtrack(0, n, board, cols, diag1, diag2, solutions);
        return solutions;
    }

private:
    void backtrack(int row, int n, vector<string>& board,
                   vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2,
                   vector<vector<string>>& solutions) {
        if (row == n) {
            solutions.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (cols[col] || diag1[row + col] || diag2[row - col + n - 1]) {
                continue; // Not safe
            }

            // Place queen
            board[row][col] = 'Q';
            cols[col] = true;
            diag1[row + col] = true;
            diag2[row - col + n - 1] = true;

            backtrack(row + 1, n, board, cols, diag1, diag2, solutions);

            // Remove queen (backtrack)
            board[row][col] = '.';
            cols[col] = false;
            diag1[row + col] = false;
            diag2[row - col + n - 1] = false;
        }
    }
};