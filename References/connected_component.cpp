template<typename Graph>
vector<size_t> connected_component(const Graph &graph, size_t node_id);

template<typename Graph>
vector<vector<size_t>> connected_components(const Graph &graph);

#main

template<typename Graph>
vector<size_t> connected_component(const Graph &graph, size_t node_id) {
  vector<bool> viewed(graph.nodes.size(), false);
  
  vector<size_t> component, stacked;
  stacked.push_back(node_id);
  viewed[node_id] = true;

  while(!stacked.empty()) {
    size_t stacked_id = stacked.back();
    stacked.pop_back();

    component.push_back(stacked_id);
    
    for(size_t child : graph.childs[stacked_id]) {
      if(!viewed[child]) {
	viewed[child] = true;
	stacked.push_back(child);
      }
    }

    for(size_t parent : graph.childs[stacked_id]) {
      if(!viewed[parent]) {
	viewed[parent] = true;
	stacked.push_back(parent);
      }
    }
  }
  
  return component;
}

template<typename Graph>
vector<vector<size_t>> connected_components(const Graph &graph) {
  vector<bool> viewed(graph.nodes.size(), false);
  vector<vector<size_t>> components;
  for(size_t id = 0;id < graph.nodes.size();id++) {
    if(!viewed[id]) {
      components.push_back(connected_component(graph, id));
      for(size_t node_id : components.back())
	viewed[node_id] = true;
    }
  }
  return components;
}
