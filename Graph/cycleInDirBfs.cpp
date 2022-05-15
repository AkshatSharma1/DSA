#include<bits/stdc++.h>
using namespace std;

bool cyclicDirBfs(vector<int> adj[], int V){
    queue<int> q;
    vector<int> indegree(V,0);

    //find indegree of all
    for(int i=0;i<V;i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    //now push in the queue nodes with indegree 0
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    // //vector to store result
    // vector<int> sorted;
    int count = 0;

    //now do operations in th queue
    while(!q.empty()){
        //pop out the node and store in sorted and then chk for its adj nodes
        // if adj node's indegree is not zero then reduce by 1 and if 0 then push in queue
        int node = q.front();
        q.pop();
        count++;
        // sorted.push_back(node);

        //adj nodes
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }

    // return sorted;
    if(count==V) return false; //if allnodes are traversed linearly means no cycle
    return true;
}

//function for adding edge
// void addEdge(vector<int> adj[], int u, int v){
//     adj[u].push_back(v);
//     adj[v].push_back(u); //incase of undirected
// }

int main() {
	int n, m;
	cin >> n >> m; 
	
	// declare the adjacent matrix 
	vector<int> adj[n+1]; 
	
	// take edges as input 
	for(int i = 0;i<m;i++) {
	    int u, v; 
	    cin >> u >> v;
	    adj[u].push_back(v); 
	    // adj[v].push_back(u); since it is directed graph
	}

    if(cyclicDirBfs(adj, n)){
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"Cycle is not present"<<endl;
    }

	return 0;
}