#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int distance(vector<int> v, int n){

    int dist = 0;
    int maxD = 0;

    int dp[n];
    dp[0]=v[0];

    for(int i=1;i<n;i++){
        dp[i] = dp[i-1] + v[i];
    }

    int curr;
    for(int i=0;i<v.size();i++){

        curr = v[i] + dp[i]; 
        cout<<curr<<" ";
        maxD = max(maxD,curr); 
        // cout<<endl;
    }

    return maxD;
}

int main(){
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<distance(v,n);

    return 0;

}