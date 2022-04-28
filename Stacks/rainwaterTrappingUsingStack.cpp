#include<bits/stdc++.h>
using namespace std;

int rainwaterTrapped(vector<int> a)
{
    stack<int> s;
    int n=a.size();
    int ans = 0;
    //traverse till we get a get a current bar greater than previous bars
    for(int i=0;i<n;i++)
    {
        while(!s.empty() and a[s.top()] < a[i])
        {
            int currentBar = s.top();
            s.pop();

            if(s.empty()) break;

            int lengthOfContainer = i-s.top()-1;
            ans=ans+(min(a[s.top()],a[i]) - a[currentBar]) * lengthOfContainer;

        }
        s.push(i);
    }
    return ans;
}

int main()
{
    vector<int> a={3,0,0,2,0,4};
    cout<<rainwaterTrapped(a)<<endl;

    return 0;
}