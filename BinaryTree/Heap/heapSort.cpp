#include<iostream>
#include<vector>
using namespace std;


bool compare(int a, int b)
{
    //max heap case 
    return a>b;
}

void heapify(vector<int> &v,int idx,int size)
{
        int left = 2*idx;
        int right = 2*idx + 1;

        int min_index = idx;
        int last_idx = size - 1;

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
            heapify(v,min_index,size);
        }
}

void buildHeap_2(vector<int> &v)
{
    for(int i = (v.size()-1)/2;i>=1;i--)
    {
        heapify(v,i,v.size());
    }
}

//heap sort function
void heapSort(vector<int> &v)
{
    buildHeap_2(v);
    int n = v.size();

    //remove n-1 elements from top(start of array) of heap
    while(n>1)//min 2 elements
    {
        swap(v[1],v[n-1]);
        //remove last, here we are shrinking not removing
        n--;//shrinking 

        //now heapify the new tree heap
        heapify(v,1,n);//pass size also

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
    // vector<int> v{-1,10,20,5,6,1,8,9,4};
    vector<int> v;
    v.push_back(-1);

    int n; cin>>n; 

    int temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        v.push_back(temp);
    }
    
    heapSort(v);
    print(v);
    return 0;
}