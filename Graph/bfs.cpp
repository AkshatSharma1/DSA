#include<bits/stdc++.h>
using namespace std;

// V -> no. of nodes, adj[]->graph
vector<int> bfs(int V, vector<int> adj[]){
    vector<int> bfsTraversed; //traversed nodes array
    vector<int> visited(V+1,0); //visited array

    //outer for loop for traversing all the components
    for(int i=1;i<V;i++){
        //if not visited, then run bfs()
        if(!visited[i]){
            queue<int> q;
            q.push(i);
            visited[i] = 1;

            //print adjacent nodes of node present in queue till queue gets empty
            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfsTraversed.push_back(node);

                //find adjacent nodes of the curr ndoe from the adj list
                for(auto it: adj[node]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }
    }
    return bfsTraversed;
}

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

    vector<int> nodesTraversed = bfs(n, adj);
    for(auto it: nodesTraversed){
        cout<<it<<endl;
    }

	return 0;
}