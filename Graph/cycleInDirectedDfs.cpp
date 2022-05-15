#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int startingNode, vector<int> adj[], vector<int> visited, vector<int> dfsVisited){

    //have an visited and dfsVisited array
    visited[startingNode] = 1;
    dfsVisited[startingNode] = 1;

    //adj check
    for(auto it: adj[startingNode]){
        //if adj node viisted then chk colot
        if(!visited[it]){
            if(checkCycle(it, adj,visited, dfsVisited)) return true;
            else if(dfsVisited[it]){
                return true;
            }
        }
    }

    //delete nodes after visiting
    dfsVisited[startingNode] = 0;
    return false;
}

bool isCycle(int V, vector<int> adj[]){
    vector<int> visited(V+1,0);
    vector<int> dfsVisited(V+1, 0);
    for(int i=1;i<=V;i++){
        if(!visited[i]){
            //check for cycle
            if(checkCycle(i, adj, visited, dfsVisited)){
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
	    // adj[v].push_back(u); since it is directed graph
	}

    if(isCycle(n, adj)){
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"Cycle is not present"<<endl;
    }

	return 0;
}