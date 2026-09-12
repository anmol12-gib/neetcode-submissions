#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<string>> ans;

    bool isSafe(int row, int col, vector<string>& board, int n) {

        int r = row;
        int c = col;

        // upper diagonal left
        while(r >= 0 && c >= 0) {

            if(board[r][c] == 'Q')
                return false;

            r--;
            c--;
        }

        r = row;
        c = col;

        // upper diagonal right
        while(r >= 0 && c < n) {

            if(board[r][c] == 'Q')
                return false;

            r--;
            c++;
        }

        r = row;

        // same column
        while(r >= 0) {

            if(board[r][col] == 'Q')
                return false;

            r--;
        }

        return true;
    }

    void solve(int row, vector<string>& board, int n) {

        // base case
        if(row == n) {

            ans.push_back(board);

            return;
        }

        for(int col = 0; col < n; col++) {

            if(isSafe(row, col, board, n)) {

                board[row][col] = 'Q';

                solve(row + 1, board, n);

                // backtrack
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        solve(0, board, n);

        return ans;
    }
};