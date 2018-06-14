#std_require vector
#require digits reversed

template<typename Container>
struct is_palindromic_sequence {
  bool operator() (const Container &a);
};

template<typename Type>
struct is_palindromic_number {
  bool operator() (const Type &a);
};

#main

template<typename Container>
bool is_palindromic_sequence<Container>::operator() (const Container &a) {
  return a == reversed(a);
}

template<typename Type>
bool is_palindromic_number<Type>::operator() (const Type &a) {
  return is_palindromic_sequence<vector<Type>>()(digits<vector<Type>>(a));
}
