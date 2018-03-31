/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <utility>
#include "GPS.h"

using namespace std;

 class Edge;
 class Graph;
 class Vertex;


/****************** Provided structures  ********************/


class Vertex {
    GPS info;                // contents
    vector<Edge> adj;  // list of outgoing edges
    bool visited;          // auxiliary field used by dfs and bfs
    bool processing;       // auxiliary field used by isDAG
    int indegree;          // auxiliary field used by topsort

    void addEdge(long long id, double w);
    bool removeEdgeTo(long long id);

public:
    Vertex(GPS in);
    GPS getInfo() const;
    friend class Graph;
};


class Edge {
    long long id;
    double weight;         // edge weight
public:
    Edge(long long id, double w);
    friend class Graph;
    friend class Vertex;
};


class Graph {
    unordered_map<long long, Vertex *> vertexSet;    // vertex set

    void dfsVisit(Vertex *v,  vector<GPS> & res) const;
    bool dfsIsDAG(Vertex *v) const;
public:
    int getNumVertex() const;
    bool addVertex(const long long &id, const GPS &in);
    bool removeVertex(const long long &id);
    bool addEdge(const long long &sourcid, const long long &destid);
    bool addDoubleEdge(const long long &sourcid, const long long &destid);
    bool removeEdge(const long long &sourcid, const long long &destid);
    vector<GPS> dfs() const;
    vector<GPS> bfs(const long long &id) const;
    vector<GPS> topsort() const;
    int maxNewChildren(const long long &id, GPS &inf) const;
    bool isDAG() const;
    Vertex *findVertex(const long long &id) const;
    void listVertices() const;
    int size() const;
    pair<long long, Vertex*> getClosestGPS(const GPS &in) const;
    double dijkstra(const long long &startid, const long long &endid);
};


#endif /* GRAPH_H_ */