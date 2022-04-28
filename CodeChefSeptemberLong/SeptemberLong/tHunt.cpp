
// C++ program for the above approach
 
#include <bits/stdc++.h>
using namespace std;
 
// Function to calculate the maximum
// Manhattan distance
void MaxDist(vector<vector<pair<int, int> > >& A, int N,int M)
{
    // Vectors to store maximum and
    // minimum of all the four forms
    vector<int> V(N), V1(N);
 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M;j++) {
            V[i] = A[i][j].first + A[i][j].second;
            V1[i] = A[i][j].first - A[i][j].second;
        }
    }
 
    // Sorting both the vectors
    sort(V.begin(), V.end());
    sort(V1.begin(), V1.end());
 
    int maximum
        = max(V.back() - V.front(), V1.back() - V1.front());
 
    cout << maximum << endl;
}
 
// Driver Code
int main()
{
    int n = 2;
    int m = 3;

    // Given Co-ordinates
    vector<vector<pair<int, int>>> v;
    for (int i = 1; i <= n;i++) {
        vector<pair<int, int>> v1;
        for (int j = 1; j <= m;j++) {
            v1.push_back(make_pair(i,j));
        }
        v.push_back(v1);
    }

        // Function Call
        MaxDist(v,n,m);
 
    return 0;
}