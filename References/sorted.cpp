#std_require algorithm

template<typename Container>
Container sorted(const Container &a);

#main

template<typename Container>
Container sorted(const Container &a) {
  Container res = a;
  sort(res.begin(), res.end());
  return res;
}
