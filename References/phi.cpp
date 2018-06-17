#std_require vector
#require prime_decomposition

template<typename Integer>
Integer phi(const Integer &a);

#main

template<typename Integer>
Integer phi(const Integer &a) {
  vector<pair<Integer, size_t>> decomp = prime_decomposition<vector<pair<Integer, size_t>>>(a);

  Integer res = a;

  for(auto prime_power : decomp) {
    res /= prime_power.first;
    res *= prime_power.first - 1;
  }

  return res;
}
