#include<bits/stdc++.h>
using namespace std;

//Method 1: Brute Force
// int longestConsecutiveSubsequence(int* arr,int n)
// {
//     int ans=0;
//     int count=0;

//     sort(arr,arr+n);

//     //make a vector to store only unique elements
//     vector<int> uniqueElements;
//     uniqueElements.push_back(arr[0]);
    
//     //insert repeated elements only once in the vector
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] != arr[i - 1])
//             uniqueElements.push_back(arr[i]);
//     }

//     // //Making unique elements using stl
//     // vector<int> uniqueEle(arr,arr+n);
//     // vector<int> :: iterator it;
//     // it = unique(uniqueEle.begin(),uniqueEle.end());
//     // //resize vector to hold only unique elements
//     // uniqueEle.resize(distance(uniqueEle.begin(),it));

//     //Now traverse the vector yo find the longest subsequence 
//     for(int i=0;i<uniqueElements.size();i++)
//     {
//         if(i>0 and uniqueElements[i]==uniqueElements[i-1]+1)
//         {
//             count++;
//         }
//         else
//         {
//             count = 1;
//         }
        
//         ans = max(ans,count);
//     }
//     return ans;

// }

/* -------------------------------------------------------------------------------------------------*/

//Method 2: Hashing
// int longestConsecutiveSubsequence(int* arr,int n)
// {
//     unordered_map<int,int> m; //number, streak length

//     //iterate over array
//     for(int i=0;i<n;i++)
//     {
//         int no = arr[i];

//         //case 1: if left and right joining not possible
//         if(!m.count(no-1) and !m.count(no+1))
//         {
//             m[no] = 1; //len=1 
//         }

//         //case 2: if left and right joining possible
//         else if(m.count(no-1) and m.count(no+1))
//         {
//             //if both present, then find the length of left and right streaks
//             int len1 = m[no-1];
//             int len2 = m[no+1];

//             int total_len = len1 + 1 +len2;
//             m[no-len1] = total_len; //starting indx
//             m[no+len2] = total_len; //ending indx
//         }
//         //case 3: left present and right not
//         else if (m.count(no-1) and !m.count(no+1)) //!m.count(no+1) is equivalent to m.count(no+1)==0
//         {
//             int len = m[no-1];
//             m[no-len] = len+1;
//             m[no] = len+1;
//         }
//         //case 4: left not and right present
//         else //(m.count(no-1)==0 and m.count(n+1))
//         {
//             int len = m[no+1];
//             m[no+len] = len+1;
//             m[no] = len+1;
//         }

//     }
//     //iterate over hashmap and find largest element
//     int largest = 0;
//     for(auto it:m){
//         largest = max(largest,it.second);
//     }
//     return largest;
// }

//Method 3: unordered_set
int longestConsecutiveSubsequence(int* arr,int n)
{
        unordered_set<int> s;
        int max_len = 1;
        int startIndex;
        int endingIndex;
        for(int i=0;i<n;i++)
        {
            s.insert(arr[i]);
        }

        //iterate over all elements ans choose(target) those from where a streak can start
        for(int i=0;i<n;i++)
        {
            //chk if we can find a number one less than current number,i.e, chk if left exists of a current number
            if(s.find(arr[i]-1)==s.end())
            {
                //if true,i.e, no number one less than it 
                //now arr[i] is the starting index of streak
                startIndex = arr[i];
                //now chk entire range in the set if one greater than stratIndex exists
                int next_no = arr[i+1];
                int streak_len = 1;
                while(s.find(next_no)!=s.end())
                {
                    //if found, 
                    next_no += 1;
                    streak_len += 1;
                }
                endingIndex = arr[i];
                max_len = max(max_len,streak_len);
                /* or
            int j = arr[i];
            while (S.find(j) != S.end())
                j++;
 
            // update  optimal length if
            // this length is more
            ans = max(ans, j - arr[i]);
            */
            }
        }
        cout<<"Starting Index value: "<<startIndex<<" and "<<"Ending Index value: "<<endingIndex<<endl;
        return max_len;
}



int main()
{
    int arr[] = {1,9,3,10,4,20,2};
    // int arr[] = {14,5,1,2,6,3,7,8,9,13,15,11,12,13,17,10};
    int n =sizeof(arr)/sizeof(arr[0]);

    cout<<"Length is: "<<longestConsecutiveSubsequence(arr,n);

    return 0;
}