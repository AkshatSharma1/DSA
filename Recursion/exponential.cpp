#include<bits/stdc++.h>
using namespace std;

int exp(int n)
{
    //Base case
    if(n==0)
        return 1;
    
    //Exp case
    //Case 1: If n is odd, then
    int ans = exp(n / 2);
    if(n&1)
    {
        return 2 * ans * ans;
    }
    else
    {
        return ans * ans;
    }
}

int main(){
    int n;
    cin >> n;

    cout << "Answer is: " << exp(n);

    return 0;
}