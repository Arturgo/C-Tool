#include <iostream>
using namespace std;

template<typename Integer>
Integer safe_mod(Integer a, Integer mod);


template<class Integer>
Integer modular_inverse(Integer a, Integer mod);


int main() {
  long long a, mod;
  cin >> a >> mod;
  cout << modular_inverse(a, mod) << endl;
  return 0;
}


template<typename Integer>
Integer safe_mod(Integer a, Integer mod) {
  return ((a % mod) + mod) % mod;
}

template<class Integer>
Integer modular_inverse(Integer a, Integer mod) {
  pair<Integer, Integer> prev = make_pair(0, 1);
  pair<Integer, Integer> cur = make_pair(1, 0);

  while(safe_mod(cur.first * a, mod) != 1) {
    Integer mult = (prev.first * a + prev.second * mod) / (cur.first * a + cur.second * mod);
    pair<Integer, Integer> suiv = make_pair(prev.first - mult * cur.first, prev.second - mult * cur.second);
    prev = cur;
    cur = suiv;
  }

  return safe_mod(cur.first, mod);
}
