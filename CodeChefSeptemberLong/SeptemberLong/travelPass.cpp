#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        string s;
        cin >> s;

        int result = 0;

        result = count(s.begin(), s.end(), '0') * a + count(s.begin(), s.end(), '1') * b;

        cout << result << endl;
    }
    return 0;
}