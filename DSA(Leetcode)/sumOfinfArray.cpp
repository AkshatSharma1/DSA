#include<bits/stdc++.h>
using namespace std;

// vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries,int q) 
// {
// 	long long  mod = 1000000007;
// 	vector <int> ans(q);
// 	vector <long long> prefixSum(n+1);
// 	prefixSum[0] = 0;
// 	for(long long i = 0; i < n; i++)
// 		prefixSum[i+1] = (prefixSum[i] + arr[i]) % mod;
    
//     // for(long long i=0;i<n;i++){
//     //     cout<<prefixSum[i]<<" ";
//     // }
    
//     long long temp;

// 	for(long long i = 0; i < q; i++)
// 	{
// 		long long l=queries[i][0];
// 		long long r=queries[i][1];
// 		l--;
//         //right-left * hoe many times a prefixSum[n] occurs
// 		temp = (prefixSum[r%n] - prefixSum[l%n] + ((prefixSum[n] * ((r/n - l/n) % mod)))) % mod ;
		
//         cout<<"r/n = "<<r/n<<" "<<"/n = "<<l/n<<endl;
//         cout<<prefixSum[r%n]<<" "<<prefixSum[l%n]<<endl;
        
//         ans[i] = temp;
// 	}
// 	return ans;
// }

/*
    Time Complexity:O(Q+N).
    Space Complexity:O(N).

    Where N is the size of the given array, and Q is the number of queries given.
*/

int mod = 1000000007;

// Function to calculate prefix sum upto index x of the infite array.
long long func(vector<long long> &sumArray, long long x, long long n) {

    // Number of times the given array comes completely upto index x.
    long long count = (x / n) % mod;
    cout<<count<<endl;

    long long res = (count * sumArray[(int) n]) % mod;

    // Adding the remaining elements sum.
    res = (res + sumArray[(int) (x % n)]) % mod;

    return res;
}

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {

    // It stores answer for each query.
    vector<int> ans;

    // It store cumulative sum where sumArray[i] = sum(A[0]+..A[i]).
    vector<long long> sumArray(n + 1);

    for (int i = 1; i <= n; i++) {
        sumArray[i] = (sumArray[i - 1] + arr[i - 1]) % mod;
    }
    

    // Traversing the given queries.
    for (int i = 0; i < queries.size(); i++) {
        vector<long long> range = queries[i];
        long long l = range[0];
        long long r = range[1];

        // It stores the prefix sum from index 0 to index r in an infinite array.
        long long rsum = func(sumArray, r, n);

        // It stores the prefix sum from index 0 to index l-1 in an infinite array.
        long long lsum = func(sumArray, l - 1, n);

        // Add answer for each query.
        ans.push_back((int) ((rsum - lsum + mod) % mod));

    }

    return ans;
    
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int q;
    cin>>q;
    vector<vector<long long>> queries;
    for(int i=0;i<q;i++){
        vector<long long> q(2);
        for(int j=0;j<2;j++){
            cin>>q[j];
        }
        queries.push_back(q);
    } 

    vector<int> res = sumInRanges(arr, n, queries, q);
    for(auto i: res){
        cout<<i<<" ";
    }

}
