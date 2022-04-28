#include<bits/stdc++.h>

using namespace std;

int main()
{
    char s[] = "aabacbebebe";
    int n = strlen(s);
    int mx = INT_MIN;
    // int k = 3;

    int i=0,j=0;
    unordered_map<char,int> mp;

    while(j<n)
    {
        //Calculations  
        mp[s[j]]++;
        // if(mp.size() > (j-i+1)) // this condition will not hit ever as map size cant be > w.s
        // {
        //     j++;
        // }

        if (mp.size() == (j-i+1))
        {
            mx = max(mx,j-i+1);
            j++;            
        }

        else if(mp.size() < (j-i+1)) //agar map ka size chota hai w.s se then it means ki map mei repeating characters hai
        {
            while(mp.size()<(j-i+1))//so we pop until map size == w.s
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