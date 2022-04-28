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
void printBfs(int** edges, int n, int sv){
    //use a queue
    queue<int> pendingAdjacentVertices;
    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

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
    printDfs(edges, n, 0, visited);

    cout<<endl;
    //print bfs
    cout<<"BFS: \n";
    printBfs(edges, n, 0);

    //Now free up the memory
    delete[] visited;
    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete [] edges;
}