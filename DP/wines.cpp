#include<iostream>
using namespace std;

//Top Down
int maxProfit(int wines[],int i,int j,int year)
{
    //base case
    //when starting>ending
    if(i>j)
    {
        return 0; //
    }

    //Rec Case 
    int op1 = wines[i]*year + maxProfit(wines,i+1,j,year+1);
    int op2 = wines[j]*year + maxProfit(wines,i,j-1,year+1);

    return max(op1,op2);
}

//Bottom Up
int maxProfitBU(int wines[],int i,int j,int year,int dp[][100])
{
    //base case
    //when starting>ending
    if(i>j)
    {
        return 0; //
    }

    //Return if dp[i][j] exist
    if(dp[i][j]!=0)
    {
        return dp[i][j];
    }
    
    int op1 = wines[i]*year + maxProfitBU(wines,i+1,j,year+1,dp);
    int op2 = wines[j]*year + maxProfitBU(wines,i,j-1,year+1,dp);

    return dp[i][j] = max(op1,op2);
}

int main()
{
    int wines[] = {2,3,5,1,4};
    int n = sizeof(wines)/sizeof(int);
    int year = 1;
    int dp[100][100] = {0};

    cout<<"Profit is: "<<maxProfitBU(wines,0,n-1,year,dp)<<endl;

    return 0;
}