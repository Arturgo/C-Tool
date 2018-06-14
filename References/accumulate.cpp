template<typename Container, typename Operation>
typename Container::value_type accumulate(const Container& container, typename Container::value_type init, Operation op);

#main

template<typename Container, typename Operation>
typename Container::value_type accumulate(const Container& container, typename Container::value_type init, Operation op) {
  for(auto elem : container) {
    init = op(init, elem);
  }
  return init;
}
