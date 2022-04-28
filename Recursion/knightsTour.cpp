// #include<iostream>
// #include<vector>

// using namespace std;

// vector<int> pathRow1 = {2, 1, -1, -2, -2, -1, 1, 2};
// vector<int> pathCol1 = {1, 2, 2, 1, -1, -2, -2, -1};

// bool isValid(vector<vector<int>> &visited,int rowNew,int colNew) {

//     //Bounding condition  + already visited chk
//     if((rowNew>=0) && (rowNew<8) and (colNew>=0) && (colNew<8) and (visited[rowNew][colNew] == 0))
//     {
//         return true;
//     }

//     return false;
// }

// bool knightsTour(vector<vector<int>>&visited,int row,int col,int move)
// {
//     //Terinate cond
//     if(move==64) //when n=8
//     {
//         for (int i = 0; i < 8;i++)
//         {
//             for (int j = 0; j < 8;j++)
//             {
//                 cout << visited[i][j] << "  ,   ";
//             }
//             cout << endl;
//         }
//         return true;
//     }

//     else
//     {
//         for (int i = 0; i < pathRow1.size();i++) {
//             //New row 
//             int rowNew = row + pathRow1[i];
//             int colNew = col + pathRow1[i];

//             if(isValid(visited,rowNew,colNew))
//             {
//                 move++;
//                 visited[rowNew][colNew] = move;
//                 if(knightsTour(visited,rowNew,colNew,move))
//                 {
//                     return true;
//                 }

//                 //Backtrack
//                 // move--;
//                 visited[rowNew][colNew] = 0;
//             }
//         }
//     }

//     return false;
// }

// int main()
// {
//     int n=8;
//     vector<vector<int>> visited = {{0,0,0,0,0,0,0,0},
//                                    {0,0,0,0,0,0,0,0},
//                                    {0,0,0,0,0,0,0,0},
//                                    {0,0,0,0,0,0,0,0},
//                                    {0,0,0,0,0,0,0,0},
//                                    {0,0,0,0,0,0,0,0},
//                                    {0,0,0,0,0,0,0,0},
//                                    {0,0,0,0,0,0,0,0}};
                                

//     visited[0][0] = 1;//starting from first index

//     cout<<knightsTour(visited, 0, 0, 1);
// }

#include<bits/stdc++.h>
using namespace std;

#define n 8

int isValid(int newRow,int newCol,int mat[n][n])
{
    return (newRow>=0 && newRow<n && newCol>=0 && newRow<n && mat[newRow][newCol]==-1);
}

int knightsTour(int mat[n][n],int row,int col,int move,int pathRow1[8],int pathCol1[8])
{
    int newRow, newCol;
    //Terminate
    if(move==n*n){
        return 1;
    }
    
    for(int idx = 0; idx < 8;idx++) {
        newRow = row + pathRow1[idx];
        newCol = col + pathCol1[idx];

        if(isValid(newRow,newCol,mat))
        {
            mat[newRow][newCol] = move;

            //rec

            if(knightsTour(mat, newRow, newCol, move + 1, pathRow1, pathCol1)==1)
                return 1;

            //Backtrack
            else
                mat[newRow][newCol] = -1;
        }
    }
    return 0;
}

int main()
{
    int mat[n][n];
    memset(mat,-1,sizeof(mat)); //fill

    mat[0][0] = 0;//first move 

    int pathRow1[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    int pathCol1[8] = {2, -2, 2, -2, 1, -1, 1, -1};

    if(knightsTour(mat,0,0,1,pathRow1,pathCol1)==1)
    {
        for (int i = 0; i < n;i++)
        {
            for (int j = 0; j < n;j++)
            {
                cout << mat[i][j] << "  ";
            }
            cout << endl;
        }
    }

    return 0;
}

