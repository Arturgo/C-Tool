#require gcd

template<typename Type>
Type lcm(const Type& a, const Type& b);

#main

template<typename Type>
Type lcm(const Type& a, const Type& b) {
  return a / gcd(a, b) * b;
}
