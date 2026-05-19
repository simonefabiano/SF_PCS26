#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

class unidirected_edge {
private:
    int node_a, node_b;
public:
    unidirected_edge(int u, int v) {
        if (u < v) { node_a = u; node_b = v; }
        else { node_a = v; node_b = u; }
    }
    int from() const { return node_a; }
    int to() const { return node_b; }
    bool operator<(const unidirected_edge& other) const {
        if (node_a != other.node_a) return node_a < other.node_a;
        return node_b < other.node_b;
    }
    bool operator==(const unidirected_edge& other) const {
        return node_a == other.node_a && node_b == other.node_b;
    }
    friend std::ostream& operator<<(std::ostream& os, const unidirected_edge& edge) {
        os << "{" << edge.node_a << ", " << edge.node_b << "}";
        return os;
    }
};

class unidirected_graph {
private:
    std::map<int, std::set<int>> adj_map;
    std::vector<unidirected_edge> edges;
public:
    unidirected_graph() = default;
    unidirected_graph(const unidirected_graph& other) = default;

    void add_edge(int u, int v) {
        unidirected_edge new_edge(u, v);
        bool exists = false;
        for (const auto& e : edges) {
            if (e == new_edge) { exists = true; break; }
        }
        if (!exists) {
            edges.push_back(new_edge);
            adj_map[u].insert(v);
            adj_map[v].insert(u);
        }
    }

    std::set<int> neighbours(int node) const {
        if (adj_map.count(node)) return adj_map.at(node);
        return {};
    }

    std::set<int> all_nodes() const {
        std::set<int> nodes;
        for (auto const& [node, _] : adj_map) nodes.insert(node);
        return nodes;
    }

    std::vector<unidirected_edge> all_edges() const { return edges; }
    int edge_number(const unidirected_edge& edge) const {
        for (int i = 0; i < (int)edges.size(); ++i) {
            if (edges[i] == edge) return i;
        }
        return -1;
    }
    unidirected_edge edge_at(int index) const { return edges.at(index); }
};

class fifo {
private:
    std::queue<int> q;
public:
    fifo() = default;
    void put(int val) { q.push(val); }
    int get() {                       
        int val = q.front();
        q.pop();
        return val;
    }
    bool empty() const { return q.empty(); }
};

class lifo {
private:
    std::stack<int> s;
public:
    lifo() = default;
    void put(int val) { s.push(val); }
    int get() {                        
        int val = s.top();
        s.pop();
        return val;
    }
    bool empty() const { return s.empty(); }
};

// Funzione template iterativa per BFS e DFS che accetta l'adattatore come parametro
template <typename Container>
unidirected_graph graph_visit(const unidirected_graph& G, int start_node, Container container) {
    unidirected_graph tree;
    std::set<int> visited;

    container.put(start_node);
    visited.insert(start_node);

    // Per associare a ciascun nodo il rispettivo genitore
    std::map<int, int> parent;

    while (!container.empty()) {
        int current = container.get();

        // Se il nodo ha un genitore, questo mette l'arco corrispondente nell'albero
        if (parent.count(current)) {
            tree.add_edge(parent[current], current);
        }

        for (int neighbor : G.neighbours(current)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                parent[neighbor] = current;
                container.put(neighbor);
            }
        }
    }
    return tree;
}

// Helper ricorsivo per la DFS
void recursive_dfs_helper(const unidirected_graph& G, int current, std::set<int>& visited, unidirected_graph& tree) {
    visited.insert(current);
    for (int neighbor : G.neighbours(current)) {
        if (visited.find(neighbor) == visited.end()) {
            tree.add_edge(current, neighbor);
            recursive_dfs_helper(G, neighbor, visited, tree);
        }
    }
}

// Funzione principale DFS ricorsiva
unidirected_graph recursive_dfs(const unidirected_graph& G, int start_node) {
    unidirected_graph tree;
    std::set<int> visited;
    recursive_dfs_helper(G, start_node, visited, tree);
    return tree;
}

void dijkstra(const unidirected_graph& G, int start_node) {
    std::map<int, int> distances;
    for (int node : G.all_nodes()) {
        distances[node] = 1e9; // Metto un valore enorme iniziale
    }
    
    // Salvo sia distanza che nodo
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    distances[start_node] = 0;
    pq.push({0, start_node});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist > distances[u]) continue;

        for (int v : G.neighbours(u)) {
            int weight = 1;
            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push({distances[v], v});
            }
        }
    }

    std::cout << "Distanze minime partendo dal nodo sorgente " << start_node << ":\n";
    for (auto const& [node, dist] : distances) {
        std::cout << "  Nodo: " << node << " -> Distanza: " << dist << "\n";
    }
}

int main() {
    unidirected_graph G;
    G.add_edge(1, 2);
    G.add_edge(1, 3);
    G.add_edge(2, 4);
    G.add_edge(3, 4);
    G.add_edge(4, 5);

    std::cout << "--- TEST VISITA IN AMPIEZZA (BFS) ITERATIVA ---\n";
    fifo q;
    unidirected_graph bfsG = graph_visit(G, 1, q);
    for (const auto& e : bfsG.all_edges()) std::cout << e << " ";
    std::cout << "\n\n";

    std::cout << "--- TEST VISITA IN PROFONDITÀ (DFS) ITERATIVA ---\n";
    lifo s;
    unidirected_graph dfsG = graph_visit(G, 1, s);
    for (const auto& e : dfsG.all_edges()) std::cout << e << " ";
    std::cout << "\n\n";

    std::cout << "--- TEST VISITA IN PROFONDITÀ (DFS) RICORSIVA ---\n";
    unidirected_graph recDfsG = recursive_dfs(G, 1);
    for (const auto& e : recDfsG.all_edges()) std::cout << e << " ";
    std::cout << "\n\n";

    std::cout << "--- TEST ALGORITMO DI DIJKSTRA ---\n";
    dijkstra(G, 1);

    return 0;
}