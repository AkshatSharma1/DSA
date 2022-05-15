// Unit weight
// Q: find shortest distance between src to any other node
//Pre-req: use queue ds to store nodes and a distanceCovered array
#include<bits/stdc++.h>
using namespace std;

vector<int> shortestDistance(int src, vector<int> &distCov,vector<int> adj[]){
    queue<int> q;
    distCov[src] = 0;
    q.push(src);

    //for adj nodes
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            //note down the min of curr and prev distCov for each node
            if(distCov[node]+1<distCov[it]){
                distCov[it] = distCov[node]+1;
                q.push(it);
            }
        }
    }
    return distCov;
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    // int src, dest;
    // cin>>src>>dest;
    int src;
    cin>>src;

    //distCov vector: initially filled with Infinity
    vector<int> distCovered(n+1, INT_MAX);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        addEdge(adj, u,v);
    }

    vector<int> ans = shortestDistance(src, distCovered, adj);
    // cout<<ans<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
