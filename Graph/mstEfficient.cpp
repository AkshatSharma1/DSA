#include<bits/stdc++.h>
using namespace std;

int main(){

    int N,m;
    cin>>N>>m;

    // vector to store graph edges
    vector<pair<int,int>> adj[N];

    int u,v,wt;

    for(int i=0;i<m;i++){
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    } 

    // Take 3 arrays for storing keys, isMst, parent
    vector<int> key(N,INT_MAX);
    vector<bool> mstSet(N, false);
    vector<int> parent(N,0);

    //min heap for getting min key always(min edge weight)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    
    //initial values
    key[0] = 0;
    parent[0] = -1;
    pq.push({0,0}); //initially

    //chk for val in queue
    while(!pq.empty()){

        //this always gives the min edge weight not part of mst
        int u = pq.top().second;
        pq.pop();

        mstSet[u] = true; //set truue when added to mst

        //chk for adj nodes
        for(auto it: adj[u]){
            int v = it.first;
            int wt = it.second;

            //if not set
            if(!mstSet[v] && wt<key[v]){
                parent[v] = u;
                key[v] = wt;
                pq.push({key[v], v});
            }
        }
    }

    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
        
    return 0;

}