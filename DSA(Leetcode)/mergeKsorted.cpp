//using heaps
#include<bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin>>k;

    //given a 2d vector for k vectors
    vector<vector<int>> vec(k);

    //input the vectors
    for(int i=0;i<k;i++){
        int n;
        cin>>n; //size of each vector
        vec[i] = vector<int>(n);

        for(int j = 0;j<n;j++){
            cin>>vec[i][j];
        }
    }

    //now make a vector, index vector to store index of each vector element which is inderted
    vector<int> indx(k,0);
    //vector to store result
    vector<int> ans;

    //min heap to perform main calcs
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    //now insert the first element of all sorted arrays into min heap and then accoring to min heap property elements will be in sorted order
    //then pop the top of min heap everytime as it will be in sorted order
    for(int i=0;i<k;i++){
        pair<int,int> p(vec[i][0], i);
        pq.push(p);
    }

    while(!pq.empty()){
        pair<int, int> x = pq.top();
        pq.pop();
        ans.push_back(x.first);

        //now if the index of popped element is smaller than the vec size then push
        if(indx[x.second]+1 < vec[x.second].size()){
            pair<int,int> pa(vec[x.second][indx[x.second]+1], x.second);
            pq.push(pa);
        }
        //else if popped element index is greater than size of sorted array it is taken from tehn do nothing
        indx[x.second]++;
    }

    //print the answer
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}