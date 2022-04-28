#include<iostream>
#include<climits>
using namespace std;

//rec way
int rodCut(int prices[],int n)
{
    //base case
    if(n<=0)
    {
        return 0;
    }

    //rec case
    int ans = INT_MIN;

    for(int i=0;i<n;i++)
    {
        int cut = i+1;
        
        int curr_ans = prices[i] + rodCut(prices,n-cut);

        ans = max(ans,curr_ans);
    }

    return ans;
}

//bottom up 
int maxProfit(int prices[],int n)
{
    int dp[n+1];
    dp[0]=0;

    for(int len=1;len<=n;len++)
    {
        int ans = INT_MIN;
        for(int i=0;i<len;i++)
        {
            int cut = i+1;
            int curr_ans = prices[i] + dp[len-cut];
            ans = max(ans,curr_ans);
        }
        dp[len] = ans;
    }
    return dp[n];
}

int main()
{
    int prices[] = {1,5,8,9,10,17,17,20};
    int n = sizeof(prices)/sizeof(prices[0]);

    cout<<"Max Profit: "<<rodCut(prices,n);
    cout<<"\nMax Profit: "<<maxProfit(prices,n);
    return 0;

}