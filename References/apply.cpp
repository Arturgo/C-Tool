template<typename Container, typename Operation>
Container apply(const Container& container, Operation op);

#main

template<typename Container, typename Operation>
Container apply(const Container& container, Operation op) {
  Container res;
  for(auto elem : container) {
    inserter(res, res.end()) = op(elem);
  }
  return res;
}
