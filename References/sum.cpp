template<typename Container>
typename Container::value_type sum(const Container& container);

#main

template<typename Container>
typename Container::value_type sum(const Container& container) {
  typename Container::value_type sum = 0;
  for(auto elem : container) {
    sum += elem;
  }
  return sum;
}

