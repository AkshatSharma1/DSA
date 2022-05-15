// Pre-req: stack
#include<bits/stdc++.h>
using namespace std;

vector<int> topoSortBfs(vector<int> adj[], int V, vector<int> &indegree){
    queue<int> q;
    // vector<int> indegree(V,0);

    //find indegree of all components
    // for(int i=0;i<V;i++){
    //     for(auto it: adj[i]){
    //         indegree[it]++;
    //     }
    // }

    //now push in the queue nodes with indegree 0
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    //vector to store result
    vector<int> sorted;

    //now do operations in th queue
    //remove vertex from the queue
    while(!q.empty()){
        //pop out the node and store in sorted and then chk for its adj nodes
        // if adj node's indegree is not zero then reduce by 1 and if 0 then push in queue
        int node = q.front();
        q.pop();
        sorted.push_back(node);

        //adj nodes
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }

    return sorted;
}

//we can also detect cycle in directed graph using Topo sort by just keeping a count variable of visited nodes.
// If visited nodes are not equal to initial nodes then cycle

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    // adj[v].push_back(u); //incase of undirected
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<int> adj[n]; 

    //indegree vector for topo sorting (initialised with zero)
    vector<int> indegree(m,0);

    // take edges as input (m->edges, n->vertices)
	for(int i = 0;i<m;i++) {
	    int u, v; 
	    cin >> u >> v;
        indegree[v]++;
        addEdge(adj,u,v);
	}

    vector<int> res = topoSortBfs(adj, n, indegree);

    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }

    return 0;
}