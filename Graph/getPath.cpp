#include<iostream>
#include<vector>
using namespace std;

bool getPath(int** edges, int v, bool *visited, int start, int end, vector<int>&path){

    path.push_back(start);
    //if start is end tehn return true
    if(start==end){
        // return true;
        return true;
    }

    //check for path
    for(int i=0;i<v;i++){
        if(!visited[i] and edges[start][i]==1){
            visited[i] = true;
            //rec check
            if(getPath(edges, v, visited, i, end, path)){
                return true;
            }
        }
    }
    path.pop_back();
    return false;

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
    vector<int> res;
    getPath(edges,v,visited,v1,v2, res);

    //print the path if size()!=0
    if(res.size()!=0){
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
    }
    else{
        return 0;
    }


}