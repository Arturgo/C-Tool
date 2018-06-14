template<typename ContainerOut, typename ContainerIn>
ContainerOut value_set(const ContainerIn& container);

#main

template<typename ContainerOut, typename ContainerIn>
ContainerOut value_set(const ContainerIn& container) {
  ContainerOut values;
  for(typename ContainerIn::value_type p : container) {
    inserter(values, values.end()) = p.second;
  }
  return values;
}
