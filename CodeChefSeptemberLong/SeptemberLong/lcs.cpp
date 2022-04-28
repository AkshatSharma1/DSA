#include<iostream>
#include<vector>
using namespace std;

int dpLCS(string x,string y,int n,int m)
    {
        //Matrix
        int dp[n+1][m+1];
        
        //Initialisation
        for(int i=0;i<n+1;i++)
            dp[i][0] = 0;
        for(int j=0;j<m+1;j++)
            dp[0][j] = 0;
        
        //Fill up the matrix
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                //Chk cond
                if(x[i-1]==y[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    // dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    dp[i][j]=0;
            }
        }
        return dp[n][m];
    }
int main()
{
    string s1 = "11101";
    string s2 = "111001";

    int n1 = s1.length();
    int n2 = s2.length();

    // vector<vector<int>> dp(n1,vector<int>(n2,-1)); //n1xn2 vector array 


    cout<<dpLCS(s1,s2,n1,n2)<<endl;
    return 0;
}