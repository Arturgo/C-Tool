#require directed_graph connected_component table_to_graph

template<typename Sequence>
int signature(const Sequence &seq);

#main

template<typename Sequence>
int signature(const Sequence &seq) {
  auto graph = table_to_graph<directed_graph<size_t>>(seq);
  auto components = connected_components(graph);

  size_t parity = seq.size() - components.size();
  if(parity % 2 == 0)
    return 1;
  return -1;
}
