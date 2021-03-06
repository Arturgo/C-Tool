template<typename ContainerOut, typename ContainerIn>
ContainerOut convert_container(const ContainerIn& container);

#main

template<typename ContainerOut, typename ContainerIn>
ContainerOut convert_container(const ContainerIn& container) {
  ContainerOut converted;
  for(auto elem : container) {
    inserter(converted, converted.end()) = elem;
  }
  return converted;
}
