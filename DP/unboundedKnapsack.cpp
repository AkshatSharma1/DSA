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
    int wt[] = {1, 50};
    int n = sizeof(wt)/sizeof(wt[0]);
    int val[] = {1, 30};
    int W = 100;

    cout << "Max Profit is: " << knapsack(wt, val, W, n);

    return 0;
}