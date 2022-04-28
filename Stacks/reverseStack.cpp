#include<iostream>
#include<stack>

using namespace std;

// void transfer(stack<int>&s1, stack<int>&s2,int n) {
//     for(int i=0;i<n;i++)
//     {
//         s2.push(s1.top());
//         s1.pop();
//     }
// }

// void reverse(stack<int>&s1)
// {
//     stack<int> s2;
//     int n = s1.size();
//     for(int i=0;i<n;i++)
//     {
//         int x = s1.top();
//         s1.pop();

//         transfer(s1,s2,n-i-1);

//         s1.push(x);

//         transfer(s2,s1,n-i-1);
//     }
// }

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

    int x = s.top(); 
    s.pop();

    reverse(s);

    insertAtBottom(s,x);
}
int main()
{
    stack<int> s;
    // int m;cin>>m;
    // for(int i=0;i<m;i++)
    // {
    //     int data; cin>>data;
    //     s.push(data);
    // }
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverse(s);
    cout<<"\nReversed: ";

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}