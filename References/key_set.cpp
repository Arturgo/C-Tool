template<typename ContainerOut, typename ContainerIn>
ContainerOut key_set(const ContainerIn& container);

#main

template<typename ContainerOut, typename ContainerIn>
ContainerOut key_set(const ContainerIn& container) {
  ContainerOut keys;
  for(typename ContainerIn::value_type p : container) {
    inserter(keys, keys.end()) = p.first;
  }
  return keys;
}
