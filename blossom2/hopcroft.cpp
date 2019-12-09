//
// Created by Agnieszka on 08/12/2019.
//
#include <iostream>
#include <list>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
#define NIL -1
#define INF INT_MAX
class BiGraph
{
    int left, right;
    list<int> *adj;
    int *pairU, *pairV, *dist;
public:
    BiGraph(int left, int right){
        this->left = left;
        this->right = right;
        this->adj = new list<int>[left+1];
        pairU = new int[left];
        pairV = new int[right];
        dist = new int[left];
        memset(pairU, NIL, left*sizeof(int));
        memset(pairV, NIL, right*sizeof(int));
        memset(dist, NIL, left*sizeof(int));
    }
    bool bfs(); // true if there is an augmenting path
    bool dfs(int start); // adds augm path starting with start (if there exist one)
    int hopcroftKarp();
    void addEdge(int u, int v);
};
void BiGraph::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add u to v’s list.
}
int BiGraph::hopcroftKarp() {
    return 0;
}
bool BiGraph::bfs() {
    queue<int> q;
    for(int u=0;u<left;u++){
        if(pairU[u]== NIL){
            dist[u]=0;
            q.push(u);
        }
        else
            dist[u]=INF;
    }

    return false;

}
bool BiGraph::dfs(int start) {
    return false;
}
int run_hopcroft(){
    return 0;
}

