#include<bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 256;

void print_map(map<char, int> const &m)
{
    for (auto const &pair: m) {
        cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}

bool compare(const pair<char, int>&a, const pair<char, int>&b)
{
   return a.second<b.second;
}

//Check if unique string
bool uniqueCharacters(string str)
{
 
    // If length is greater than 265,
    // some characters must have been repeated
    if (str.length() > MAX_CHAR)
        return false;
 
    bool freqCheck[MAX_CHAR] = { 0 };
    for (int i = 0; i < str.length(); i++) {
        if (freqCheck[int(str[i])] == true) //if already a character exists
            return false;
 
        freqCheck[int(str[i])] = true;
    }
    return true;
}

int consistency(string s)
{
    int n = s.length();
    // transform(s.begin(), s.end(), s.begin(), ::toupper);
    //base case: if string contains only one character
    if(n==1)
    {
        return 0;
    }

    //Create a hashmap
    map<char,int> freq,vowelMax,consonantMax;
    int vowels = 0,consonants = 0;
    for(int i=0; i<n; i++)
    {
        freq.insert(make_pair(s[i],freq[s[i]]++));
        if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
        {
                vowels++;
                vowelMax[s[i]]++;
        }
        else{
            consonants++;
            consonantMax[s[i]]++;
        }
    }

    //Now cases
    //first get the most repeating character
    auto max = max_element(freq.begin(),freq.end(),compare);
    auto vowelMaxElement = max_element(freq.begin(),freq.end(),compare)
    
    
    // Case 1: if all characters have freq 1
    if(uniqueCharacters(s)==true)
    {
        //if my vowel count =1 || consonant count = 1
        if(vowels==1 || consonants==1)
        {
            return n-1;
        }

        //Case 2: if vowel count < consonant count, then try to change consonants to vowels
        else if((vowels < consonants)||(vowels==consonants))
        {
              return consonants + (vowels-1)*2;
        }
        else if((vowels > consonants)||(vowels==consonants))
        {
            return vowels + (consonants-1)*2;
        }
    }

    else{

        //Case 2: if vowel count < consonant count
        if((vowels < consonants)||(vowels==consonants))
        {
            if((max->first)=='A'||(max->first)=='E'||(max->first)=='I'||(max->first)=='O'||(max->first)=='U')
                return consonants + (vowels-(max->second))*2;
            
            else
            {
                return consonants + (vowels-1)*2;
            }
        }
        else if((vowels > consonants)||(vowels==consonants))
        {
            if((max->first)=='A'||(max->first)=='E'||(max->first)=='I'||(max->first)=='O'||(max->first)=='U')
                return vowels + (consonants-1)*2;
            else
                return vowels + (consonants-(max->second))*2;
        }

    }

}


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
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