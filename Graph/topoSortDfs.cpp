// Pre-req: stack
#include<bits/stdc++.h>
using namespace std;

void topoSortDfs(int node, vector<int> adj[], vector<int> &visited, stack<int> &order){
    visited[node] = 1;

    //find adj nodes
    for(auto it: adj[node]){
        // if the adj node is not visited
        if(!visited[it]){
            //call the dfs for that and when called push the node in the stack
            topoSortDfs(it, adj, visited, order);
        }
    }

    //when dfs call over then push node in the stack
    order.push(node);
}

vector<int> topoSort(vector<int> adj[], int V){
    stack<int> order; //order of values
    vector<int> visited(V,0);

    for(int i=0;i<V;i++){
        if(!visited[i]){
            topoSortDfs(i, adj, visited, order);
        }
    }

    //now vector to store result
    vector<int> sorted;
    while(!order.empty()){
        sorted.push_back(order.top());
        order.pop();
    }

    return sorted;
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    // adj[v].push_back(u); //incase of undirected
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<int> adj[n+1]; 

    // take edges as input 
	for(int i = 0;i<m;i++) {
	    int u, v; 
	    cin >> u >> v;
        addEdge(adj,u,v);
	}

    vector<int> res = topoSort(adj, n);

    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }

    return 0;
}