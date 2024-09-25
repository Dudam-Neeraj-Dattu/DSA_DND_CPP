#include <bits/stdc++.h>

using namespace std;

void boxIndexGiver(int &n, int &a, int &b)
{
    if (n >= 0 && n <= 2)
    {
        a = 0;
        b = 2;
    }
    else if (n >= 3 && n <= 5)
    {
        a = 3;
        b = 5;
    }
    else
    {
        a = 6;
        b = 8;
    }
}

bool isSafe(vector<vector<char>> &board, char ch, int row, int col)
{
    // row check
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == ch)
        {
            return false;
        }
    }

    // col check
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == ch)
        {
            return false;
        }
    }

    // miniGrid check
    int r1 = 0, r2 = 0, c1 = 0, c2 = 0;
    boxIndexGiver(row, r1, r2);
    boxIndexGiver(col, c1, c2);
    for (int i = r1; i <= r2; i++)
    {
        for (int j = c1; j <= c2; j++)
        {
            if (board[i][j] == ch)
            {
                return false;
            }
        }
    }
    return true;
}



bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (isSafe(board, k, i, j)) {
                            board[i][j] = k;
                            if (solve(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

void solveSudoku(vector<vector<char>>& board) { solve(board); }

int main()
{
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
 {'6','.','.','1','9','5','.','.','.'},
 {'.','9','8','.','.','.','.','6','.'},
 {'8','.','.','.','6','.','.','.','3'},
 {'4','.','.','8','.','3','.','.','1'},
 {'7','.','.','.','2','.','.','.','6'},
 {'.','6','.','.','.','.','2','8','.'},
 {'.','.','.','4','1','9','.','.','5'},
 {'.','.','.','.','8','.','.','7','9'}};


    solveSudoku(board);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}