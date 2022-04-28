#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        int n, m;
        cin >> n >> m;
        int limit = 3;

        vector<vector<int>> v(n);

        for (int i = 1; i < n;i++)
        {
            v[i] = {i + 1};
            cout << i <<" "<< i + 1 << endl;
            m--;
        }
        while(m>0)
        {
            for (int i = 1; i < limit;i++)
            {
                if(v[i][-1] < limit)
                {
                    v[i].push_back(limit);
                    cout << i << " " << limit << endl;
                    m--;
                    if(m==0)
                        break;
                }
            }
            limit++;
        }
    }
    return 0;
}