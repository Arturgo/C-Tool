template<typename Type>
Type gcd(const Type &a, const Type &b);

#main

template<typename Type>
Type gcd(const Type& a, const Type& b) {
  if(b == 0)
    return a;
  return gcd(b, a % b);
}
