#require reversed

template<typename Container>
Container digits(typename Container::value_type number, typename Container::value_type base = 10);

#main

template<typename Container>
Container digits(typename Container::value_type number, typename Container::value_type base) {
  Container res;
  while(number != 0) {
    inserter(res, res.end()) = number % base;
    number /= base;
  }

  return reversed(res);
}
