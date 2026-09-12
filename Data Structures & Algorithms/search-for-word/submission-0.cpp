#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool solve(vector<vector<char>>& board, string& word,
               int i, int j, int k) {

        // Entire word matched
        if(k == word.size()) {
            return true;
        }

        // Out of bounds
        if(i < 0 || i >= board.size() ||
           j < 0 || j >= board[0].size()) {
            return false;
        }

        // Wrong character / already visited
        if(board[i][j] != word[k]) {
            return false;
        }

        // Mark visited
        char temp = board[i][j];
        board[i][j] = '#';

        // 4 directions
        bool found =
            solve(board, word, i + 1, j, k + 1) ||
            solve(board, word, i - 1, j, k + 1) ||
            solve(board, word, i, j + 1, k + 1) ||
            solve(board, word, i, j - 1, k + 1);

        // Backtrack
        board[i][j] = temp;

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {

                if(board[i][j] == word[0]) {
                    if(solve(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};