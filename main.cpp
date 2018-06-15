#std_require vector iostream cstdio
#require fast_io undirected_graph

int main() {
  fast_io();
  int nbNodes;
  cin >> nbNodes;

  undirected_graph<int> graph;

  for(int iNode = 0;iNode < nbNodes;iNode++) {
    graph.add_node(iNode);
  }

  for(int iEdge = 0;iEdge < nbNodes - 1;iEdge++) {
    int deb, fin;
    cin >> deb >> fin;
    graph.add_edge_id(deb - 1, fin - 1);
  }

  vector<int> stars, leaves;
  for(int iNode = 0;iNode < nbNodes;iNode++) {
    if(graph.childs[iNode].size() > 2) {
      stars.push_back(iNode);
    }
    if(graph.childs[iNode].size() == 1) {
      leaves.push_back(iNode);
    }
  }

  if(stars.size() > 1) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
    if(stars.empty())
      stars.push_back(0);
    vector<pair<int, int>> paths;
    for(int leave : leaves) {
      if(leave != stars[0])
	paths.push_back({leave, stars[0]});
    }
    cout << paths.size() << endl;
    for(pair<int, int> path : paths) {
      cout << path.first + 1 << " " << path.second + 1 << endl;
    }
  }
  return 0;
}
