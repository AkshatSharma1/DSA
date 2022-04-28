#include<bits/stdc++.h>
using namespace std;

// void printSubset(vector<int> in,vector<int> out,int index) {

//     // Base case
//     // When whole array is traversed then print the output array
//     if(index>=in.size())
//     {
//         //Print the output array
//         for(auto i: out)
//         {
//             cout << i << " ";
//         }
//         cout << "\n";
//         return;
//     }

//     //Include the values in output array
//     printSubset(in, out,index+1);
//     //Fill the output array
//     out.push_back(in[index]);
//     //Exclude the value
//     printSubset(in,out,index+1);

//     //or
//     // printSubset(in.substr(1), out);
//     // printSubset(in.substr(1), out + in[0]); and cout<<out in base cond
// }
void printSubset(string in, string out,int index)
{
    //Base case 
     if(index>=in.length())
    {
        //Print the output array
        cout << out << endl;
        return;
    }

    printSubset(in, out, index + 1);

    out = out + in[index];

    printSubset(in, out, index + 1);
}

int main()
{
    // cout << "Enter array size: ";
    // int n;
    // cin >> n;

    // vector<int> in(n);
    // vector<int> out;

    // for(int i=0; i<n; i++)
    // {
    //     cin >> in[i];
    // }
    string in;
    cin >> in;
    string out;

    cout << "Subsets are:\n";
    printSubset(in, out, 0);
    return 0;
}