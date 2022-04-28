#include<iostream>
using namespace std;

int ladders_topDown(int n,int k,int dp[])
{
    //base case 
    if(n==0)//no stairs 
    {
        return 1;
    }

    //Lookup for values in dp array
    if(dp[n]!=0)
    {
        return dp[n];
    }

    //Rec case
    int ways = 0;
    for(int i=1;i<=k;i++)//
    {
        if(n-i>=0)
        {
            ways+=ladders_topDown(n-i,k,dp);
        }
    }
    return dp[n] = ways;
}

int ladders_bottomUp(int n, int k)
{
    int dp[100]={0};
    dp[0]=1;//base case

    //iterate over dp array 
    for(int i=1;i<=n;i++)
    {
        dp[i]=0;//sum of prev k initialised to 0
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                dp[i]+=dp[i-j];
            }
            
        }
    }
    //if we want to print dp array
    for(int i=0;i<=n;i++)
    {
        cout<<dp[i]<<" ";
    }

    return dp[n];
}

//ladders bottom up optimized- O(K)
int ladders_optimized(int n,int k)
{
    int dp[100] = {0};

    dp[0] = dp[1] = 1;//base case

    for(int i=2;i<=k;i++)
    {
        dp[i] = 2*dp[i-1]; //cummulative sum
    }
    for(int i=k+1;i<=n;i++)
    {
        dp[i] = 2*dp[i-1] - dp[n-k-1];
    }

    return dp[n];
}

int main()
{
    // int dp[100] = {0};
    int n;cin>>n;
    int k; cin>>k;

    // cout<<"Ways: "<<ladders_topDown(n,k,dp);
    // cout<<"\nWays: "<<ladders_bottomUp(n,k);
    cout<<"\nWays: "<<ladders_optimized(n,k);

    return 0;
}

// 4 3
// 7