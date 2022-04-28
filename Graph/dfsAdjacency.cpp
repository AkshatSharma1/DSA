#include<iostream>
using namespace std;

void printDfs(int** edges, int n, int sv, bool* visited){
    //cout the starting vertex
    cout<<sv<<endl;
    //mark the visited vertex
    visited[sv] = true;

    for(int i=0;i<n;i++){
        if(i==sv){
            continue;
        }

        //if edges is from starting vertex to i then call on this one also
        if(edges[sv][i]==1){
            if(visited[i]){
                continue;
            }
            printDfs(edges, n, i, visited);
        }
    }
}

int main(){
    //vertices(n) and edges(E)
    int n,e;
    cin>>n>>e;

    int **edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }

    //now input the edges
    for(int i=0;i<e;i++){
        int f,s; //first & second edge
        cin>>f>>s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    //keep a visited array
    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    //Dfs print the edges
    // 0 -> starting edge
    printDfs(edges, n, 0, visited);
}