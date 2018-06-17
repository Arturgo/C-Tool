template<typename Integer>
int sign(Integer a);

#main

template<typename Integer>
int sign(Integer a) {
  if(a < 0)
    return -1;
  if(a > 0)
    return 1;
  return 0;
}
