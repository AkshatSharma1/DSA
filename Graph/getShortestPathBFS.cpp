#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

void getPath(int** edges, int v, bool *visited, int start, int end){
    
    if(start == end){
        cout<<start<<" ";
        return;
    }

    queue<int> q;

    visited[start] = true;
    q.push(start);

    //map to store the current element and the element from which it came that is its previous one
    map<int,int> mp;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int i=0;i<v;i++){
            if(!visited[i] and edges[curr][i]==1){

                if(i==end){
                    cout<<end<<" ";
                    mp[end] = curr;

                    int j = end;
                    while(j!=start){
                        cout<<mp[j]<<" ";
                        j = mp[j];
                    }

                    return;
                }
                else{
                    q.push(i);
                    visited[i] = true;
                    mp[i] = curr;
                }
            }
        }
    }

    int i = end;
    cout<<end<<" ";
    while(i!=start){
        cout<<mp[i]<<" ";
        i = mp[i];
    }
    

}

int main(){
    int v,e;
    cin>>v>>e;

    //edges matrix
    int** edges = new int*[v];
    for(int i=0;i<v;i++){
        edges[i] = new int[v];
        for(int j=0;j<v;j++){
            edges[i][j] = 0;
        }
    }

    //get the edges input
    for(int i=0;i<e;i++){
        int firstVertex, secondVertex;
        cin>>firstVertex>>secondVertex;

        edges[firstVertex][secondVertex] = 1;//edges between first and second
        edges[secondVertex][firstVertex] = 1;
    }

    //now make a boolean visited array
    bool* visited = new bool[v];
    for(int i=0;i<v;i++){
        visited[i] = false;
    }

    //now get the vertex input for which we have to check if path exists or not
    int v1, v2;
    cin>>v1>>v2;

    //now for v1 visited is marked
    visited[v1] = true;
    
    //get the path
    getPath(edges,v,visited,v1,v2);

    delete[] visited;

    return 0;

}