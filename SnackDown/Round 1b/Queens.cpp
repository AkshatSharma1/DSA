#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row,int col,int n,vector<string>&board) {
            // 1. Checking for upper diagonal
        int origRow = row;
        int origCol = col;
        while(row>=0 && col>=0)
        {
            if()
            row--;
            col--;
        }
        
        // 2. Checking the staright axis
        row = origRow;
        col = origCol;
        while(col>=0)
        {
            if(board[row][col]=='Q')
            {
                return false;
            }
            col--;
        }
        
        // 3. Checking the left lower diagonal
        row = origRow;
        col = origCol;
        while(col>=0 && row < n)
        {
            if(board[row][col]=='Q')
            {
                return false;
            }
            col--;
            row++;
        }
        
        return true;
}

void solve(int col, vector<string> &board,int n,vector<vector<string>> &res)
{
        //Base case(ending condition)
        if(col==n)//fully traversed
        {
            res.push_back(board);
            return;
        }
        
        //Check for every row if we can place a queen there or not
        for(int row = 0;row<n;row++)
        {
            //Check if safe to place
            if (isSafe(row,col,n,board))
            {
                //Put Queen
                board[row][col] = 'Q';
                
                //rec call
                //for next queen go to next col & next row
                solve(col+1,board,n,res);
                
                //Backtrack if the result generated is invalid/not allowed
                board[row][col] = '.';
            }
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<vector<string>> result;
        //Fill borad
        vector<string> board(n);
        string s(n,'.');
        
        //For each row
        for(int i=0;i<n;i++)
        {
            board[i] = s;
        }

        solve(0,board,n,result);


    }
}