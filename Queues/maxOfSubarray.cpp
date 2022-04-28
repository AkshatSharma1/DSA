#include<bits/stdc++.h>
using namespace std;
//use deque

void maxSubarray(int arr[],int n,int k)
{
    int i=0;
    int j=0;
    deque<int> l;
    vector<int> ans;

    //Edge condition
    if(k > n)
    {
        ans.push_back(*max_element(arr,arr+n));
    }

    else
    {
        while (j<n)
        {
            //calculations 
            //traverse till list is not empty
            while(!l.empty() and l.back()<arr[j])
            {
                l.pop_back();
            }
            l.push_back(arr[j]);

            //window size check
            if((j-i+1)<k) j++;

            else if((j-i+1)==k)
            {
                //Process the answer
                ans.push_back(l.front());

                //remove the calculations
                if(arr[i]==l.front())
                {
                    l.pop_front();
                }
                //Slide the window
                i++;
                j++;
            }
        }
    }

    
    //printing the vector
    for(auto& itr: ans)
    {
        cout<<itr<<" ";
    }
}

int main()
{
    int arr[] = { 12, 1, 78, 90, 57, 89, 56 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    maxSubarray(arr,n,k);
    return 0;
}