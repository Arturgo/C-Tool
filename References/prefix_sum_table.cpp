#std_require vector

template<typename Container, typename SumType = long long>
class prefix_sum_table {
private:
  vector<SumType> table;
public:
  prefix_sum_table(const Container &a);
  prefix_sum_table();
  SumType sum_between(size_t begin, size_t end);
};

#main

template<typename Container, typename SumType>
prefix_sum_table<Container, SumType>::prefix_sum_table(const Container &a) {
  SumType prefix_sum = 0;
  inserter(table, table.end()) = prefix_sum;

  for(auto elem : a) {
    prefix_sum = prefix_sum + elem;
    inserter(table, table.end()) = prefix_sum;
  }
}

template<typename Container, typename SumType>
prefix_sum_table<Container, SumType>::prefix_sum_table() {}

template<typename Container, typename SumType>
SumType prefix_sum_table<Container, SumType>::sum_between(size_t begin, size_t end) {
  return table[end] - table[begin];
}
