#include<bits/stdc++.h>
using namespace std;

int main()
{
    // int rCenter = 1;
    // int cCenter = 1;
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;

        int matrix[n][m];

        for (int k = 1; k <= n;k++)
        {
            for (int l = 1; l <= n;l++)
            {
                matrix[k][l] = -1;
            }
        }

        map<int, int> m1;
        for (int rCenter = 1; rCenter <= n;rCenter++)
        {
            for (int cCenter = 1; cCenter <= m;cCenter++)
            {
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= m; j++)
                    {
                        if(matrix[i][j]!=0)
                        {
                            //calculate manhattan distance
                            int manhattan = abs(rCenter-i) + abs(cCenter-j);
                            if(manhattan > 0)
                                m1[manhattan]++;
                        }
                        matrix[rCenter][cCenter] = 0;
                    }
                }

            }
        }
        int c=0;
        vector<int> v;
        for (auto i : m1)
        {
            v.push_back(i.second);
        }

        for (int i = 0;i<v.size();i++)
        {
            cout<<v[i] * pow(31, i)<<"+";
            
        }

        
    }

    return 0;
}