template<typename Map, typename Table>
Map table_to_map(const Table &table);

#main

template<typename Map, typename Table>
Map table_to_map(const Table &table) {
  Map res;

  for(size_t key = 0;key < table.size();key++) {
    inserter(res, res.end()) = make_pair(key, table[key]);
  }

  return res;
}
