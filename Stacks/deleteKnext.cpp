#include <iostream>
#include <stack>
using namespace std;
void insertAtBottom(stack<int>&s, int x)
{
    //Base case 
    if(s.empty()){
        s.push(x);
        return;
    }

    //Rec Cases
    int data = s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(data);
}

void reverse(stack<int>&s)
{
    //base  case
    if(s.empty()){
        return;
    }

    int x = s.top(); s.pop();

    reverse(s);

    insertAtBottom(s,x);
}

void deleteKnext(int arr[],int n,int k) 
{
    stack<int> s;
    s.push(arr[0]);
    int count=0;

    for(int i=1;i<n;i++)
    {
        while(!s.empty() and s.top()<arr[i] and count<k)
        {
            s.pop();
            count++;
        }

        s.push(arr[i]);
    }
    reverse(s);

    
    for(int i=0;i<n;i++)
    {
        arr[i] = s.top();
        s.pop();
        cout << arr[i] <<" ";
    }
}

int main()
{
    int arr[] = {20,10,25,30,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k; cin>>k;
    deleteKnext(arr,n,k);

    return 0;

}