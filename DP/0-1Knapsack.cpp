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
        for(int j=0; j<W+1; j++)
        {
            if(i==0 or j==0)
                dp[i][j] = 0;
        }
    }

    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<W+1; j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j] = max(val[i - 1] + dp[i-1][j-wt[i-1]] , dp[i-1][j]);
            }

            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    //Fill the remaining with max answers 
    // for(int i=1; i<n+1; i++)
    // {
    //     for(int j=1; j<W+1; j++)
    //     {
    //         if(wt[i-1]<=W)
    //         {
    //             dp[i][j] = max(val[i - 1] + knapsack(wt, val, W - wt[i - 1], n - 1), knapsack(wt, val, W, n - 1));
    //         }

    //         else
    //         {
    //             dp[i][j] = knapsack(wt, val, W, n - 1);
    //         }
    //     }
    // }

    return dp[n][W];//last cell
}

int main()
{
    //Weight and value array
    int wt[] = {1, 3, 4, 5};
    int n = sizeof(wt)/sizeof(wt[0]);
    int val[] = {1, 4, 5, 7};
    int W = 7;

    cout << "Max Profit is: " << knapsack(wt, val, W, n);

    return 0;
}