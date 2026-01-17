class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 1. Check each Row
        for (int row = 0; row < 9; ++row) {
            vector<int> seen(9, 0);
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.') continue;
                
                int num = board[row][col] - '1';
                if (seen[num]) return false;
                seen[num] = 1;
            }
        }

        // 2. Check each Column
        for (int col = 0; col < 9; ++col) {
            vector<int> seen(9, 0);
            for (int row = 0; row < 9; ++row) {
                if (board[row][col] == '.') continue;
                
                int num = board[row][col] - '1';
                if (seen[num]) return false;
                seen[num] = 1;
            }
        }

        // 3. Check each 3x3 Sub-box
        // We iterate through the top-left corner of each 3x3 box
        for (int rowStart = 0; rowStart < 9; rowStart += 3) {
            for (int colStart = 0; colStart < 9; colStart += 3) {
                
                vector<int> seen(9, 0);
                // Iterate through the cells inside the 3x3 box
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        char digit = board[rowStart + i][colStart + j];
                        
                        if (digit == '.') continue;
                        
                        int num = digit - '1';
                        if (seen[num]) return false;
                        seen[num] = 1;
                    }
                }
            }
        }

        return true;
    }
};