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
#include<vector>
#include <deque>

using namespace std;
#define NIL 0
#define INF INT32_MAX
int edge_hash(int u, int v, int V){
    if(v>u) swap(u, v);
    return u*V + v;
}
pair<int, int> get_vertices(int edge, int V){
    return make_pair(edge%V, edge/V);
}
int get_other(int edge, int v, int V){
    int u = edge%V, w = edge/V;
    return u==v ? w : u;
}
struct Node{
    int n;
    list<Node*> children;
    Node *parent;
    explicit Node(int v, Node* parent){
        this->n = v;
        this->parent= parent;
    }
    int dist_to_root(int dist=0){
        if(parent== this) return dist;
        return dist_to_root(dist+1);
    }
    Node* find_root(){
        if(parent==this) return this;
        return parent->find_root();
    }
    // returns hashes of edges on path this->other
    deque<int>* path_to_other(Node* other, int V, unordered_set<int> *active_vs){
        int diff = other->dist_to_root() - this->dist_to_root();
        deque<int> *pfurther = new deque<int>;
        deque<int> *pcloser = new deque<int>;
        Node *further;
        Node *closer;
        active_vs->erase(other->n);
        bool this_further;
        if(diff>0){
            this_further = false;
            further = other;
            closer = this;
        } else{ // diff<=0
            this_further = true;
            further = this;
            closer = other;
        }
        diff = abs(diff);
        while(diff > 0){
            diff--;
            pfurther->push_back(edge_hash(further->n,further->parent->n, V));
            further = further->parent;
            active_vs->erase(further->n);
        }
        // now both at same lvl
        while(further != closer){
            pfurther->push_back(edge_hash(further->n, further->parent->n, V));
            pcloser->push_back(edge_hash(closer->n, closer->parent->n, V));
            further = further->parent;
            closer = closer->parent;
            active_vs->erase(further->n);
            active_vs->erase(closer->n);
        }
        if(this_further){
            for(auto it = pcloser->rbegin(); it != pcloser->rend(); ++it)
                pfurther->push_back(*it);
            return pfurther;
        }else{
            for(auto it = pfurther->rbegin(); it != pfurther->rend(); ++it)
                pcloser->push_back(*it);
            return pcloser;
        }
    }
};

class Graph
{
    int V; // nr of vertices and edges
    unordered_set<int> *adj;
    int *pairs, *dist; // pairs[i] - only 1 vertex from a pair is not NIL
    int result;
public:
    explicit Graph(int V){
        this->result = 0;
        this->V = V;
        this->adj = new unordered_set<int>[V+1];
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
    void contract(deque<int> edges, int v);
    int find_unmarked_w_even_dist( Node** nodes, bool*marked);
    int find_other_vertex_from_unmarked_edge_with(int v, unordered_map<int, bool> edge_marked);
    list<int> lift_p(list<int> p_prim, int v, deque<int> bloss);
    list<int> path_in_blossom(deque<int> bloss, int v, int next_in_path );
    void augment_M_along_path(list<int> path);
    // debug
    void print_pairs();
};
void Graph::addEdge(int u, int v)
{
    adj[u].insert(v);
    adj[v].insert(u);
}
void Graph::find_max_matching(){
    list<int> p = find_aug_path();
    if(!p.empty()){
        cout<<"found aug path ";
        for(auto v: p) cout<<v<<" ";
        augment_M_along_path(p);
        find_max_matching();
    }
}
void Graph::augment_M_along_path(list<int> path) {
    auto it = path.begin();
    int prev = *it;
    bool even=true;
    for(++it; it != path.end(); it++){
        if(even){
            pairs[prev] = *it;
            pairs[*it] = prev;
        }else{
            pairs[prev] = pairs[*it] = NIL;
        }
        prev = *it;
        even = !even;
    }
    result++;
}
list<int> Graph::find_aug_path() {  // returns path as list of vertices
    // if node->parent is null -> node not in forest
    // if node->parent = self -> tree root
    Node** nodes = new Node*[V+1];
    for(int i=1;i<=V;i++){
        nodes[i] = new Node(i, nullptr);
    }

    bool* v_marked = new bool[V+1];
    memset(v_marked, false, (V+1)* sizeof(bool));

    bool* exposed = new bool[V+1];  // all vertices not incident with curr matching
    memset(exposed, true, (V+1)* sizeof(bool));

    // mark edges in current matching
    unordered_map<int, bool> edge_marked;
    for(auto i:employees){
        if(pairs[i]!=NIL){
            exposed[i]=exposed[pairs[i]] = false;
            edge_marked[edge_hash(i, pairs[i], V)]= true;
            cout<<"edge "<<i<<" "<<pairs[i]<<" is used.";
        }
    }
    // create a singleton tree { v } and add the tree to forest for each exposed v
    for(int v=1; v<=V;v++){
        if(!exposed[v]) continue;
        nodes[v]->parent = nodes[v];
    }
    int v = find_unmarked_w_even_dist(nodes, v_marked);
    while(v != NIL){
        cout<<"found unmarked w even dist to root "<<v;
        // find unmarked edge e(v,w)
        int w = find_other_vertex_from_unmarked_edge_with(v, edge_marked);
        while(w != NIL){
            cout<<"found unmarked edge"<<v<<" "<<w;
            if(nodes[w]->parent == nullptr){ // if w not in forest
                // w is matched, so add edge and w's matched edge to F
                int x = pairs[w];
                nodes[v]->children.push_back(nodes[w]);
                nodes[w]->children.push_back(nodes[x]);
            }
            else{
                if(nodes[w]->dist_to_root() %2 == 0){
                    if(nodes[w]->find_root() != nodes[v]->find_root()){
                        // Report an augmenting path in F ∪{ e }.
//                        P ← path ( root( v ) → ... → v ) → ( w → ... → root( w ) )
                        list<int> path;
                        Node *next_v = nodes[v];
                        while(next_v->parent != next_v){
                            path.push_front(next_v->n);
                            next_v = next_v->parent;
                        }
                        path.push_front(next_v->n);

                        Node *next_w = nodes[w];
                        while(next_w->parent != next_w){
                            path.push_back(next_w->n);
                            next_w = next_w->parent;
                        }
                        path.push_back(next_w->n);
                        return path;
                    }
                    // Contract a blossom in G and look for the path in the contracted
//                    B ← blossom formed by e(v,w) and edges on the path v → w in T
                    unordered_set<int> active_vs;
                    for(int i=1;i<=V;i++) active_vs.insert(i);
                    deque<int> *bloss = nodes[v]->path_to_other(nodes[w], V, &active_vs);
                    bloss->push_back(edge_hash(v, w, V));
                    // TODO set of active vert?

                    //                    G’, M’ ← contract G and M by B
                    Graph* g_prim = new Graph(V); // auto*
                    g_prim->pairs = this->pairs;
                    for(int i=1; i<=V;i++)
                        g_prim->adj[i] = this->adj[i]; // TODO copy or ref??
                        // contract to v
                    g_prim->contract(*bloss, v);
//                    P’ ← find_augmenting_path( G’, M’ )
                    list<int> p_prim = g_prim->find_aug_path();
//                    P ← lift P’ to G
                    return lift_p(p_prim, v, *bloss);
                }
            }
            edge_marked[edge_hash(v,w, V)] = true;
            w = find_other_vertex_from_unmarked_edge_with(v, edge_marked);
        }
        v_marked[v] = true;
        v = find_unmarked_w_even_dist(nodes, v_marked);
    }
    list<int> nth;
    return nth;

}
list<int> Graph::lift_p(list<int> p_prim, int v, deque<int> bloss) {
    list<int> path;
    for(auto it = p_prim.begin(); it!= p_prim.end(); ++it){
        if(*it==v){ // contracted blossom
            int next_v_in_path;
            if(++it != p_prim.end()){
                next_v_in_path = *it;
                it--;
            }else next_v_in_path = NIL;
            list<int> path_piece = path_in_blossom(bloss, v, next_v_in_path);
            // insert path piece to path
            path.insert(path.end(), path_piece.begin(), path_piece.end());
        }
        else{
            path.push_back(*it);
        }
    }
    return path;
}
list<int> Graph::path_in_blossom(deque<int> bloss, int v, int next_in_path ){ // v - contracted blossom in this v
    auto opt1 = bloss.begin(); // 2 options of iterating over blossom cycle
    auto opt2 = bloss.rbegin();
    list<int> path_in_blossom;
    // check which path has even nr of edges
    if(next_in_path != NIL){ // case v is not last element of aug path
        int iter=0;
        int prev = v;
        while(opt1 != bloss.end()){
            int vert = get_other(*opt1, prev, V);
            path_in_blossom.push_back(vert);
            if(iter%2==0){
                if(adj[vert].find(next_in_path) != adj[vert].end()){ // vert connects to v from original path
                    return path_in_blossom;
                }
            }
            iter++;
            prev = vert;
        }
        // opt1 unsuccessful
        iter = 0;
        prev = v;
        while(opt2 != bloss.rend()){
            int vert = get_other(*opt2, prev, V);
            path_in_blossom.push_back(vert);
            if(iter%2==0){
                if(adj[vert].find(next_in_path) != adj[vert].end()){ // vert connects to v from original path
                    return path_in_blossom;
                }
            }
            iter++;
            prev = vert;
        }
        list<int> l;
        return l; // cant find path in blossom
    }
    else{  // v is last in aug path
        list<int> l;
        return l;
    }
}
void Graph::contract(deque<int> edges, int v){
    unordered_set<int> affected_v;  // vs to be contracted
    // remove edges in blossom
    for(auto edge: edges){
        int u = get_vertices(edge, V).first;
        int w = get_vertices(edge, V).second;
        adj[u].erase(w);
        adj[w].erase(u);
        affected_v.insert(u);
        affected_v.insert(w);
    }
    affected_v.erase(v);
    for(auto u: affected_v){
        adj[v].insert(adj[u].begin(), adj[u].end());
        adj[u] = {};
    }
}
int Graph::find_other_vertex_from_unmarked_edge_with(int v, unordered_map<int, bool> edge_marked){
    for(auto neigh: adj[v]){
        if(!edge_marked[edge_hash(v, neigh, V)])
            return neigh;
    }
    return  NIL;
}
int Graph::find_unmarked_w_even_dist( Node** nodes, bool *marked){
    for(int v=1;v<=V;v++){
        if(marked[v]) continue;  // v is marked
        if(nodes[v]->parent== nullptr) continue;  // v not in forest
        // if distance( v, root( v ) ) even
        if(nodes[v]->dist_to_root()%2==0){
            return v;
        }
    }
    return NIL;
}

void Graph::blossom() {
    hopcroft();  // any matching
    // add reference from each vertex in pair to its partner
    for(auto i : employees){
        if(pairs[i]!=NIL){
            pairs[pairs[i]] = i;
        }
    }
    print_pairs();
    find_max_matching();
}
void Graph::print_pairs() {
    cout<<"curent pairs:";
    for(int i=0;i<=V;i++){
        cout<<i<<": "<<pairs[i]<<", ";
    }
}
void Graph::print_answer() {
    cout<<result<<"\n";
    for(auto i:employees){
        if(pairs[i]==NIL) continue;
        cout<<i-1<<" "<<pairs[i]-1<<"\n";
        pairs[pairs[i]] = NIL;  // do not display same connection twice
    }
}
void Graph::hopcroft() {
    memset(pairs, NIL, (V+1)*sizeof(int));
    while(bfs()) {
        for(auto u: employees)
            if (pairs[u]==NIL && dfs(u))
                result++;
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
    Graph g(nrOfResidents);
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