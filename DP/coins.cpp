#include<iostream>
#include<climits>
using namespace std;

//Top Down Approach
int minCoins(int n,int coins[],int T,int dp[])
{
    //base case 
    if(n==0)
    {
        return 0;
    }
    //Look up 
    if(dp[n]!=0) return dp[n];

    //rec case
    int ans = INT_MAX;
    for(int i=0;i<T;i++)
    {
        if(n-coins[i]>=0)//denominations should be less than final money
        {
            int subProblem = minCoins(n-coins[i],coins,T,dp);
            ans = min(ans,subProblem + 1);
        }
    }
    
return dp[n] = ans;

}

//Bottom Up Approach 
int minCoinsBU(int n,int coins[],int T)
{
    int dp[100] = {0};
    //base case : // dp[0] = 0;

    //iterate over all states
    for(int i=1;i<=n;i++)
    {
        //we have multiple answer

        dp[i] = INT_MAX;//current answer

        for(int t=0;t<T;t++)
        {
            if(i-coins[t]>=0)
            {
                int subProblem = dp[i-coins[t]];
                dp[i] = min(dp[i],subProblem+1); //answer
            }
            
        }
    }
    return dp[n];
    
}

int main()
{
    int n = 15;//final money
    int coins[] = {1,7,10};
    int dp[100] = {0};
    int T = sizeof(coins)/sizeof(int);

    // cout<<minCoins(n,coins,T,dp);
    cout<<minCoinsBU(n,coins,T);

    return 0;
}