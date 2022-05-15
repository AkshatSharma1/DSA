#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int startingNode, int V, vector<int> adj[], vector<int> visited){

    // queue for storing node and its prev.
    // if prev and node's ifirst adj are same then no cycle
    // if prev and node's other adj are same then cycle
    queue<pair<int,int>> q;
    q.push({startingNode,-1});
    visited[startingNode] = 1;

    while(!q.empty()){
        int node = q.front().first;
        int prev = q.front().second;
        q.pop();

        //chk for adj
        for(auto it: adj[node]){
            if(!visited[it]){
                visited[it] = 1;
                q.push({it, node}); //prev will be the curr node
            }

            //if visited and prev not same then cycle
            else if(prev!=it){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]){
    vector<int> visited(V+1,0);
    for(int i=1;i<=V;i++){
        if(!visited[i]){
            //check for cycle
            if(checkCycle(i, V, adj, visited)){
                return true;
            }
        }
    }
    return false;
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
	    adj[v].push_back(u); 
	}

    if(isCycle(n, adj)){
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"Cycle is not present"<<endl;
    }

	return 0;
}