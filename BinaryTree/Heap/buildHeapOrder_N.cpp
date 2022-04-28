#include<iostream>
#include<vector>
using namespace std;


bool compare(int a, int b)
{
    //max heap case 
    return a>b;
}

void buildHeap(vector<int> &v)
{
    for(int i=2;i<v.size();i++) //i=1 when idx>1 and vec{10,12,32,-----}, no -1
    {
        int idx = i;
        int parent = i/2;

        while(idx>0 and v[idx]>v[parent])//max heap
        {
            swap(v[idx],v[parent]);
            idx = parent;
            parent = parent/2;
        }
    }
}

void heapify(vector<int> &v,int idx)
{
        int left = 2*idx;
        int right = 2*idx + 1;

        int min_index = idx;
        int last_idx = v.size() - 1;

        //now if the child of the parent nodes exist in the array then heapify the tree
        if(left<=last_idx and compare(v[left],v[min_index]))
        {
            min_index = left;
        }
        if(right<=last_idx and compare(v[right],v[min_index]))
        {
            min_index = right;
        }
        //swwap min index and parent index
        if(min_index!=idx)
        {
            swap(v[idx],v[min_index]);
            //rec call
            heapify(v,min_index);
        }
}

void buildHeap_2(vector<int> &v)
{
    for(int i = (v.size()-1)/2;i>=1;i--)
    {
        heapify(v,i);
    }
}

void print(vector<int> vec)
{
    for(auto &it: vec)
    {
        cout<<(it)<<" ";
    }2
    
}

int main()
{
    vector<int> v{-1,10,20,5,6,1,8,9,4};
    buildHeap_2(v);
    print(v);
    return 0;
}