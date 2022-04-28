/*
Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if the length of the rod is 8 and the values of different pieces are given as the following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20
*/

//Top down approach
#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[],int val[],int W,int n)
{
    //Making a dp array of size n+1 and w+1;
    int dp[n + 1][W + 1];
    
    //Initialise the dp array 
    for(int i=0; i<n+1; i++)
    {
        dp[i][0] = 0;
    }
    for(int j=0; j<W+1; j++)
    {
        dp[0][j] = 0;
    }

    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<W+1; j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j] = max(val[i - 1] + dp[i][j-wt[i-1]] , //dp[i][j-wt[i-1]] here dp[i] and not i-1 bcoz we can take i again as it is accepted
                                 dp[i-1][j]);
            }

            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];//last cell
}

int main()
{
    //Weight and value array
    int l[] = {1, 2,3,4,5,6,7,8};
    int n = sizeof(l)/sizeof(l[0]); //size of arr
    int price[] = {1, 5,8,9,10,17,17,20};
    int length = 8;//length of rod given

    cout << "Max Profit is: " << knapsack(l, price, length, n);

    return 0;
}