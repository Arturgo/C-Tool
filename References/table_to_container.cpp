template<typename Container, typename Table>
Container table_to_container(const Table &table);

#main

template<typename Container, typename Table>
Container table_to_container(const Table &table) {
  Container res;
  for(size_t value = 0;value < table.size();value++) {
    for(int count = 0;count < table[value];count++) {
      inserter(res, res.end()) = value;
    }
  }
  return res;
}
