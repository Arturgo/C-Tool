#std_require vector algorithm
#require range

template<typename ContainerOut>
ContainerOut permutation_set(const typename ContainerOut::value_type& container);

#main

template<typename ContainerOut>
ContainerOut permutation_set(const typename ContainerOut::value_type& container) {
  ContainerOut permutations;
  vector<size_t> p = range<vector<size_t>>(container.size());

  do {
    typename ContainerOut::value_type permuted;
    for(size_t index : p) {
      inserter(permuted, permuted.end()) = container[index];
    }
    inserter(permutations, permutations.end()) = permuted;
  } while(next_permutation(p.begin(), p.end()));

  return permutations;
}
