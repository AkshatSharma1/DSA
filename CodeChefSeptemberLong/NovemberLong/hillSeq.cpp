#include<bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int>&a, const pair<int, int>&b)
{
   return a.second<b.second;
}

bool compare1(int a, int b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        /* code */
        int n;
        cin >> n;

        int arr[n];
        unordered_map<int, int> m;

        vector<int> left;
        vector<int> right;

        for (int i = 0; i < n;i++){
            cin >> arr[i];
            m[arr[i]]++;
        }
        //Max element in arr
        int maxEleInArr = *max_element(arr,arr+n);

        //Max frequency element
        auto maxFreqEle = max_element(m.begin(), m.end(), compare)->second;
        
        if(m[maxEleInArr] > 1 or maxFreqEle > 2)
        {
            cout << "-1" << endl;
        }
        else
        {
            for (auto itr = m.begin(); itr != m.end(); itr++)
            {
                if(itr->second == 2)
                {
                    right.push_back(itr->first);
                    left.push_back(itr->first);
                }
                else if(itr->second == 1)
                {
                    left.push_back(itr->first);
                }
            }

            sort(left.begin(), left.end(),compare1);
            sort(right.begin(), right.end());

            for (int i = 0; i < right.size();i++)
            {
                cout << right[i] << " ";
            }

            for (int i = 0; i < left.size();i++)
            {
                cout << left[i] << " ";
            }

            cout << endl;
        }
    }
    
}