#include<bits/stdc++.h>
using namespace std;

bool checkBipartite(int startingNode, vector<int> adj[], vector<int> colored){

    colored[startingNode] = 1;
    queue<int> q;
    q.push(startingNode);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        //for adj nodes
        for(auto it: adj[node]){
            //chk if adj node is colored or not
            if(colored[it]==-1) {//means not trvaersed yet
                //color alternatively
                colored[it] = 1 - colored[node];
                q.push(it);
            }
            //if already colored, then chk if correctly colored
            else if(colored[it]==colored[node]){
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[]){
    vector<int> colored(V,-1);
    for(int i=1;i<=V;i++){
        if(colored[i]==-1){
            //check for cycle
            if(checkBipartite(i,adj, colored)){
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

    if(isBipartite(m, adj)){
        cout<<"Bipartitie Graph"<<endl;
    }
    else{
        cout<<"Not a Bipartite Graph"<<endl;
    }

	return 0;
}