template<typename Container>
Container prime_decomposition(typename Container::value_type::first_type number);

#main

template<typename Container>
Container prime_decomposition(typename Container::value_type::first_type number) {
  Container decomposition;
  
  typename Container::value_type::first_type divisor(2);
  while(divisor * divisor <= number) {
    typename Container::value_type::second_type count(0);
    while(number % divisor == 0) {
      number = number / divisor;
      count++;
    }

    if(count != 0) {
      inserter(decomposition, decomposition.end()) = make_pair(divisor, count);
    }
    divisor++;
  }

  if(number != 1) {
    typename Container::value_type::second_type count = 1;
    inserter(decomposition, decomposition.end()) = make_pair(number, count);
  }

  return decomposition;
}
