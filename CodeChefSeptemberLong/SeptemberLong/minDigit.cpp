#include<bits/stdc++.h>
#define mp make_pair
#define ll long long

using namespace std;

ll digitSum(ll n,ll r)
{
    ll sum = 0;
    while(n)
    {
        ll ntemp = n;
        sum += ntemp % r;
        ntemp /= r;
    }
    return sum;
}

ll minValueOfB(ll n,ll r)
{
    ll result = 0;
    ll minimum = INT_MAX;
    if(2<=n and r>=n)
    {
        return n;
    }
    else if(2>n)
        return 2;
    
    else
    {
        auto sum_of_digits = digitSum(n,r);
        for(ll i = 2; i <= r;i++)
        {
            if(minimum >= sum_of_digits)
            {   
                minimum = sum_of_digits;
                result = i;
            }
        }
        return result;
    }
}

int main()
{
    //For fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;

    while(t--)
    {
        ll n, r;
        cin >> n >> r;

        cout << minValueOfB(n, r) << "\n";
    }
    return 0;
}