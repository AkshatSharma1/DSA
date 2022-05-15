// Algorithm for finding the shortest path between nodes in a graph
/*Valid for:
    -> Both directed and undirected
    -> Non-negative weights must
    -> connected graph
*/
#include<bits/stdc++.h>
using namespace std;

void dijktra(int src, vector<int> &distCov, vector<pair<int,int>> adj[]){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    distCov[src] = 0;
    //dist cov to reach src = 0
    pq.push({0,src});

    //find the dist travelled for nodes in the prior queue
    while(!pq.em pty()){
        int distTrav = pq.top().first;
        int prevNode = pq.top().second;
        pq.pop();

        //chk for adj nodes
        //make an iterator to traverse pair adj list
        vector<pair<int,int>>:: iterator it;
        for(it = adj[prevNode].begin();it!=adj[prevNode].end();it++){
            int nextNode = it->first;
            int nextDist = it->second;

            //chk if prev way of travelling has less value or not
            if(distCov[nextNode] > distCov[prevNode] + nextDist){
                //if bigger, then
                distCov[nextNode] = distCov[prevNode] + nextDist;

                //push in pq the new pair
                pq.push({distCov[nextNode], nextNode});
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> adj[n+1];

    int src;
    cin>>src;

    //take input edges
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    // distance vector
    vector<int> distCov(n+1, INT_MAX);

    // calling dijktra function
    dijktra(src, distCov, adj);

    cout << "The distances from source " << src << " are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distCov[i] << " ";
    cout<<endl;

    return 0;
}