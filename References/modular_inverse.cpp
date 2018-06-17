#require safe_mod

template<class Integer>
Integer modular_inverse(Integer a, Integer mod);

#main

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
