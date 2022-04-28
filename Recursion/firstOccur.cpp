#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<vector<long long>> q;
    q.push_back({4,2});

    for (int i = 0;i<q.size();i++)
    {
        for (int j = 0;j<q.size();j++)
        {
            cout << q[i][j] << " ";
        }
    }
}