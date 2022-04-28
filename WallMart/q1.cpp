// C++ implementation of above approach
#include <bits/stdc++.h>
using namespace std;

int static dp[1001];

bool isPower(int x,int y){
    int res1 = log(y) / log(x);
	double res2 = log(y) / log(x);

    return (res1==res2);
}

// Function that returns the minimum
// number of operations to be performed
// to reduce the number to 1
int count_minimum_operations(long long n)
{
	// Base cases
	// if (n == 2) {
	// 	return 1;
	// }
	if (n == 1) {
		return 1;
	}
	if(dp[n] != -1)
	{
		return dp[n];
	}
	if (isPower(6,n)) {
		dp[n] = 1 + count_minimum_operations(n / 6);
	}
	else if (isPower(9,n)) {
		dp[n] = 1 + count_minimum_operations(n / 9);
	}
    else if((n%6==1) and (n%9==1)){
        dp[n] = 1 + count_minimum_operations(n-1);
    }
	else {
		dp[n] = 1 + count_minimum_operations(n + 1);
	}
	return dp[n];
}

// Driver code
int main()
{
	long long n = 127;
	memset(dp, -1, sizeof(dp));
	long long ans = count_minimum_operations(n);
    // cout<<isPower(9,81);
	cout << ans << endl;
	return 0;
}
