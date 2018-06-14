template<typename Container>
Container fibonacci(size_t size);

#main

template<typename Container>
Container fibonacci(size_t size) {
  Container sequence;
  if(size >= 1)
    sequence.push_back(0);
  if(size >= 2)
    sequence.push_back(1);
  
  typename Container::value_type a = 0, b = 1;
  while(sequence.size() < size) {
    inserter(sequence, sequence.end()) = a + b;
    typename Container::value_type c = a + b;
    a = b;
    b = c;
  }
  
  return sequence;
}
