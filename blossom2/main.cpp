//
// Created by Agnieszka on 08/12/2019.
//
#include <iostream>
#include <list>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <iterator>
#include <string>
using namespace std;
class Graph
{
    list<int> *adj;
public:
    explicit Graph(int V){
        this->adj = new list<int>[V+1];
    }
    unordered_set<int> employees;
    void addEdge(int u, int v);
};
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add u to v’s list.
    adj[v].push_back(u);
}
int main(){
    string name;
    cin>>name;
    int nrOfResidents, nrOfEmp, nrOfMeetings;
    bool isBipartite = true;
    cin>>nrOfResidents>>nrOfEmp;
    Graph g(nrOfEmp);
    for(int i=0;i<nrOfEmp;i++){
        int empNr;
        cin >> empNr;
        g.employees.insert(empNr);
    }
    cin>>nrOfMeetings;
    int emp,cit;
    while(nrOfMeetings--)
    {
        cin>>emp>>cit;
        g.addEdge(emp,cit);
        if (g.employees.find(cit) != g.employees.end()) {
            isBipartite = false;
        }
    }
    if(isBipartite){
        cout<<"hopcroft";
    }
    else
        cout<<"blossom";
}