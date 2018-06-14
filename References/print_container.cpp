#std_require iostream

template<typename Container>
void print_container(const Container& container, ostream& stream = cout);

#main

template<typename Container>
void print_container(const Container& container, ostream& stream) {
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
  stream << endl;
  #endif
}
