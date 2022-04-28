#include<bits/stdc++.h>
using namespace std;

string keypadArr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void generate(string s,string ans)
{
    //Base case:
    if(s.length() == 0)
    {
        cout << ans << ", ";
        return;
    }

    char ch = s[0];//get the first charater and call rec for rest
    string val = keypadArr[ch - '0'];

    //Start by taking first digit
    string updated = s.substr(1);

    //Or use last digit %10 and /10

    //Iterate for all characters in a particular string
    for (int i = 0;i<val.length();i++)
    {
        generate(updated, ans + val[i]);//rec call
    }

}

int main()
{
    string s = "2378";
    cout << "[ ";
    generate(s, "");
    cout << "]";

    return 0;
}

// class Solution {
// public:
//     vector<string>keypadArr = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" }; 
    
//     vector<string>res;
    
//     void recur(string temp, string s, int i) {
//         if(i == s.size()) 
//         { 
//             //if reached at the end then add the solution to answer and return from there
//             res.push_back(temp);
//             return;
//         }
//         for(auto& c :  keypadArr[s[i] - '0']) 
//         {    //pick 1 element from the current set of characters
//             recur(temp + c, s, i + 1); // and then go to next click
//         }
//     }
    
//     vector<string> letterCombinations(string s)
//     {
//         if(s.empty()) return {};
//         int n = s.size();
//         recur("", s, 0); //start with index 0
//         return res;
//     }
// };