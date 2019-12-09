//
// Created by Agnieszka on 09/12/2019.
//
//
// Created by Agnieszka on 08/12/2019.
//
#include <iostream>
#include <list>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <unordered_set>
#include <cstdint>
#include <limits>

using namespace std;
#define NIL 0
#define INF INT32_MAX
class Graph
{
    int nrOfEmp;
    int V;
    list<int> *adj;
    int *pairs, *dist;
public:
    Graph(int V, int nrOfEmp){
        this->V = V;
        this->adj = new list<int>[V+1];
        this->nrOfEmp = nrOfEmp;
        this->pairs = new int[V+1];
        this->dist = new int [V+1];
    }
    unordered_set<int> employees;
    void addEdge(int u, int v);
    bool bfs();
    void hopcroft();
    bool dfs(int u);
};
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add u to v’s list.
    adj[v].push_back(u);
}
//zzx 4 2 0 1 3 0 2 0 3 1 3
void Graph::hopcroft() {
    memset(pairs, NIL, (V+1)*sizeof(int));
    int result = 0;
    while(bfs()) {
//        cout << "next bfs\n";
        for(auto u: employees)
            if (pairs[u]==NIL && dfs(u))
                result++;
    }
    cout<<result<<"\n";
    for(auto i:employees){
        if(pairs[i]==NIL) continue;
        cout<<i-1<<" "<<pairs[i]-1<<"\n";
    }
//    return result;
}
bool Graph::bfs() {
    queue<int> q;
    for(auto emp: employees){
        if(pairs[emp]== NIL){
            dist[emp]=0;
            q.push(emp);
        }
        else
            dist[emp]=INF;
    }
    dist[NIL] = INF;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(dist[u]<dist[NIL]){
            for(auto neigh: adj[u]){
                if(dist[pairs[neigh]]==INF){
                    dist[pairs[neigh]] = dist[u]+1;
                    q.push(pairs[neigh]);
                }

            }
        }
    }
    for(auto it:employees){
//        cout<<"\n v nr "<<it;
//        cout<<"dist: "<<dist[it];
    }
    return dist[NIL]!=INF;
}
bool Graph::dfs(int u){
    if(u != NIL){
        for(auto neigh:adj[u]){
            if(dist[pairs[neigh]]==dist[u]+1){
                if(dfs(pairs[neigh])){
                    pairs[u] = neigh;
                    pairs[neigh] = u;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}
int main(){
    string name;
    cin>>name;
    int nrOfResidents, nrOfEmp, nrOfMeetings;
    bool isBipartite = true;
    cin>>nrOfResidents>>nrOfEmp;
    Graph g(nrOfResidents, nrOfEmp);
    for(int i=0;i<nrOfEmp;i++){
        int empNr;
        cin >> empNr;
        g.employees.insert(++empNr);  // change indexing from 1
    }
    cin>>nrOfMeetings;
    int emp,cit;
    while(nrOfMeetings--)
    {
        cin>>emp>>cit;
        g.addEdge(++emp,++cit);
        if (g.employees.find(cit) != g.employees.end()) {
            isBipartite = false;
        }
    }
    if(isBipartite){
        g.hopcroft();
    }
    else
        g.hopcroft();
}