#include<bits/stdc++.h>
using namespace std;

void dfsRun(int node, vector<int> &visited, vector<int> adj[], vector<int> &dfsTraversed){
    //store the current node as it gets travelled
    dfsTraversed.push_back(node);
    visited[node] = 1; //marked viisted

    //get adjacent nodes
    for(auto it: adj[node]){
        if(!visited[it]){
            //if not visited then same process i.e. rec call dfs
            dfsRun(it,visited, adj, dfsTraversed);
        }
    }
}

vector<int> dfs(int V, vector<int> adj[]){

    vector<int> dfsTraversed; // nodes traversed
    // visited array
    vector<int> visited(V+1,0);

    for(int i=1;i<=V;i++){
        if(!visited[i]){
            //recursive call to dfs
            dfsRun(i, visited, adj, dfsTraversed);
        }
    }


    return dfsTraversed;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<int> adj[n+1];

    //take edges input(m)
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> nodesTraversed = dfs(n, adj);
    for(auto it: nodesTraversed){
        cout<<it<<endl;
    }

    return 0;
}