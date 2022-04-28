#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        int c,d;

        if(a==p and b==q)
        {
            cout << "0" << endl;
        }
        else if(((a+b)%2==0) and ((p+q)%2==0) )
        {
            cout << "2" << endl;
        }
        else
        {
            cout << "1" << endl;
        }
        
    }
    return 0;
}