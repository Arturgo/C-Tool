template<typename Graph, typename Table>
Graph table_to_graph(const Table& table);

#main

template<typename Graph, typename Table>
Graph table_to_graph(const Table& table) {
  Graph graph;
  for(size_t begin = 0;begin < table.size();begin++) {
    graph.add_node(begin);
  }
  for(size_t begin = 0;begin < table.size();begin++) {
    graph.add_edge_id(begin, table[begin]);
  }
  return graph;  
}
