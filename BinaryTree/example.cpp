// C++ program to minimize the cost of operation
// to bring all towers to same height.
#include <bits/stdc++.h>
using namespace std;

// Returns the cost of entire operation in bringing
// the height of all towers to equal height eq_h
long int costOfOperation(int n, int h[], int cost[],
						int eq_h)
{
	// Initialize initial cost to 0
	long int c = 0;

	// Adding cost for each tower
	for (int i = 0; i < n; i++)
		c += abs(h[i] - eq_h) * cost[i];

	return c;
}

// Return the minimum possible cost of operation
// to bring all the towers of different height
// in height[0..n-1] to same height.
long long int Bsearch(int n, int h[], int cost[])
{
	long int max_h = *max_element(h, h + n);
	long int ans = LONG_MAX;

	// Do binary search for minimum cost
	long int high = 1 + max_h;
	long int low = 0;
	while (high > low) {
		int mid = (low + high) >> 1;

		// Cost below mid
		long int bm = (mid > 0) ?
				costOfOperation(n, h, cost, mid - 1) :
				LONG_MAX;

		// Cost at mid
		long int m = costOfOperation(n, h, cost, mid);

		// Cost above mid
		long int am = costOfOperation(n, h, cost, mid + 1);


		// ans should hold the minimum cost of operation
		ans = min(ans, m);

		// Search lower cost
		if (bm <= m)
			high = mid;

		// Search higher cost
		else if (am <= m)
			low = mid + 1;

		// If am > m and bm > m
		// then ans is m
		else
			return m;
	}

	return (ans)%10^9+7;
}

// Driver code
int main()
{
	int h[] = { 1, 3, 8 };
	int cost[] = { 1, 100, 100 };
	int n = sizeof(h)/sizeof(h[0]);
	cout << Bsearch(n, h, cost);
	return 0;
}
