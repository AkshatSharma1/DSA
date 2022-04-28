/*
    Count anagrams(permutations) of a substring in a given string.
    Example: fox in oxfrroxffxodf. Anagrams of fox are 3! ,i.e, fox,ofx,xof,oxf,fxo,xfo.

    Note: a) Anagrams would be in continuos manner. So, sliding window of size k =3 here.
          b) First check the quantity of characters in pattern and then check each character frequency for comparison.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "aabaabaa";
    string ptr = "aaba";
    int k = ptr.length();
    int size = s.length();

    int i=0;
    int j=0;
    int ans;

    map<char,int> m;
    map<char,int>::iterator it;
    for(int i=0;i<k;i++)
    {
        m[ptr[i]]++;
    }

    int count = m.size();

    // cout<<count<<endl;
    while(j<size)
    {
        //Logic 
        if(m.count(s[j])>0)
        {
            m[s[j]]--;
            if(m[s[j]]==0){
                count--;
            }
        }

        if((j-i+1)<k)
        {
            j++;
        }
        else if((j-i+1)==k)
        {
            if(count==0)
            {
                ans++;
            }

            if(m.count(s[i])>0)
            {
                m[s[i]]++;
                if(m[s[i]]==1)
                {
                    count++;
                }
            }
            i++;
            j++;
        }
    }
    cout<<ans<<endl;
    return 0;

}