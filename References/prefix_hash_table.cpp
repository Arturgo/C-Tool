#std_require functional
#require safe_mod

template<typename Container, typename HashType = long long>
class prefix_hash_table {
private:
  HashType mod, mult;
  vector<HashType> table, powers;
public:
  prefix_hash_table(const Container &a, HashType _mod = 1000000007, HashType _mult = 31);
  prefix_hash_table();
  HashType hash_between(size_t begin, size_t end);
};

#main

template<typename Container, typename HashType>
prefix_hash_table<Container, HashType>::prefix_hash_table(const Container &a, HashType _mod, HashType _mult) {
  mod = _mod;
  mult = _mult;
  
  HashType prefix_hash = 0, power = 1;
  table.push_back(prefix_hash);
  powers.push_back(power);

  for(auto elem : a) {
    prefix_hash = prefix_hash + power * safe_mod(hash<typename Container::value_type>()(elem), mod);
    prefix_hash %= mod;

    table.push_back(prefix_hash);
    
    power = power * mult;
    power %= mod;
    powers.push_back(power);
  }
}

template<typename Container, typename HashType>
prefix_hash_table<Container, HashType>::prefix_hash_table() {}

template<typename Container, typename HashType>
HashType prefix_hash_table<Container, HashType>::hash_between(size_t begin, size_t end) {
  return safe_mod(safe_mod(table[end] - table[begin], mod) * powers[powers.size() - 1 - begin], mod);
}
