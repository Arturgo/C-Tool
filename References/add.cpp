template<typename Param>
class add {
private:
  Param value;
public:
  add(Param _value);
  Param operator ()(const Param& a);
};

#main

template<typename Param>
add<Param>::add(Param _value) {
  value = _value;
}

template<typename Param>
Param add<Param>::operator ()(const Param &a) {
  return a + value;
}
