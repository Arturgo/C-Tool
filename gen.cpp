#include <iostream>
#include <vector>
using namespace std;

template<typename Container>
typename Container::value_type sum(const Container& container);


template<typename Container>
void print(const Container& container, ostream& stream = cout);

template<typename Container, typename Filter>
Container filter(const Container& container, Filter fliter);

template<typename Container>
Container range(typename Container::value_type begin, typename Container::value_type end, typename Container::value_type iter);

template<typename Container>
Container range(typename Container::value_type begin, typename Container::value_type end);

template<typename Container>
Container range(typename Container::value_type end);

template<typename Container>
Container fibonacci(size_t size);

template<typename ContainerOut, typename ContainerIn>
ContainerOut key_set(const ContainerIn& container);

template<typename Container>
Container prime_decomposition(typename Container::value_type::first_type number);

template<typename ContainerOut, typename ContainerIn>
ContainerOut value_set(const ContainerIn& container);

template<typename Container>
typename Container::value_type max_value(const Container &container);


int main() {
  cout << max_value(key_set<vector<int>>(prime_decomposition<vector<pair<long long, int>>>(600851475143ll))) << endl;
  return 0;
}


template<typename Container>
typename Container::value_type sum(const Container& container) {
  typename Container::value_type sum = 0;
  for(auto elem : container) {
    sum += elem;
  }
  return sum;
}


template<typename Container>
void print(const Container& container, ostream& stream) {
  #ifndef print_hide_size
  stream << container.size() << endl;
  #endif
  
  for(typename Container::value_type elem : container) {
    stream << elem;
    #ifndef print_separator
    stream << " ";
    #endif
  }
  
  #ifndef print_no_endl
  cout << endl;
  #endif
}

template<typename Container, typename Filter>
Container filter(const Container& container, Filter filter) {
  Container filtered;
  for(typename Container::value_type elem : container) {
    if(filter(elem)) {
      inserter(filtered, filtered.end()) = elem;
    }
  }
  return filtered;
}

template<typename Container>
Container range(typename Container::value_type begin, typename Container::value_type end, typename Container::value_type iter) {
  Container range;

  for(typename Container::value_type elem = begin;elem < end;elem += iter) {
    inserter(range, range.end()) = elem;
  }
  
  return range;
}

template<typename Container>
Container range(typename Container::value_type begin, typename Container::value_type end) {
  Container range;

  for(typename Container::value_type elem = begin;elem < end;elem ++) {
    inserter(range, range.end()) = elem;
  }
  
  return range;
}

template<typename Container>
Container range(typename Container::value_type end) {
  typename Container::value_type zero = 0;
  return range<Container>(zero, end);
}

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

template<typename ContainerOut, typename ContainerIn>
ContainerOut key_set(const ContainerIn& container) {
  ContainerOut keys;
  for(typename ContainerIn::value_type p : container) {
    inserter(keys, keys.end()) = p.first;
  }
  return keys;
}

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

template<typename ContainerOut, typename ContainerIn>
ContainerOut value_set(const ContainerIn& container) {
  ContainerOut values;
  for(typename ContainerIn::value_type p : container) {
    inserter(values, values.end()) = p.second;
  }
  return values;
}

template<typename Container>
typename Container::value_type max_value(const Container &container) {
  typename Container::value_type maxi = *container.begin();
  for(auto elem : container) {
    if(elem > maxi) {
      maxi = elem;
    }
  }
  return maxi;
}
