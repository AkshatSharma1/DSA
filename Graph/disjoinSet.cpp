// used to find out whether the two nodes belongs to same component or not
// opeartions: 
//     -> findParent()
//     -> Union()

#include<bits/stdc++.h>
using namespace std;

int parent[100000];
int rank[100000];

void makeSet(){
    for(int i=0;i<=n;i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int node){
    if(node == parent){
        return node;
    }

    return parent[node] = findParent(parent[node]);
}

void union(int u, int v){
    u = findParent(u);
    v = findParent(v);

    if(rank[u]<rank[v]){
        parent[u] = v;
    }
    else if(rank[v]<rank[u]){
        paremt[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

int main(){
    makeSet();
    int m;
    cin>>m;

    while(m--){
        int u,v;
        cin>>u>>v
        union(u,v);
    }

    //check if components connectd or not
    if(findParent(4)!=findParent(6)){
        cout<<"Diff compon";
    }
    else{
        cout<<"Same"
    }
}
