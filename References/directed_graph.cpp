#std_require map

template<typename Node, typename Map = map<Node, size_t> >
class directed_graph {
public:
  typedef Node node_type;
  
  Map r_nodes;
  vector<Node> nodes;
  vector<vector<size_t>> childs, parents;
  
  directed_graph();
  void add_node(const Node& node);
  void add_edge(const Node& begin, const Node& end);
  void add_edge_id(size_t begin, size_t end);
};

#main

template<typename Node, typename Map>
directed_graph<Node, Map>::directed_graph() {
}

template<typename Node, typename Map>
void directed_graph<Node, Map>::add_node(const Node& node) {
  r_nodes[node] = nodes.size();
  nodes.push_back(node);
  childs.push_back({});
  parents.push_back({});
}

template<typename Node, typename Map>
void directed_graph<Node, Map>::add_edge(const Node& begin, const Node& end) {
  add_edge_id(r_nodes[begin], r_nodes[end]);
}

template<typename Node, typename Map>
void directed_graph<Node, Map>::add_edge_id(size_t begin, size_t end) {
  childs[begin].push_back(end);
  parents[end].push_back(begin);
}
