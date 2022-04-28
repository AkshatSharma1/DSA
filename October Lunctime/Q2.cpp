#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {

        long long A, B, P, Q;
        cin >> A >> B >> P >> Q;

        long long div1 = 0, div2 = 0;
        long long res = 0;

        div1 = P / A;
        div2 = Q / B;

        res = abs(div2 - div1);

        if(res==0 or res==1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        cout << 9 / 5;
    }
    return 0;
}