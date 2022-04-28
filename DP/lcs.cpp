//Longest common subsequence
/*  s1 = "ABCD"
    s2 = "ABEDG"

    o/p: "ABD" - 3
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int lcs(string s1, string s2,int i,int j)
{
    //base case
    if(i==s1.length() or j==s2.length()) //i.e. strings of 0 length
    {
        return 0;
    }

    //rec cases
    if(s1[i] == s2[i])
    {
        return 1 + lcs(s1,s2,i+1,j+1);
    }

    int op1 = lcs(s1,s2,i+1,j);
    int op2 = lcs(s1,s2,i,j+1);

    return max(op1,op2);
}

//DP Bottom up
int lcs_DP(string s1, string s2,int i,int j,vector<vector<int>>&dp)
{
    //base case
    if(i==s1.length() or j==s2.length()) //i.e. strings of 0 length
    {
        return 0;
    }

    //loook up if state is already found
    if(dp[i][j]!=-1) return dp[i][j];

    //rec cases
    if(s1[i] == s2[i])
    {
        return dp[i][j] =  1 + lcs_DP(s1,s2,i+1,j+1,dp);
    }

    int op1 = lcs_DP(s1,s2,i+1,j,dp);
    int op2 = lcs_DP(s1,s2,i,j+1,dp);

    return dp[i][j] = max(op1,op2);
}

int main()
{
    string s1 = "ABCD";
    string s2 = "ABEDG";

    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1,vector<int>(n2,-1)); //n1xn2 vector array 


    cout<<lcs_DP(s1,s2,0,0,dp)<<endl;

    //for showing dp arrau
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}