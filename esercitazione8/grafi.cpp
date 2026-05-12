#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

class unidirected_edge {
private:
    int node_a, node_b;

public:
    unidirected_edge(int u, int v) {
        if (u < v) {
            node_a = u;
            node_b = v;
        } else {
            node_a = v;
            node_b = u;
        }
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
        os << "(" << edge.node_a << " -- " << edge.node_b << ")";
        return os;
    }
};

class unidirected_graph {
private:
    std::map<int, std::set<int>> adjacency_list;
    std::vector<unidirected_edge> edges_list;

public:
    unidirected_graph() = default;
    
    unidirected_graph(const unidirected_graph& other) = default;

    void add_edge(int u, int v) {
        unidirected_edge new_edge(u, v);
        
        if (std::find(edges_list.begin(), edges_list.end(), new_edge) == edges_list.end()) {
            edges_list.push_back(new_edge);
            adjacency_list[u].insert(v);
            adjacency_list[v].insert(u);
        }
    }

    std::set<int> neighbours(int node) const {
        if (adjacency_list.count(node)) {
            return adjacency_list.at(node);
        }
        return {};
    }

    std::set<int> all_nodes() const {
        std::set<int> nodes;
        for (auto const& [node, neighbors] : adjacency_list) {
            nodes.insert(node);
        }
        return nodes;
    }

    std::vector<unidirected_edge> all_edges() const {
        return edges_list;
    }

    int edge_number(const unidirected_edge& edge) const {
        for (size_t i = 0; i < edges_list.size(); ++i) {
            if (edges_list[i] == edge) return static_cast<int>(i);
        }
        return -1;
    }

    unidirected_edge edge_at(int index) const {
        return edges_list.at(index);
    }

    unidirected_graph operator-(const unidirected_graph& other) const {
        unidirected_graph result;
        auto other_edges = other.all_edges();

        for (const auto& e : this->edges_list) {
            if (std::find(other_edges.begin(), other_edges.end(), e) == other_edges.end()) {
                result.add_edge(e.from(), e.to());
            }
        }
        return result;
    }
};

int main() {
    unidirected_graph g1;
    g1.add_edge(1, 2);
    g1.add_edge(2, 3);
    g1.add_edge(3, 1);

    std::cout << "Nodi in G1: ";
    for(int n : g1.all_nodes()) std::cout << n << " ";
    std::cout << "\nArchi in G1:\n";
    for(const auto& e : g1.all_edges()) std::cout << e << " indice: " << g1.edge_number(e) << "\n";

    unidirected_graph g2;
    g2.add_edge(1, 2);

    unidirected_graph diff = g1 - g2;
    std::cout << "\nArchi in (G1 - G2):\n";
    for(const auto& e : diff.all_edges()) std::cout << e << "\n";

    return 0;
}