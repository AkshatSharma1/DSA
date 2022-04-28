#include<bits/stdc++.h>
using namespace std;

void getpermutation(string str,int index)
{
    //Base condition:  whole string is traversed 
    if(index>=str.length())
    {
        //Print
        cout << str << endl;
        return;
    }

    //Traverse whole string
    for (int i = index;i<str.length();i++)
    {
        //Swap the current element till str.length() elements
        swap(str[index], str[i]);

        //Rec callback
        getpermutation(str, index + 1);

        //backtracking
        swap(str[index],str[i]);
    }
}

int main()
{
    string s = "123";
    getpermutation(s, 0);
    return 0;
}


//Heaps Algo
/*
    Time complexity: O(N!)
    Space complexity: O(N * N!)

    Where 'N' is the size of the vector.
*/

// void permutationHelper(vector<int> &vec, vector<vector<int>> &answer, int size) {
//     // Base case.
//     if (size == 1) {
//         answer.push_back(vec);
//     }
//     for (int i = 0; i < size; i++) {
//         permutationHelper(vec, answer, size - 1);

//         // If size is odd, swap 0th and last element.
//         if (size % 2 == 1) {
//             swap(vec[0], vec[size - 1]);
//         }

//         // If size is even, swap ith and last element.
//         else {
//             swap(vec[i], vec[size - 1]);
//         }
//     }
// }

// vector<vector<int>> permutations(vector<int> &vec, int size) {
//     vector<vector<int>> answer;
//     permutationHelper(vec, answer, size);
//     return answer;
// }