#include<iostream>
#include<vector>
using namespace std;

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

void print(vector<int> vec)
{
    for(auto &it: vec)
    {
        cout<<(it)<<" ";
    }
}

int main()
{
    vector<int> v{-1,10,20,5,6,1,8,9,4};
    buildHeap(v);
    print(v);
    return 0;
}