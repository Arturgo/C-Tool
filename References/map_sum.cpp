template<typename MapOut, typename Map, typename Operation>
MapOut map_sum(const Map& a, const Map& b, Operation op, typename Map::value_type::second_type def);

#main

template<typename MapOut, typename Map, typename Operation>
MapOut map_sum(const Map& a, const Map &b, Operation op, typename Map::value_type::second_type def) {
  MapOut res;

  typename Map::const_iterator b_it = b.begin();
  for(auto pair : a) {
    while(b_it != b.end() && b_it->first < pair.first) {
      inserter(res, res.end()) = make_pair(b_it->first, op(def, b_it->second));
      b_it++;
    }

    if(b_it == b.end() || b_it->first != pair.first) {
      inserter(res, res.end()) = make_pair(pair.first, op(pair.second, def));
    }
    else {
      inserter(res, res.end()) = make_pair(pair.first, op(pair.second, b_it->second));
      b_it++;
    }
  }

  while(b_it != b.end()) {
    inserter(res, res.end()) = make_pair(b_it->first, op(def, b_it->second));
    b_it++;
  }
  
  return res;
}
