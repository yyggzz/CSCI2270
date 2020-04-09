#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct vertex;

struct adjVertex
{
    vertex* v;
};

struct vertex
{
    int data;
    int distance;
    bool visited;
    vector<adjVertex> adj;
};

vector<vertex*> vertices; // global

// Function prototypes
vertex* findVertexPointer(int x);
void addEdge(int u, int v);
void BFSTraverse(vertex* u);
void countNodesWithDist(int u, int dist);

int main()
{
    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(2, 5);
    addEdge(4, 5);
    addEdge(3, 5);

    countNodesWithDist(3, 2);

    return 0;
}

vertex* findVertexPointer(int x)
{
    for(int i = 0; i < vertices.size(); i++) {
        if (vertices[i]->data == x) {
            return vertices[i];
        }
    }
}

void addEdge(int u, int v)
{
    vertex* a = findVertexPointer(u);
    vertex* b = findVertexPointer(v);

    if (!a) {
        a = new vertex;
        a->data = u;
        a->distance = 0;
        a->visited = false;
        vertices.push_back(a);
    }

    if (!b) {
        b = new vertex;
        b->data = v;
        b->distance = 0;
        b->visited = false;
        vertices.push_back(b);
    }

    adjVertex av1;
    av1.v = b;
    a->adj.push_back(av1);

    adjVertex av2;
    av2.v = a;
    b->adj.push_back(av2);
}

void BFSTraverse(vertex* u)
{
    for(vertex* i : vertices) {
        i->distance = 0;
        i->visited = false;
    }

    // Use the STL queue to keep track of visited vertices
    queue<vertex*> q;

    // Enqueue the starting vertex
    u->visited = true;
    q.push(u);    // enqueue

    // Need another vertex pointer
    vertex *n;

    while(!q.empty()){
        n = q.front(); // peek 
        q.pop();       // dequeue

        // scan the adj list of each element in Q
        for(int x = 0; x < n->adj.size(); x++)
        {
            // check if vertex visited
            if(n->adj[x].v->visited == false)
            {
                n->adj[x].v->visited = true;
                n->adj[x].v->distance = n->distance + 1;
                q.push(n->adj[x].v);
            }
        }
    }
}

void countNodesWithDist(int u, int dist)
{
    BFSTraverse(findVertexPointer(u));
    for(int i = 0; i < vertices.size(); i++) {
        if (vertices[i]->distance == dist) 
            cout << vertices[i]->data << " ";
    }
    cout << endl;
}