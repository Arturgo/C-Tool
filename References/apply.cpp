template< typename ContainerOut, typename ContainerIn, typename Operation>
ContainerOut apply(const ContainerIn& container, Operation op);

#main

template< typename ContainerOut, typename ContainerIn, typename Operation>
ContainerOut apply(const ContainerIn& container, Operation op) {
  ContainerOut res;
  for(auto elem : container) {
    inserter(res, res.end()) = op(elem);
  }
  return res;
}
