//Given weighted graph DAG
#include<bits/stdc++.h>
using namespace std;

void findTopoSort(int node, vector<int> &visited, stack<int> &st, vector<pair<int,int>>adj[]){
    visited[node] = 1;
    for(auto it: adj[node]){
        if(!visited[it.first]){
            findTopoSort(it.first, visited, st, adj);
        }
    }
    st.push(node);
}

vector<int> shortestDistance(int src, int V,vector<int>&dist, vector<pair<int,int>> adj[]){
    vector<int> visited(V, 0);
    stack<int> st;

    for(int i=0;i<V;i++){
        if(!visited[i]){
            findTopoSort(i, visited, st, adj);
        }
    }
    dist[src] = 0;

    //do operations for elements in stack
    while(!st.empty()){
        int node = st.top();
        st.pop();

        //initial check(done to make sure we have a starting node available)
        //if non inf that means we have reached the curr node
        if(dist[node]!=INT_MAX){
            for(auto it: adj[node]){
                if(dist[node] + it.second < dist[it.first]){
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }
    return dist;
}

void addEdge(vector<pair<int,int>> adj[], int u, int v,int wt){
    //take input weight also
    adj[u].push_back({v,wt});
    // adj[v].push_back(u);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];

    int src;
    cin>>src;

    //distCov vector: initially filled with Infinity
    vector<int> distCovered(n, INT_MAX);

    for(int i=0;i<m;i++){
        int u,v, wt;
        cin>>u>>v>>wt;
        addEdge(adj, u,v, wt);
    }

    vector<int> ans = shortestDistance(src, n, distCovered, adj);
    // cout<<ans<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
