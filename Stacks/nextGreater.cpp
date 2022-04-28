#include<iostream>
#include<stack>
using namespace std;

void nextGreater(int arr[],int n)
{
    //base case: if array is empty then return immediately
    if(n==0){
        return;
    }

    stack<int> stk;
    stk.push(arr[0]);

    for(int i=1;i<n;i++)
    {
        if(stk.empty())
        {
            stk.push(arr[i]);
        }
        while(!stk.empty() and stk.top() < arr[i])
        {
            cout<<stk.top()<<"-->"<<arr[i]<<endl;
            stk.pop();
        }
        stk.push(arr[i]);
    }

    while(!stk.empty())
    {
        cout<<stk.top()<<"-->"<<-1<<endl;
        stk.pop();
    }
}

int main()
{
    int arr[] = { 13, 7, 6, 12 };
    int n = sizeof(arr) / sizeof(arr[0]);
    nextGreater(arr, n);
    return 0;
}