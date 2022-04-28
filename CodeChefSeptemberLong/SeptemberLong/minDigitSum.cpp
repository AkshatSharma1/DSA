#include <bits/stdc++.h>
#define ll unsigned long long int
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
        
        ll n,r;
        cin >> n >> r;

        ll temp_number, sum, sum2, minimum_value;
        sum2 = INT_MAX;
        minimum_value = 0;
        ll l = 2;

        //Base Case When n lies below or between range
        if (n >= 2 and n <= r) {
            cout << n <<"\n";
            continue;
        }
        if (n < 2) {
            cout << 2 <<"\n";
            continue;
        }
        /* optimize */
        while (2 < r && n / r < r) {
            ll d1 = n % r;
            ll d2 = n / r;
            if (sum2 > d1 + d2) {
                sum2 = d1 + d2;
                minimum_value = r;
            }
            r = n / (d2 + 1);
        }
        while (l <= r) {
            temp_number = n;
            sum = 0;
            while(1) 
            {
                if (temp_number < l) {
                    sum += temp_number;
                    if (sum < sum2) {
                        minimum_value = l;
                        sum2 = sum;
                    }
                    break;
                }
                sum += temp_number % l;
                temp_number /= l;
                if (sum >= sum2)
                    break;
            }
            l++;
        }
        cout << minimum_value << "\n";
    }
    return 0;
}