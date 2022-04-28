#include <iostream>
#include <stack>
using namespace std;

stack<int> sortStack(stack<int> s1)
{
    stack<int> temp;

    while(!s1.empty())
    {
        int x = s1.top();
        s1.pop();

        while(!temp.empty() and temp.top()<x)
        {
            s1.push(temp.top());
            temp.pop();

        }

        temp.push(x);
    }
 

    return temp;
}

void callSort(int arr[],int n)
{
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        s.push(arr[i]);
    }

    stack<int> temp = sortStack(s);

    for(int i=0;i<n;i++){
        arr[i] = temp.top();
        temp.pop();
    }

}

int main()
{
    int arr[] = {10,15,5,50,45};
    int n = sizeof(arr)/sizeof(arr[0]);

    callSort(arr,n);

    for(int i=0;i<n;i++)
    {
        cout << arr[i] <<" ";
    }
    return 0;

}