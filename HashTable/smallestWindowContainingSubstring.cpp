//Find the smallest windoe of string containing all the characters of the another string
//Sliding window concept
//String: "hellloeeo"; pattern:"eelo".

/* Method:- 
    Case 1: If Pattern length > string length(SL)
        return false
    Case 2: Else if Pattern length < SL

        Make a pattern frequency map 
        Run sliding window algo on string and make a map of string frequency values
        Now chk if frequency of string values is in pattern map 
        If no, then move ahead and increase window size and include elements frequency
        When the frequency of elements traversed in string matches the pattern map frequency then it is the answer 
        Now we get a valid window and note its starting and ending index
        Now we chk if there is a smaller window available 
        For this we contract string from left.
        If pattern still fits, then move ahead and remove elements
        If not, then move the right(ending) index and increase window size 
        Do above 4 steps repeatedly.

        Note: Evertime we get a window, update the min window by doing comparison between current window and min window till now 
*/

#include<bits/stdc++.h>
using namespace std;

string find_window(string s,string pattern) {

    int SL = s.length();
    int PL = pattern.length();

    //Base Case: 
    if(PL > SL)
    {
        return "None";
    }

    //Make frequency maps(here we only need value no keys so make a simple arr map)
    int string_map[256] = {0};
    int pattern_map[256] = {0};

    //Get frequencies of characters of pattern
    for(int i = 0; i < PL; i++)
    {
        char ch = pattern[i];
        pattern_map[ch]++;
    }

    //Sliding window to map frequency of string character and compare with pattern map
    int count = 0;
    int start = 0;
    int min_len = INT_MAX;
    int start_indx = -1;
    
    for(int i=0;i<SL;i++)
    {
        char ch = s[i];
        string_map[ch]++;

        //Maintain the count of characters matched 
        if(pattern_map[ch]!=0 and string_map[ch]<=pattern_map[ch])
        {
            //means character count is not matched 
            count++;
        }

        //Now if all the characers match(window is found)
        if(count == PL){

            //start shrinking the window
            char temp = s[start];//starting index value 

            //loop to remove extra characters to get min size window
            while(pattern_map[temp]==0 or string_map[temp] > pattern_map[temp] )
            {
                //ignore the current character
                string_map[temp]--;
                start++;
                temp = s[start];
            }
            //when min size recahed
            int window_len = i - start + 1; //j-i+1
            if(window_len < min_len)
            {
                min_len = window_len;
                start_indx = start;
            }
        }

    }
    if(start_indx == -1)
    {
            return "None";
    }

    string ans = s.substr(start_indx, min_len);
    return ans;
}

int main()
{
    string s = "hllloeaeo world";
    string p = "eelo";

    cout<<find_window(s,p)<<endl;
    return 0;
}