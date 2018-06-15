#std_require queue functional list

template<typename Graph>
vector<int> distances_from_bfs(const Graph &graph, vector<size_t> node_ids);

template<typename Graph>
vector<int> distances_from_bfs(const Graph &graph, size_t node_id);

const int NOT_REACHABLE = -2000 * 1000 * 1000;

#main

template<typename Graph>
vector<int> distances_from_bfs(const Graph &graph, vector<size_t> node_ids) {
  vector<int> dists(graph.nodes.size(), NOT_REACHABLE);

  list<size_t> queued;
  for(auto node : node_ids) {
    queued.push_back(node);
    dists[node] = 0;
  }

  while(!queued.empty()) {
    size_t node = queued.front();
    queued.pop_front();

    for(size_t child : graph.childs[node]) {
      if(dists[child] == NOT_REACHABLE) {
	dists[child] = dists[node] + 1;
	queued.push_back(child);
      }
    }
  }

  return dists;
}

template<typename Graph>
vector<int> distances_from_bfs(const Graph &graph, size_t node_id) {
  return distances_from_bfs(graph, vector<size_t>(1, node_id));
}
