#std_require iostream

template<typename Container>
Container read_container(istream& stream = cin);

template<typename Container>
Container read_container_of_size(size_t size, istream& stream = cin);

#main

template<typename Container>
Container read_container(istream& stream) {
  size_t size;
  cin >> size;
  return read_container_of_size<Container>(size, stream);
}

template<typename Container>
Container read_container_of_size(size_t size, istream& stream) {
  Container res;
  for(size_t i = 0;i < size;i++) {
    typename Container::value_type elem;
    stream >> elem;
    inserter(res, res.end()) = elem;
  }
  return res;
}
