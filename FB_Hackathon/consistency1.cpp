#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<char, int> &a, const pair<char, int> &b)
{
    return a.second < b.second;
}


int consistency(string s)
{
    int n = s.length();
    if (n == 1)
    {
        return 0;
    }

    map<char, int> freq;
    map<char, int> vowelCount;
    map<char, int> consonantCount;
    int vowels = 0, consonants = 0;
    for (int i = 0; i < n; i++)
    {
        freq.insert(make_pair(s[i], freq[s[i]]++));
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            vowels++;
            vowelCount[s[i]]++;
        }
        else
        {
            consonants++;
            consonantCount[s[i]]++;
        }
    }
    

    auto maxVowel = max_element(vowelCount.begin(), vowelCount.end(), compare);
    auto maxConsonant = max_element(consonantCount.begin(), consonantCount.end(), compare);
    
    if(vowels==0 or consonants==0){
        return n;
    }
    int replaceByCons = (consonants - (maxConsonant->second)) * 2 + vowels;
    int replaceByVow = consonants + (vowels - (maxVowel->second)) * 2;
    return min(replaceByCons, replaceByVow);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        string s;
        cin>>s;

        int ans = consistency(s);
        
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
    return 0;
}