#include<iostream>
#include<vector>
using namespace std;

class Heap{

    //vector for storing data 
    //another variable for storing type of heap - min or max 
    vector<int> v;
    bool minHeap;

    bool compare(int a, int b)
    {
        if(minHeap)
        {
            return a<b;
        }

        else
        {
            return a>b;
        }
    }

    void heapify(int idx)
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
            heapify(min_index);
        }
    }
        
    public:

        //constructor
        Heap(int default_size = 10, bool type = true)
        {
            v.reserve(default_size); //reserve 10 spaces. vector will not expand till 10 are fill
            v.push_back(-1); //0th index is blocked

            minHeap = type;
        }

        void push(int d)
        {
            v.push_back(d);//start from back
            int idx = v.size() - 1;
            int parent = idx/2;

            //keep pushing to the top until we reach a root node or child > root in minHeap
            while(idx > 1 and compare(v[idx],v[parent])) // or v[idx] > v[parent] if min heap or v[idx] < v[parent] in case of max heap
            {
                swap(v[idx],v[parent]);
                idx = parent;
                parent = parent/2;
            } 
        }

        int get()//min element in case of min heap and max element in case of max heap
        {
            //gives the topmost element,i.e, first element in the array
            return v[1];
        }

        void pop()
        {
            swap(v[1],v[v.size()-1]);
            v.pop_back();//removed root node which is swapped to the last

            //heapify
             heapify(1);
        }

        bool empty()
        {
            return v.size()==1;
        }

};

int main()
{
    Heap h;
    int n;

    cin>>n;

    for(int i=0;i<n;i++){
        int no;
        cin>>no;
        h.push(no);
    }

    //  remove all elements
    while(!h.empty())
    {
        cout<<h.get()<<" ";
        h.pop();
    }

    return 0;
}

//Min heap I/P: 10 20 15 14 11 90

//for max heap, use Heap h(10,false)