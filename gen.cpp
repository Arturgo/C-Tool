#include <iostream>
#include <vector>
using namespace std;

template<typename Table>
Table prime_table(size_t size);

template<typename Container, typename Table>
Container table_to_container(const Table &table);


int main() {
  vector<bool> table = prime_table<vector<bool>>(4000000);
  vector<int> primes = table_to_container<vector<int>>(table);
  cout << primes[10000]  << endl;
  return 0;
}


template<typename Table>
Table prime_table(size_t size) {
  Table table(size, true);
  table[0] = table[1] = false;
  for(size_t div = 2;div * div <= size;div++) {
    if(table[div]) {
      for(size_t mult = 2 * div;mult < size;mult += div) {
	table[mult] = false;
      }
    }
  }
  return table;
}

template<typename Container, typename Table>
Container table_to_container(const Table &table) {
  Container res;
  for(size_t value = 0;value < table.size();value++) {
    for(int count = 0;count < table[value];count++) {
      inserter(res, res.end()) = value;
    }
  }
  return res;
}
