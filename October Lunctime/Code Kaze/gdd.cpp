#include "bits/stdc++.h"

using namespace std;

#define fo(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define vi vector<int>

void helper(int T)

{

    int n;
    cin >> n;

    vi b, a;
    int no;
    bool c = true;

    fo(i, n)

    {

        cin >> no;
        b.pb(no);

        if (i > 0 && b[i - 1] % b[i] != 0)

        {

            c = false;
        }
    }

    if (c)

    {

        fo(i, n) cout << b[i] << ' ';

        cout << "\n";
    }

    else
        cout << "-1\n";
}

int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;

    cin >> t;

    while (t--)

    {
        helper(t);
    }

    return 0;
}