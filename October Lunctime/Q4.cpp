/* C++ code to generate all possible subarrays/subArrays
	Complexity- O(n^3) */
#include<bits/stdc++.h>
using namespace std;

// Prints all subarrays in arr[0..n-1]
void subArray(int arr[], int n)
{
    int count = 0;
    // Pick starting point
	for (int i=0; i <n; i++)
	{
		// Pick ending point
		for (int j=i; j<n; j++)
		{
            for (int k=i; k<=j; k++)
                if(arr[k] == i)
                {
                    count++;
                }
		}
	}
    cout << count;
}

// Driver program
int main()
{
	int arr[] = {1, 3, 4, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "All Non-empty Subarrays\n";
	subArray(arr, n);
	return 0;
}
