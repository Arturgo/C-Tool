template<typename Container>
typename Container::value_type max_value(const Container &container);

#main

template<typename Container>
typename Container::value_type max_value(const Container &container) {
  typename Container::value_type maxi = *container.begin();
  for(auto elem : container) {
    if(elem > maxi) {
      maxi = elem;
    }
  }
  return maxi;
}
