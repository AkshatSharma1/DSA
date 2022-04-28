#include<iostream>
#include<vector>
using namespace std;
    vector<int> is_prime(10000001, 1);
    vector<int> counter(10000001, 0);

    int primeSieve()
    {
        is_prime[0] = is_prime[1] = 0;
        for (int i = 2; i <= 10000000; i++)
        {
            if (is_prime[i] && (long long)i * i <= 10000000)
            {
                for (int j = i * i; j <= 10000000; j += i)
                    is_prime[j] = 0;
            }
        }

        for (int i = 2;i<=10000000; i++)
        {
            counter[i] = counter[i - 1] + is_prime[i];
        }
}

int helper()
{
    long long x, y;
    cin >> x >> y;
    
    long long res = y - x;
    res = res - (counter[y] - counter[x]);

    if(x==1 and y==2)
    {
        cout << "1" << endl;
        
    }
    else if(x==1 and y==3)
    {
        cout << "2" << endl;
        
    }
    else if(x==2 and y==3)
    {
        cout << "1" << endl;
        
    }

    if(is_prime[x+1])
    {
        res = res + 1;
    }

    cout<<res << endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    primeSieve();
    int t;
    cin >> t;
    while(t--) {
        helper();
    }
    return 0;
}