template<typename Container>
Container range(typename Container::value_type begin, typename Container::value_type end, typename Container::value_type iter);

template<typename Container>
Container range(typename Container::value_type begin, typename Container::value_type end);

template<typename Container>
Container range(typename Container::value_type end);

#main

template<typename Container>
Container range(typename Container::value_type begin, typename Container::value_type end, typename Container::value_type iter) {
  Container range;

  for(typename Container::value_type elem = begin;elem < end;elem += iter) {
    inserter(range, range.end()) = elem;
  }
  
  return range;
}

template<typename Container>
Container range(typename Container::value_type begin, typename Container::value_type end) {
  Container range;

  for(typename Container::value_type elem = begin;elem < end;elem ++) {
    inserter(range, range.end()) = elem;
  }
  
  return range;
}

template<typename Container>
Container range(typename Container::value_type end) {
  typename Container::value_type zero = 0;
  return range<Container>(zero, end);
}
