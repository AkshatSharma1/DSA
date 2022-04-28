// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the number of right
// angled triangle that are formed from
// given N points whose perpendicular or
// base is parallel to X or Y axis
int RightAngled(int a[][2], int n)
{

	// To store the number of points
	// has same x or y coordinates
	unordered_map<int, int> xpoints;
	unordered_map<int, int> ypoints;

	for (int i = 0; i < n; i++) {
		xpoints[a[i][0]]++;
		ypoints[a[i][1]]++;
	}

	// Store the total count of triangle
	int count = 0;

	// Iterate to check for total number
	// of possible triangle
	for (int i = 0; i < n; i++) {

		if (xpoints[a[i][0]] >= 1
			&& ypoints[a[i][1]] >= 1) {

			// Add the count of triangles
			// formed
            //(n1-1)*(n2-1) 
			count += (xpoints[a[i][0]] - 1)
					* (ypoints[a[i][1]] - 1);
		}
	}

	// Total possible triangle
	return count;
}

// Driver Code
int main()
{
	int N = 5;

	// Given N points
	int arr[][2] = { { 1, 2 }, { 2, 1 },
					{ 2, 2 }, { 2, 3 },
					{ 3, 2 } };

	// Function Call
	cout << RightAngled(arr, N);

	return 0;
}
