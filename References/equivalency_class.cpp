#std_require algorithm
#require convert_container

template<typename Map>
vector<vector<typename Map::value_type>> equivalency_classes(const Map& container);

#main

template<typename Map>
vector<vector<typename Map::value_type>> equivalency_classes(const Map& container) {
  vector<vector<typename Map::value_type>> res;

  for(auto p : pairs) {
    if(res.empty() || p.second != res.back().back().second) {
      res.push_back(vector<typename Map::value_type>());
    }
    res.back().push_back(p);
  }

  return res;
}
