template<typename Container, typename Filter>
Container filter(const Container& container, Filter fliter);

#main

template<typename Container, typename Filter>
Container filter(const Container& container, Filter filter) {
  Container filtered;
  for(typename Container::value_type elem : container) {
    if(filter(elem)) {
      inserter(filtered, filtered.end()) = elem;
    }
  }
  return filtered;
}
