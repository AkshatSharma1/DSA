// class Solution {
// public:
//     vector<vector<int>> combine(int n, int k) {
//         vector<vector<int>> result;
//         const int code = pow( 2, n );
//         for (int i = 0; i < code; ++i) {
//             bitset<20> b(i);
//             if (b.count() != k) continue;
            
//             int c = i;
//             vector<int> set;
//             for (int j = 1; j <= n; ++j) {
//                 if (c & 1) set.push_back( j );
//                 c >>= 1;
//             }
//             result.push_back( set );
//         }
//         return result;
//     }
// };

#include<bits/stdc++.h>
    
    //Vector for storing result
    vector<vector<int>> result;
    
    //Start from 1 to n-1, so pass a beginner iterator
    void helper(vector<int> out, int n,int k,int begin)
    {
        //Base case
        if(k==0)
        {
            result.push_back(out);
            return;
        }
        
        //Rec cases
        
        for(int i=begin;i<=n;++i)
        {
            //Push the elements into out vector
            //Include case
            out.push_back(i);
            //Rec call
            helper(out,n,k-1,i+1);
            
            //exclude case
            out.pop_back();
            
        }
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> output;
        helper(output,n,k,1);
        
        return result;
    }
};