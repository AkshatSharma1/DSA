#include <bits/stdc++.h>
using namespace std;

// recursive implementation
int GcdOfArray(vector<int>& arr, int idx)
{
	if (idx == arr.size() - 1) {
		return arr[idx];
	}
	int a = arr[idx];
	int b = GcdOfArray(arr, idx + 1);
	return __gcd(
		a, b); // __gcd(a,b) is inbuilt library function
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> v1;

        for (int i = 0; i < n;i++)
        {
            cin >> v[i];
            if(v[i]%2==0)
            {
                v1.push_back(v[i] * 3);
            }
            else
            {
                v1.push_back(v[i] * 2);
            }
        }
        v1[0] = v[0];
        if(v1[0]==1)
        {
            cout << "-1" << endl;
        }
        else
        {
            for (auto i = v1.begin(); i != v1.end();i++)
            {
                cout << *i << " ";
            }
            cout << endl;
        }
    }
}
