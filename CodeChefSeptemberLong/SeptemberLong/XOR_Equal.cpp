#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;

pair<int,int> xor_equal(int* arr,int n,int x)
{
    map<int, int> counter;
    map<int, int> operations;
    for (int i = 1; i <= n;i++)
    {
        //Count frequency of numbers in array
        counter.insert(mp(arr[i], counter[arr[i]]++));
        //Initially operations are 0
        operations.insert(mp(arr[i], 0));
    }
    
    //Doing XOR and storing its result mainly updating it in the map using some condition check
    for (int i = 1; i <= n;i++)
    {
        //if X=0, then number xor 0 = number
        if(x==0)
        {
            break;
        }

        int xor_value = arr[i] ^ x;
        counter.insert(mp(xor_value, counter[xor_value]++));
        operations.insert(mp(xor_value, operations[xor_value]++));
    }
    //Find max same numbers in the vector 
    //Let max same numbers be 1
    int max_same = 1;
    //min operations needed be initally infinity
    int minimum_operations = INT_MAX;
    vector<int> v;

    //Iterate in map 
    for(auto i: counter)
    {
        if(max_same < i.second)
        {
            max_same = i.second;
            //Initially empty the vector after every test case
            v.clear();
            v.pb(i.first);
        }
        else if(max_same == i.second)
        {
            v.pb(i.first);
        }
    }

    //For min operations to be performed
    for(auto num: v)
    {
        minimum_operations = min(minimum_operations, operations[num]);
    }
    return mp(max_same, minimum_operations);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 1; i <= n;i++)
        {
            cin >> arr[i];
        }

        auto result = xor_equal(arr, n, x);
        cout << result.first << " " << result.second << "\n";
    }
    return 0;
}
