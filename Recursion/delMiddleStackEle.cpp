#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

void solve(stack<int>&s,int k,int size)
{
    //Base case: When the mid element "k" becomes the topmost element in stack i.e. k==1
    //or Base case: can be the size of stack i.e when original size > mid of stack(half)
    if(k==1)
    {
        s.pop(); //remove the middle element
        return;
    }

    //pop the topmost element from stack till we reach the middle element
    int temp = s.top();
    s.pop();

    solve(s, k - 1,size);

    //Push back the topmost element to the stack
    s.push(temp);

    return;
}

int main()
{
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    stk.push(6);
    stk.push(7);

    int k = ceil(stk.size() / 2.0);
    int size = stk.size();

    solve(stk, k,size);

    while(!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }

    return 0;
}