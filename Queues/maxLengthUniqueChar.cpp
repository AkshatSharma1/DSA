#include<bits/stdc++.h>

using namespace std;

int main()
{
    char s[] = "aabacbebebe";
    int n = strlen(s);
    int mx = INT_MIN;
    int k = 3;

    int i=0,j=0;
    unordered_map<char,int> mp;

    while(j<n)
    {
        //Calculations  
        mp[s[j]]++;
        if(mp.size() < k)
        {
            j++;
        }

        else if (mp.size() == k)
        {
            mx = max(mx,j-i+1);
            j++;            
        }

        else if(mp.size() > k)
        {
            while(mp.size()>k)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        
    }
    cout<<mx<<endl;
    return 0;
}