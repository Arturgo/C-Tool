#std_require functional set
#require convert_container

template<typename ContainerA, typename ContainerB, typename Operation>
ContainerA cartesian_sum(const ContainerA &a, const ContainerB &b, Operation op);

#main

template<typename ContainerA, typename ContainerB, typename Operation>
ContainerA cartesian_sum(const ContainerA &a, const ContainerB &b, Operation op) {
  set<typename ContainerA::value_type> res;

  for(auto u : a) {
    for(auto v : b) {
      res.insert(op(u, v));
    }
  }
  
  return convert_container<ContainerA>(res);
}
