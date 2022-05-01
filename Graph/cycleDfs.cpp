#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int startingNode, int , vector<int> adj[], vector<int> visited){

    visited[startingNode] = 1;
    //check for adj and then if not visited do rec call
    for(auto it: adj[startingNode]){
        if(!visited[it]){
            if(checkCycle(it, startingNode, visited, adj)){
                return true;
            }
        }
        // if any adj node other than prev node aleady visited then it means there is a cycle
        else if(parent!=it){
            return true;
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

    if(isCycle(m, adj)){
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"Cycle is not present"<<endl;
    }

	return 0;
}