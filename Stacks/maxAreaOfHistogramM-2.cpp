#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int maxArea(vector<int> a)
{
    int i=0,ans=0,n=a.size();
    stack<int> s;
    a.push_back(0);//as last bars are of height 0
    
    //Traversing array
    while(i<n)
    {
        //If stk top > arr[i] i.e. incresaing stack until a lower comes
        while(!s.empty() and a[s.top()] > a[i])
        {
            //a potential rectangle comes and we need its maxArea
            int ht = a[s.top()];
            s.pop();

            if(s.empty())
            {
                ans = max(ans,ht * i);

            }

            else
            {
                int len = i-s.top() - 1;
                ans = max(ans,ht*len);
            }

        }
        s.push(i);
        i++;
    }
    return ans;
}

int main()
{
    vector<int> a = {2,1,5,6,2,3};
    cout<<maxArea(a);

    return 0;
}