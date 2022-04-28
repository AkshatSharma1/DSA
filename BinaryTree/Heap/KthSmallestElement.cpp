//Find Kth smallest element in row and column wise sorted array
#include<bits/stdc++.h>
using namespace std;

class HeapNode{
    public:
        int val;
        int r;//row index
        int c;//col index
        
};

// bool compare(HeapNode a, HeapNode b)
// {
//     //max heap case 
//     return a.value>b.value;
// }


// void heapify(HeapNode arr[],int i,int n)
// {
//     int left = 2*i;
//     int right = left + 1;

//     int min_index = i;
//     int last_idx = n-1;

//     //now if the child of the parent nodes exist in the array then heapify the tree
//     if(left<=last_idx and compare(arr[left],arr[min_index]))
//     {
//             min_index = left;
//     }
//     if(right<=last_idx and compare(arr[right],arr[min_index]))
//     {
//             min_index = right;
//     }
//     //swwap min index and parent index
//     if(min_index!=i)
//     {
//             swap(arr[i],arr[min_index]);
//             //rec call
//             heapify(arr,min_index,n);
//     }
// }

void minHeapify(HeapNode harr[], int i, int n)
{
    int l = i * 2 + 1;
    int r = i * 2 + 2;
     if(l < n && r<n && harr[l].val < harr[i].val && harr[r].val < harr[i].val){
            HeapNode temp=harr[r];
            harr[r]=harr[i];
            harr[i]=harr[l];
            harr[l]=temp;
            minHeapify(harr ,l,n);
            minHeapify(harr ,r,n);
        }
          if (l < n && harr[l].val < harr[i].val){
            HeapNode temp=harr[i];           
            harr[i]=harr[l];
            harr[l]=temp;
            minHeapify(harr ,l,n);
        }
}

int kthSmallestElement(int mat[4][4],int n,int k) {

    //base case: if k<0 and k>=n*n
    if(k<0 and k>=n*n) return INT_MAX;

    //min heap
    HeapNode arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = {mat[0][i],0,i}; //0 is row index and i is column index
    }

    HeapNode result;
    for(int i=0;i<k;i++)
    {
        result = arr[0];

        //push column value of root.If end value push INT_Max
        int nextColVal = (result.r < (n-1))? mat[result.r+1][result.c] : INT_MAX;

        //update root
        arr[0] = {nextColVal,(result.r)+1,result.c};

        minHeapify(arr,0,n);
    }
    

return result.val;
}

int main()
{
    int mat[4][4] = {
        { 10, 20, 30, 40 },
        { 15, 25, 35, 45 },
        { 25, 29, 37, 48 },
        { 32, 33, 39, 50 },
    };
    cout << "7th smallest element is "
        << kthSmallestElement(mat, 4, 7);
    return 0;
}