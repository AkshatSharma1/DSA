
#include<bits/stdc++.h>
using namespace std;

int checkPalindrome(string str){
	
	int n = str.length();	

	// Counting number of characters
	// that should be changed.
	int count = 0;
	for (int i = 0; i < n/2; ++i)
		if (str[i] != str[n - i - 1])
			++count;

	return count;
}

// Driver function.
int main()
{
    string str;
    cin >> str;
    int ans = checkPalindrome(str);
    cout << ans << endl;

    return 0;
}
