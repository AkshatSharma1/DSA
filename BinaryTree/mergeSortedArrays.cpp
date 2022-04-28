#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef pair<int,pair<int,int> > customPair; //P.first = value, p.first.first = row index, p.first.second = ele index

vector<int> mergeSortedArrays(vector<vector<int>> arr)
{
    vector<int> result;
    priority_queue<customPair,vector<customPair>, greater<customPair>> pq;//min heap priority queue

    //insert 0th element of every array into heap
    for(int i=0;i<arr.size();i++)
    {
        pq.push({arr[i][0], {i,0}}); // value and index pair
    }
    //remove elements one by one fromthe min heap and add to result and add the next of removed element in heap
    while(!pq.empty())
    {
        customPair curr = pq.top();
        pq.pop(); 

        //element to be added to result array
        int element = curr.first; // value
        int Kth_Array_index = curr.second.first; // index of array
        int element_index_of_array = curr.second.second;

        result.push_back(element);

        //push next of element removed in heap
        if(element_index_of_array + 1 < arr[Kth_Array_index].size())
        {
            pq.push({arr[Kth_Array_index][element_index_of_array + 1], {Kth_Array_index,element_index_of_array + 1}});

        }
    }
    return result;
}

int main()
{
    int k;
    cin>>k;

    vector<vector<int>> arr = {
        { 10, 20, 30, 40 },
        { 15, 25, 35, 45 },
        { 25, 29, 37, 48 },
        { 32, 33, 39, 50 }};

    //approach is to make a min heap and put 3 elements into it(first element of each arr) and do it for all elements
    //now pop the min element from the min heap and put it in the answer arr and insert the next element from the array from where the element is popped and do heapification
    //here we will store three things - value,array idx(which row),element idx(ele idx in row)

    vector<int> output = mergeSortedArrays(arr);

    // for(auto it: output)
    // {
    //     cout<<it<<" ";
    // }

    cout<<endl;

    //find kth smallest element 
    int ans = output[k-1];
    cout<<ans;

    return 0;
}