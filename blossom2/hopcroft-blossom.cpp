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
#include <unordered_map>
#include <cstdint>
#include <limits>

using namespace std;
#define NIL 0
#define INF INT32_MAX
struct Node{
    int n;
    list<Node*> children;
    Node *parent;
    explicit Node(int v, Node* parent){
        this->n = v;
        this->parent= parent;
    }
    int dist_to_root(int dist=0){
        if(parent== nullptr) return dist;
        return dist_to_root(dist+1);
    }
};
class Tree
{
    Node *head;
public:
    unordered_map<int, Node*> all_vs;
    explicit Tree(Node* v){
        this->head = v;
        all_vs[v->n] = head;
    }
    // add connection from existing node u to new node v
    void add_connection(int u, int v){
        if(all_vs.find(u) == all_vs.end()){
            throw "parent node not in the tree";
        }
        if(all_vs.find(v) != all_vs.end())
            throw "child already in tree";
        Node* parent = all_vs.at(u);
        Node *child = new Node(v, parent);
        parent->children.push_back(child);
    }

};
class Graph
{
    int V, L; // nr of vertices and edges
    list<int> *adj;
    int *pairs, *dist; // pairs[i] - only 1 vertex from a pair is not NIL
    int result;
public:
    explicit Graph(int V, int L){
        this->result = 0;
        this->V = V;
        this->L = L;
        this->adj = new list<int>[V+1];
        this->pairs = new int[V+1];
        this->dist = new int [V+1];
    }
    unordered_set<int> employees;
    void addEdge(int u, int v);
    bool bfs();
    bool dfs(int u);
    void hopcroft();
    void print_answer();
    void blossom();
    void find_max_matching();
    list<int> find_aug_path();
    list<int>find_exposed(unordered_map<int, bool> edges_in);
    int find_unmarked_w_even_dist( unordered_map<int, Tree*> *forest, bool*marked);
    int edge_hash(int u, int v);
};
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void Graph::find_max_matching(){
    list<int> p = find_aug_path();
    if(!p.empty()){
        find_max_matching();
    }
}
list<int> Graph::find_aug_path() {
//    unordered_map<int, Tree*> forest;
    Node** nodes = new Node*[V+1];
    for(int i=1;i<=V;i++){
        nodes[i] = new Node(i, nullptr);
    }

    bool* marked = new bool[V+1];
    memset(marked, false, (V+1)* sizeof(bool));

    bool* exposed = new bool[V+1];  // all vertices not incident with curr matching
    memset(exposed, true, (V+1)* sizeof(bool));

    // mark edges in current matching
    unordered_map<int, bool> edges_in;
    for(auto i:employees){
        if(pairs[i]!=NIL){
//            marked[i] = marked[pairs[i]] = true;
            exposed[i]=exposed[pairs[i]] = false;
            edges_in[edge_hash(i, pairs[i])]= true;
        }
    }
    // create a singleton tree { v } and add the tree to F
//    for(int v=1; v<=V;v++){
//        if(!exposed[v]) continue;
//        forest[v]=new Tree(v);
    }
    int v = find_unmarked_w_even_dist(&forest, marked);
    while(v != NIL){
        int edge = find_unmarked_edge(v);
        while(edge != NIL){
            int w = get_other(edge, v);  // get other vertex from edge
            if(w not in forest){
                // w is matched, so add edge and w's matched edge to F
                int x = pairs[w];
                forest[v]->add_connection(v, w);
                forest[v]->add_connection(w, x);
            }
            else{
                if()
            }
            edge = find_unmarked_edge(v);
        }
        v = find_unmarked_w_even_dist(&forest, marked);
    }

}
int Graph::find_unmarked_w_even_dist( unordered_map<int, Tree*> *forest, bool*marked){
    for(auto& tree_entry:*forest){
        unordered_map<int, Node*> nodes = tree_entry.second->all_vs;
        for(auto& node_entry: nodes){
            Node* v = node_entry.second;
            // check if v unmarked
            if(marked[v->n]) continue;
            // if distance( v, root( v ) ) even
            if(v->dist_to_root()%2==0){
                return node_entry.second->n;
            }
        }
    }
    return NIL;
}

list<int> Graph::find_exposed(unordered_map<int, bool> edges_in){
    list<int> exposed;
    for(int i=1; i<=V;i++){
        bool exp = true;
        for(auto neigh:adj[i]){
            if(edges_in.find(edge_hash(i, neigh)) != edges_in.end()){
                exp = false;
            }
        }
        if(exp){
            exposed.push_back(i);
        }
    }
    return exposed;
}
int Graph::edge_hash(int u, int v){
    if(v>u) swap(u, v);
    return u*V + v;
}
void Graph::blossom() {
    hopcroft();  // any matching
    // add reference from each vertex in pair to its partner
    for(auto i : employees){
        if(pairs[i]!=NIL){
            pairs[pairs[i]] = i;
        }
    }
    find_max_matching();
}
void Graph::print_answer() {
    cout<<result<<"\n";
    for(auto i:employees){
        if(pairs[i]==NIL) continue;
        cout<<i-1<<" "<<pairs[i]-1<<"\n";
    }
}
void Graph::hopcroft() {
    memset(pairs, NIL, (V+1)*sizeof(int));
    while(bfs()) {
        for(auto u: employees)
            if (pairs[u]==NIL && dfs(u))
                result++;
    }
    for(auto i:employees){
        if(pairs[i]==NIL) continue;
        pairs[pairs[i]] = NIL;  // do not count same connection twice
    }
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
    Graph g(nrOfResidents, nrOfMeetings);
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
        g.print_answer();
    }
    else{
        g.blossom();
        g.print_answer();
    }

}