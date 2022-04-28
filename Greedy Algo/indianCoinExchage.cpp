/*

Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the denominations in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins and/or notes needed to make the change?

Examples:  

Input: V = 70
Output: 2
We need a 50 Rs note and a 20 Rs note.

Input: V = 121
Output: 3
We need a 100 Rs note, a 20 Rs note and a 1 Rs coin.

*/

#include<iostream>
#include<algorithm>
using namespace std;

int make_change(int* coins,int n,int money)
{ 
    int ans = 0;
    //first pick a largest number lesser than money
    //using binary search to find idx of number greater than money using upperbound
    //then use it to find largest number<money using (-1-coins),it gives idx of coin.
    while(money > 0)
    {
        int idx = upper_bound(coins,coins+n,money) - 1 -coins;//coins(base address) [-coins means remove base address from idx address]
        cout<<coins[idx]<<" + ";
        money = money - coins[idx];
        ans++;

    }
    
    return ans;
}

int main()
{
    int money;
    cin>>money;

    int coins[] = {1,2,5,10,20,50,100,200,500,2000};
    int t = sizeof(coins)/sizeof(coins[0]);

    cout<<"\n\nMin Coins Needed: "<<make_change(coins,t,money);

    return 0;
}