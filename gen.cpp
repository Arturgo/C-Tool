#include <algorithm>
#include <functional>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

template<typename ContainerOut, typename ContainerIn>
ContainerOut convert_container(const ContainerIn& container);


template<typename ContainerA, typename ContainerB, typename Operation>
ContainerA cartesian_sum(const ContainerA &a, const ContainerB &b, Operation op);

template<typename Container>
Container range(typename Container::value_type begin, typename Container::value_type end, typename Container::value_type iter);

template<typename Container>
Container range(typename Container::value_type begin, typename Container::value_type end);

template<typename Container>
Container range(typename Container::value_type end);

template<typename Container>
typename Container::value_type max_value(const Container &container);

template<typename Container, typename Filter>
Container filter(const Container& container, Filter fliter);


template<typename Container>
Container reversed(Container container);


template<typename Container>
Container digits(typename Container::value_type number, typename Container::value_type base = 10);


template<typename Container>
struct is_palindromic_sequence {
  bool operator() (const Container &a);
};

template<typename Type>
struct is_palindromic_number {
  bool operator() (const Type &a);
};


int main() {
  vector<int> three_digits = range<vector<int>>(100, 1000);
  vector<int> product = cartesian_sum(three_digits, three_digits, multiplies<int>());
  vector<int> palindromes = filter(product, is_palindromic_number<int>());
  cout << max_value(palindromes) << endl;
  return 0;
}


template<typename ContainerOut, typename ContainerIn>
ContainerOut convert_container(const ContainerIn& container) {
  ContainerOut converted;
  for(auto elem : container) {
    inserter(converted, converted.end()) = elem;
  }
  return converted;
}

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
typename Container::value_type max_value(const Container &container) {
  typename Container::value_type maxi = *container.begin();
  for(auto elem : container) {
    if(elem > maxi) {
      maxi = elem;
    }
  }
  return maxi;
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
Container reversed(Container container) {
  reverse(container.begin(), container.end());
  return container;
}

template<typename Container>
Container digits(typename Container::value_type number, typename Container::value_type base) {
  Container res;
  while(number != 0) {
    inserter(res, res.end()) = number % base;
    number /= base;
  }

  return reversed(res);
}

template<typename Container>
bool is_palindromic_sequence<Container>::operator() (const Container &a) {
  return a == reversed(a);
}

template<typename Type>
bool is_palindromic_number<Type>::operator() (const Type &a) {
  return is_palindromic_sequence<vector<Type>>()(digits<vector<Type>>(a));
}
