#include<bits/stdc++.h>
using namespace std;
int main() {

	int t;
	cin>>t;
	while(t--)
	{
		int n,data;
		cin>>n;
		list<int> l1;
		for(int i=0;i<n;i++)
		{
			cin>>data;
			l1.push_back(data);
		}

		int m,data2;
		cin>>m;
		list<int> l2;
		for(int i=0;i<m;i++)
		{
			cin>>data2;
			l2.push_back(data2);
		}

		l2.merge(l1);
		for(auto i = l2.begin(); i !=l2.end(); ++i)
		{
			cout << *i << " ";
		}
    		
	}
	
	return 0;
}