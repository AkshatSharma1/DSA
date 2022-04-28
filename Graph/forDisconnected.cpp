#include<iostream>
#include<queue>
using namespace std;

void printDfs(int** edges, int n, int sv, bool* visited){
    //cout the starting vertex
    cout<<sv<<" ";
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

//print bfs
void printBfs(int** edges, int n, int sv, bool* visited){
    //use a queue
    queue<int> pendingAdjacentVertices;

    pendingAdjacentVertices.push(sv);
    visited[sv] = true;
    //pop front tillnot empty
    while(!pendingAdjacentVertices.empty()){
        int currentVertex = pendingAdjacentVertices.front();
        pendingAdjacentVertices.pop();
        cout<<currentVertex<<" ";

        //find adjacebnt to curr
        for(int i=0;i<n;i++){

            //if i==curr
            if(i==currentVertex){
                continue;
            }

            //if edge b/w sv and curr and is not visited
            if(edges[currentVertex][i]==1 && !visited[i]){
                pendingAdjacentVertices.push(i);
                visited[i] = true;
            }
        }
    }
}

//DFS
void DFS(int** edges, int n){
    //Make a visites array
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    //now traverse the whole visited array and call for the printDfs function where the node is not marked as vovisted
    for(int i=0;i<n;i++){
        if(!visited[i]){
            //here the starting vertex will be the current node which is not marked as visited
            printDfs(edges,n,i,visited);
        }
    }

    //free up visited
    delete[] visited;
}

//BFS
void BFS(int** edges, int n){
    //Make a visites array
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    //now traverse the whole visited array and call for the printDfs function where the node is not marked as vovisted
    for(int i=0;i<n;i++){
        if(!visited[i]){
            //here the starting vertex will be the current node which is not marked as visited
            printBfs(edges,n,i,visited);
        }
    }

    //free up visited
    delete[] visited;
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
    cout<<"DFS: \n";
    DFS(edges, n);

    cout<<endl;
    //print bfs
    cout<<"BFS: \n";
    BFS(edges, n);

    //Now free up memory
    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete [] edges;
}