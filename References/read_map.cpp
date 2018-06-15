#std_require iostream

template<typename Map>
Map read_map(istream& stream = cin);

template<typename Map>
Map read_map_of_size(size_t size, istream& stream = cin);

#main

template<typename Map>
Map read_map(istream& stream) {
  size_t size;
  cin >> size;
  return read_map_of_size<Map>(size, stream);
}

template<typename Map>
Map read_map_of_size(size_t size, istream& stream) {
  Map res;
  for(size_t i = 0;i < size;i++) {
    typename Map::value_type::first_type key;
    typename Map::value_type::second_type value;
    stream >> key >> value;
    inserter(res, res.end()) = make_pair(key, value);
  }
  return res;
}
