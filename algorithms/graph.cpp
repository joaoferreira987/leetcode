#include <algorithm>
#include <iostream>
#include <list>

using namespace std;


class Graph {

    int numVertices;
    list<int> *adjLists;
    bool is_directed;
    
    public:
    Graph(int vertices, bool directed){
        numVertices = vertices;
        adjLists = new list<int>[vertices];
        is_directed = directed;

    } //constructor
    void addEdge(int src, int dest){

        cout << "Adding edge from " << src << " to " <<  dest << "\n";

        adjLists[src].push_front(dest);

        if(!is_directed){

            cout << "Adding edge from " << dest << " to " <<  src << "\n";
            adjLists[dest].push_front(src);
        }



    }

    int getVertices(){
        return numVertices;
    }
    list<int> * getAdjLists(){
        return adjLists;
    }

};