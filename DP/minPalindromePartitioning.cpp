#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int low,int high) {
    while(low<high)
    {
        if(s[low]!=s[high])
            return false;

        low++;
        high--;
    }
    return true;
}

int static dp[1001][1001];

//Less optimized memoized 
int solve(string s,int i,int j)
{

    //If empty string or unit length, then 0 partitions needed to make palindrome
    if(i>=j)
        return 0;

    if(isPalindrome(s,i,j))
        return 0;
    
    if(dp[i][j]!=-1)
        return dp[i][j];

    int mn = INT_MAX;

    for (int k = i; k <= j - 1;k++)
    {
        int temp_ans = 1 + solve(s, i, k) + solve(s, k + 1, j);

        if(temp_ans<mn)
            mn = temp_ans;
    }

    return dp[i][j] = mn;
}

//More space optimized solution
int solveMemo(string s,int i,int j)
{

    //If empty string or unit length, then 0 partitions needed to make palindrome
    if(i>=j)
        return 0;

    if(isPalindrome(s,i,j))
        return 0;
    
    if(dp[i][j]!=-1)
        return dp[i][j];

    int mn = INT_MAX;
    int left;
    int right;

    for (int k = i; k <= j - 1;k++)
    {
        if(dp[i][k]!= -1)
        {
            left = dp[i][k];
        }
        else if(dp[i][k]==-1)
        {
            left = solveMemo(s, i, k);
            dp[i][k] = left;
        }
        else if(dp[k+1][j]!= -1)
        {
            right = dp[k + 1][j];
        }

        else
        {
            right = solveMemo(s, k + 1, j);
            dp[k + 1][j] = right;
        }

        int temp_ans = 1 + left + right;
        if(temp_ans < mn)
            mn = temp_ans;
    }

    return dp[i][j] = mn;
}


int main()
{
    string s = "aab";
    int n = s.length();
    memset(dp, -1, sizeof(dp));

    // cout << "Min partitions needed: " << solve(s, 0, n - 1) << endl;
    cout << "Min partitions needed: " << solveMemo(s, 0, n - 1) << endl;
}