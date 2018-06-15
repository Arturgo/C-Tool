#require directed_graph

template<typename Node, typename Map = map<Node, size_t>>
class undirected_graph : public directed_graph<Node, Map> {
public:
  void add_edge(const Node &begin, const Node &end);
  void add_edge_id(size_t begin, size_t end);
};

#main

template<typename Node, typename Map>
void undirected_graph<Node, Map>::add_edge(const Node &begin, const Node &end) {
  add_edge_id(directed_graph<Node, Map>::r_nodes[begin], directed_graph<Node, Map>::r_nodes[end]);
}

template<typename Node, typename Map>
void undirected_graph<Node, Map>::add_edge_id(size_t begin, size_t end) {
  directed_graph<Node, Map>::childs[begin].push_back(end);
  directed_graph<Node, Map>::childs[end].push_back(begin);
  directed_graph<Node, Map>::parents[begin].push_back(end);
  directed_graph<Node, Map>::parents[end].push_back(begin);
}
