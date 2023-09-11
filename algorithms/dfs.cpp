
#include <iostream>
#include <iostream>
#include <list>
#include <vector>
#include "graph.cpp"

using namespace std;

void dfs_preorder(int vertex, int total_vertices, list<int>* adjLists, vector<bool> &visited){

    cout << "Visited vertex " << vertex << endl;
    visited[vertex] = true;

    
    for(int v : adjLists[vertex]){
        if(!visited[v]){
            dfs_preorder(v,total_vertices,adjLists,visited);
        }
    }

    return;



}

int main() {
    Graph g(4,false);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    int total_vertices = g.getVertices();
    list<int>* adjLists =  g.getAdjLists();
    vector<bool> visited(total_vertices,false);

    dfs_preorder(2,total_vertices,adjLists,visited);



    return 0;

}