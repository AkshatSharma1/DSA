#include<bits/stdc++.h>
using namespace std;

//For finding Nearest smaller to left
vector<int> NSL(int arr[],int n)
{
    vector<int> left;
    stack<pair<int,int>> s;
    int pseudo_index = -1;
    for(int i=0;i<n;i++)
    {
        if(s.empty()) left.push_back(pseudo_index);

        else if(!s.empty() and s.top().first < arr[i])
        {
            left.push_back(s.top().second);
        }

        else if(!s.empty() and s.top().first >= arr[i])
        {
            while(!s.empty() and s.top().first >= arr[i])
            {
                s.pop();
            }

            if(s.empty()) left.push_back(pseudo_index);
            else left.push_back(s.top().second);
        }

        s.push({arr[i],i});
    }

    return left;
}

//For finding Nearest smaller to right
vector<int> NSR(int arr[],int n)
{
    vector<int> right;
    stack<pair<int,int>> s;
  
    for(int i=n-1;i>=0;i--)
    {
        if(s.empty()) right.push_back(n);

        else if(!s.empty() and s.top().first < arr[i])
        {
            right.push_back(s.top().second);
        }

        else if(!s.empty() and s.top().first >= arr[i])
        {
            while(!s.empty() and s.top().first >= arr[i])
            {
                s.pop();
            }

            if(s.empty()) right.push_back(n);
            else right.push_back(s.top().second);
        }

        s.push({arr[i],i});
    }
    reverse(right.begin(), right.end());

    return right;
}

int maxArea(int arr[],int n)
{
    vector<int> r = NSR(arr,n);
    vector<int> l = NSL(arr,n);

    vector<int> area;
    for(int i = 0; i < n; i++)
    {
        area.push_back(arr[i]*abs(r[i]-l[i]-1));
    }
   
    int max = *max_element(area.begin(),area.end());
    return max;
}

// vector<int> widthCal(vector<int> l, vector<int> r, int n)
// {
//     vector<int> w;
//     for(int i = 0; i < n; i++)
//     {
//         w.push_back(abs(r[i] - l[i] -1));
//     }
//     return w;
// }

// vector<int> areaCal(vector<int> width, int arr[], int n)
// {
//     vector<int> a;
//     for(int i = 0; i < n; i++)
//     {
//         a.push_back(width[i]*arr[i]);
//     }

//     return a;
// }

int main()
{
    int arr[] = {2,1,5,6,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    // vector<int> l = NSL(arr,n);
    // vector<int> r = NSR(arr,n);

    // vector<int> width = widthCal(l,r,n);
    // vector<int> area = areaCal(width,arr,n);

    // for(auto i: l)
    // {
    //     cout<<i<<"  ";
    // }

    // cout<<endl;
    // for(auto i: r)
    // {
    //     cout<<i<<"  ";
    // }

    //     cout<<endl;
    // for(auto i: area)
    // {
    //     cout<<i<<"  ";
    // }

    int maxAreaofHist = maxArea(arr,n);
    cout<<maxAreaofHist<<endl;

    return 0;
}