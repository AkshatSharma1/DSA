#include<iostream>
#include<vector>
using namespace std;

void solve(int i,int j,vector<vector<int>> &m,int n,vector<string> &ans, string move, vector<vector<int>> &visited)
{
    if(i==n-1 and j==n-1)
    {
        ans.push_back(move);
        return;
    }

    //Cases

    // 1. Downward
    if(i+1<n and !visited[i+1][j] and m[i+1][j]==1)
    {
        visited[i][j] = 1;
        solve(i + 1, j, m, n,ans, move + 'D', visited);
        //Backtrack
        visited[i][j] = 0;
    }

    // 2. Left
    if(j-1>=0 and !visited[i][j-1] and m[i][j-1]==1)
    {
        visited[i][j] = 1;
        solve(i,j-1,m,n,ans,move+'L', visited);
        visited[i][j] = 0;
    }

    // 3. Right
    if(j+1<n and !visited[i][j+1] and m[i][j+1]==1)
    {
        visited[i][j] = 1;
        solve(i,j+1,m,n,ans,move+'R', visited);
        visited[i][j] = 0;
    }

    // 4. Up
    if(i-1>=0 and !visited[i-1][j] and m[i-1][j]==1)
    {
        visited[i][j] = 1;
        solve(i-1,j,m,n,ans,move+'U', visited);
        visited[i][j] = 0;
    }
}

vector<string> findPath(vector<vector<int>> &m,int n)
{
    vector<string> ans;
    //Visited vector 
    vector<vector<int>> visited(n,vector<int>(n,0));

    if(m[0][0]==1)
    {
        solve(0, 0, m, n,ans,"",visited);
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> vec;
    for (int i = 0;i<n;i++)
    {
        vector<int> v1;
        for(int j = 0;j<m;j++)
        {
            int inp;
            cin >> inp;
            v1.push_back(inp);
        }
        vec.push_back(v1);
    }

    vector<string> result;

    result = findPath(vec, n);

    for(int i = 0;i<result.size();i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}