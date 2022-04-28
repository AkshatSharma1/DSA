#include<bits/stdc++.h>
using namespace std;
int dp[100001];
#define mod 1000000007
#define ll long long int

int findStrings(string s){
    
    if(s.length() == 0 || s.length() == 1){
        return s.length();
    }
    
    if(dp[s.length()] != -1)
        return dp[s.length()];
    
    ll option1 = findStrings(s.substr(1))%mod;
    ll option2 = 0;
    if((s[0] == '3' && s[1] == '3') || (s[0] == '2' && s[1] == '2')){
        option2 = findStrings(s.substr(2))%mod;
    }
    
    ll ans = (option1%mod + option2%mod)%mod;
    dp[s.length()] = ans;
    return ans;
}

int solve(int n, string s){

    memset(dp,-1,100001);
    return findStrings(s)%mod;
}

int main(){
    int n;
    cin>>n;

    string s;
    cin>>s;

    cout<<solve(n,s);
}