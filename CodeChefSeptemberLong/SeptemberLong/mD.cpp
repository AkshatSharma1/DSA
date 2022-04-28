// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum
// Manhattan distance
void MaxDist(vector<pair<int, int> >& A, int N)
{
	// Vectors to store maximum and
	// minimum of all the four forms
	vector<int> V(N), V1(N);

	for (int i = 0; i < N; i++) {
		V[i] = A[i].first + A[i].second;
		V1[i] = A[i].first - A[i].second;
	}

	// Sorting both the vectors
	sort(V.begin(), V.end());
	sort(V1.begin(), V1.end());

	// int maximum
	// 	= max(V.back() - V.front(), V1.back() - V1.front());

	// cout << maximum << endl;
    cout << V.size() << " " <<V1.size();
}

// Driver Code
int main()
{
	int N = 6;

	// Given Co-ordinates
	vector<pair<int, int> > A
		= { { 1, 1 }, { 1, 2 }, { 1, 3 },{2,1},{2,2},{2,3} };

	// Function Call
	MaxDist(A, N);

	return 0;
}
